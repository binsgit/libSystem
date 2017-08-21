cmake_minimum_required(VERSION 2.8)
project(libSystem)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES
    Net/Sockets/AddressFamily.hpp
    Net/SocketAddress.cpp
    Net/SocketAddress.hpp
        Net/Net.cpp
        Net/Net.hpp System.cpp System.hpp Exception/Exception.cpp Exception/Exception.hpp Exception/SystemException.cpp Exception/SystemException.hpp Exception/OutOfMemoryException.cpp Exception/OutOfMemoryException.hpp Net/IPAddress.cpp Net/IPAddress.hpp Exception/SocketException.cpp Exception/SocketException.hpp Exception/PosixException.cpp Exception/PosixException.hpp Exception/ArgumentNullException.cpp Exception/ArgumentNullException.hpp Exception/ArgumentException.cpp Exception/ArgumentException.hpp Net/IPEndPoint.cpp Net/IPEndPoint.hpp Net/EndPoint.cpp Net/EndPoint.hpp Net/Sockets/TcpListener.cpp Net/Sockets/TcpListener.hpp Net/Sockets/TcpClient.cpp Net/Sockets/TcpClient.hpp Net/Socket.cpp Net/Socket.hpp Exception/inc.hpp Net/Sockets/inc.hpp Net/inc.hpp libSystem.hpp)

add_library(Reimu_System SHARED ${SOURCE_FILES})
add_library(Reimu_System_Static STATIC ${SOURCE_FILES})
set_target_properties(Reimu_System_Static PROPERTIES OUTPUT_NAME Reimu_System)

set(BASE "${PROJECT_SOURCE_DIR}/")

file(GLOB_RECURSE REIMU_HEADERS "${PROJECT_SOURCE_DIR}/*/*.hpp")
foreach(ITEM ${REIMU_HEADERS})
    get_filename_component(ITEM_PATH ${ITEM} PATH)
    string(REPLACE ${BASE} "" ITEM_PATH ${ITEM_PATH})
    install(FILES ${ITEM} DESTINATION include/libReimu_System/${ITEM_PATH})
endforeach()

file(GLOB REIMU_HEADERS "${PROJECT_SOURCE_DIR}/*.hpp")
foreach(ITEM ${REIMU_HEADERS})
    install(FILES ${ITEM} DESTINATION include/libReimu_System/)
endforeach()


install(TARGETS Reimu_System Reimu_System_Static DESTINATION lib)

add_executable(reimu_system_test Test.cpp)
target_link_libraries(reimu_system_test Reimu_System)
set_property(SOURCE Tests.cpp APPEND_STRING PROPERTY COMPILE_FLAGS " -I. ")