#pragma once

#include <string>
#include <boost/>

#include "Constant.h"

namespace usm
{
    class Writer
    {
    public:
        Writer(size_t size = 65536)
        {
            shared_memory_object::remove(ipc_id_);
            managed_shared_memory segment(create_only, ipc_id_, size);

        }

        ~Writer()
        {
            shared_memory_object::remove(ipc_id_);
        }

        template <typename T>
        void write(const std::string& name, T data);

        void clear(const std::string& name);

    };
}
