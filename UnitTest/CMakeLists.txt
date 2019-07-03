cmake_minimum_required (VERSION 3.10)

project (TinyShmemTestHost)

set(gtest_force_shared_crt TRUE)

add_subdirectory(googletest)

add_executable(TinyShmemTestHost
        src/SharedMemoryTestCase.cpp)

target_compile_features(TinyShmemTestHost PRIVATE cxx_std_14)
target_link_libraries(TinyShmemTestHost PRIVATE TinyShmem gtest gmock gtest_main )
