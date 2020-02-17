cmake_minimum_required(VERSION 3.16)

set(TARGET "server")

project(${TARGET})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Debug)

include(ExternalProject)

set(EXTERNAL_INSTALL_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/lib)


ExternalProject_Add(jwt
    GIT_REPOSITORY https://github.com/arun11299/cpp-jwt.git
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
    INSTALL_COMMAND cmake -E echo "Skipping install step."
    CONFIGURE_COMMAND cmake -E echo "Skipping configure step."
    BUILD_COMMAND cmake -E echo "Skipping build step."
)

ExternalProject_Add(sqlite
    GIT_REPOSITORY https://github.com/SqliteModernCpp/sqlite_modern_cpp.git
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
    INSTALL_COMMAND cmake -E echo "Skipping install step."
    CONFIGURE_COMMAND cmake -E echo "Skipping configure step."
    BUILD_COMMAND cmake -E echo "Skipping build step."
)

if (APPLE)
    set(OPENSSL_ROOT_DIR "/usr/local/opt/openssl@1.1") 
    set(OPENSSL_LIBRARIES "/usr/local/opt/openssl@1.1/lib")
endif()

set(OPENSSL_USE_STATIC_LIBS TRUE)
set(CPPRESTSDK_USE_STATIC_LIBS TRUE)
set(Boost_NO_BOOST_CMAKE 1)

find_package(OpenSSL)
find_package(cpprestsdk REQUIRED)
find_package(Boost 1.72.0 COMPONENTS random system thread filesystem chrono atomic date_time regex)
find_package(SQLite3)

add_executable(${TARGET} main.cpp)

target_include_directories(${TARGET} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${TARGET} PRIVATE cpprestsdk::cpprest ${Boost_LIBRARIES} lib logic sqlite3)

add_subdirectory(lib)
add_subdirectory(logic)
