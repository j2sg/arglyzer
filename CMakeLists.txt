CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(arglyzer)

INCLUDE_DIRECTORIES(include)

ADD_LIBRARY(arglyzer SHARED src/arglyzer.c src/optionslist.c src/option.c src/result.c)

INSTALL(DIRECTORY include/ DESTINATION /usr/include/arglyzer FILES_MATCHING PATTERN "*.h")
INSTALL(FILES build/libarglyzer.so DESTINATION /usr/lib)
