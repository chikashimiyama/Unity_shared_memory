#pragma once

#include <string>
#include <array>

namespace usm
{
    template <int MaxSize>
    class Message
    {
    public:
        Message(const std::string& address);
        void addInt(int value);
        void addFloat(float value);
        void addString(const std::string str);

        std::array<char, MaxSize> get();

    private:
        const std::string address_;
        const std::vector<char> typetag_;

    }

   
}