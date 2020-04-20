cmake_minimum_required(VERSION 3.10)

set(TARGET "server")

project(${TARGET})

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Debug)

if (APPLE)
    set(OPENSSL_ROOT_DIR "/usr/local/opt/openssl@1.1") 
    set(OPENSSL_LIBRARIES "/usr/local/opt/openssl@1.1/lib")
endif()

set(OPENSSL_USE_STATIC_LIBS TRUE)
set(CPPRESTSDK_USE_STATIC_LIBS TRUE)
set(Boost_NO_BOOST_CMAKE 1)

find_package(OpenSSL)
find_package(cpprestsdk REQUIRED)
find_package(Boost COMPONENTS random system thread filesystem chrono atomic date_time regex)
find_package(SQLite3)

add_executable(${TARGET} main.cpp)


include(find_lua)
include(customcommands)

target_include_directories(${TARGET} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if (UNIX AND NOT APPLE AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--start-group ")
    target_link_libraries(${TARGET} PUBLIC ${CMAKE_DL_LIBS})
endif()

target_link_libraries(${TARGET} PRIVATE cpprestsdk::cpprest ${Boost_LIBRARIES} lib logic sqlite3 crypto)

if (UNIX AND NOT APPLE)
    target_link_libraries(${TARGET} PUBLIC ${CMAKE_DL_LIBS})
endif()

if (UNIX AND NOT APPLE)
endif()

add_definitions(-DCPP_JWT_USE_VENDORED_NLOHMANN_JSON)

add_subdirectory(lib)
add_subdirectory(logic)
add_subdirectory(config)
