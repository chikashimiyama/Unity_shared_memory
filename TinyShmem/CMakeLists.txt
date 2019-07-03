cmake_minimum_required (VERSION 3.8)

project (TinyShmem)
add_library(TinyShmem INTERFACE)

target_include_directories(TinyShmem INTERFACE inc)
target_compile_features(TinyShmem INTERFACE cxx_std_14)

