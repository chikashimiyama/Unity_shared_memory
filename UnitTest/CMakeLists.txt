cmake_minimum_required (VERSION 3.8)

project (UnitySharedMemoryTestHost)

add_executable(UnitySharedMemoryTestHost  
				src/char_integer.cpp)


target_compile_features(UnitySharedMemoryTestHost PRIVATE cxx_std_14)
target_link_libraries(UnitySharedMemoryTestHost PRIVATE UnitySharedMemory)
