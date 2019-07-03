#pragma once

#include <string>
#include <windows.h>

namespace tsm
{
    template <typename T>
    class Writer
    {
    public:

        Writer(const std::string& name, size_t size = 512):
            sizeInBytes_(static_cast<DWORD>(size * sizeof(T)))
        {
            hMapFile_ = CreateFileMapping(INVALID_HANDLE_VALUE, nullptr, PAGE_READWRITE, 0, sizeInBytes_, name.c_str());
            if (hMapFile_ == nullptr)
                throw std::runtime_error("cannot create file mapping object");

            pBuf_ = MapViewOfFile(hMapFile_, FILE_MAP_ALL_ACCESS, 0, 0, sizeInBytes_);

            if (pBuf_ == nullptr)
            {
                CloseHandle(hMapFile_);
                throw std::runtime_error("cannot map view of file");
            }
        }

        ~Writer()
        {
            UnmapViewOfFile(pBuf_);
            CloseHandle(hMapFile_);
        }

        void write(const T* data)
        {
            memcpy(pBuf_, data, sizeInBytes_);
        }

    private:
        const DWORD sizeInBytes_;
        HANDLE hMapFile_;
        LPVOID pBuf_;
    };
}
