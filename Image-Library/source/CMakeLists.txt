project (Image-Library)
add_library (tool code.cpp)

add_executable(Main main.cpp)
target_link_libraries(Main tool)
