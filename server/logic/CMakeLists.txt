add_library(logic STATIC "")

add_subdirectory(controllers)

target_include_directories(logic PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(logic cpprestsdk::cpprest ${Boost_LIBRARIES} lib)