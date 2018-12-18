add_library(StringTokenizer StringTokenizer.cpp)

install(FILES StringTokenizer.h DESTINATION /usr/include)
install(TARGETS StringTokenizer DESTINATION /usr/lib)
