#pragma once

#define EXPORT_API __declspec(dllexport) 

extern "C" {
    int EXPORT_API getFive();
}