cmake_minimum_required(VERSION 3.16)

set(TARGET "server")

project(${TARGET})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Debug)

if (APPLE)
    set(OPENSSL_ROOT_DIR "/usr/local/opt/openssl@1.1") 
    set(OPENSSL_LIBRARIES "/usr/local/opt/openssl@1.1/lib")
endif()

find_package(cpprestsdk REQUIRED)
find_package(Boost 1.72.0 COMPONENTS random system thread filesystem chrono atomic date_time regex)
find_package(SQLite3)

add_executable(${TARGET} main.cpp)

target_include_directories(${TARGET} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${TARGET} PRIVATE cpprestsdk::cpprest ${Boost_LIBRARIES} lib logic sqlite3)

add_subdirectory(lib)
add_subdirectory(logic)
