set(CMAKE_C_FLAGS " -g -O0")
add_executable(rfcomm_client rfcomm_client.c)
TARGET_LINK_LIBRARIES(rfcomm_client bluetooth)