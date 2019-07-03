#pragma once

#include <string>
#include <windows.h>

namespace tsm
{
    template <typename T>
    class Reader
    {
    public:
        Reader::Reader(const std::string& name, size_t size)
        {
            hMapFile_ = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, name.c_str());
            if (hMapFile_ == nullptr)
                throw std::runtime_error("cannot open file mapping object");

            pBuf_ = MapViewOfFile(hMapFile_, FILE_MAP_ALL_ACCESS, 0, 0, size);
            if (pBuf_ == nullptr)
            {
                CloseHandle(hMapFile_);
                throw std::runtime_error("cannot map view");
            }
        }

        const T* get()
        {
            return reinterpret_cast<T*>(pBuf_);
        }


        Reader::~Reader()
        {
            UnmapViewOfFile(pBuf_);
            CloseHandle(hMapFile_);
        }

    private:
        HANDLE hMapFile_;
        LPVOID pBuf_;
    };
}