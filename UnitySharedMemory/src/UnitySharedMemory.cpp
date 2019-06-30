#include "UnitySharedMemory.h"
#include "Writer.h"

extern "C"
{
    int EXPORT_API getFive()
    {
        return 5;
    }

}