add_subdirectory(StringTokenizer)
add_executable(tokenize tokenize.cpp)
target_link_libraries(tokenize StringTokenizer)
target_include_directories(tokenize PUBLIC StringTokenizer/)
install(TARGETS tokenize DESTINATION /bin/)
