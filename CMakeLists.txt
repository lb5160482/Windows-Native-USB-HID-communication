cmake_minimum_required(VERSION 2.8.12)

set(PROJECT_NAME NativeWinUSBHIDSample)
project(${PROJECT_NAME})

add_definitions("-D_TIMESPEC_DEFINED")

include_directories(
	./include
)

add_executable(main src/main.cpp src/UsbDevice.cpp)
target_link_libraries(main
)