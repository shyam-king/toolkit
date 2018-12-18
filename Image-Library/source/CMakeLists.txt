add_subdirectory(Image)

set (mainInclude Image/)

add_executable(Main main.cpp)
target_link_libraries(Main Image)
target_include_directories(Main PUBLIC ${mainInclude})
