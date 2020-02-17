add_library(lib STATIC "")

add_subdirectory(controllers)
add_subdirectory(models)

target_include_directories(lib PRIVATE ${CMAKE_SOURCE_DIR})
target_include_directories(lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/jwt/include)
target_include_directories(lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/sqlite/hdr)

target_link_libraries(lib PRIVATE cpprestsdk::cpprest ${Boost_LIBRARIES})
