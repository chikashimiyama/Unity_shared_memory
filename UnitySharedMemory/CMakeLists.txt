cmake_minimum_required (VERSION 3.8)

project (UnitySharedMemory)

				src/UnitySharedMemory.cpp)

target_include_directories(UnitySharedMemory PUBLIC inc)
target_include_directories(UnitySharedMemory PUBLIC ../boost boost)

target_compile_features(UnitySharedMemory PUBLIC cxx_std_14)

add_custom_command(TARGET UnitySharedMemory POST_BUILD       
    COMMAND ${CMAKE_COMMAND} -E copy_if_different 
        "${CMAKE_CURRENT_BINARY_DIR}/UnitySharedMemory.dll"
		"${CMAKE_SOURCE_DIR}/lib/UnitySharedMemory.dll")
