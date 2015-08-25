CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(arglyzer)
INCLUDE_DIRECTORIES(include)
ADD_LIBRARY(arglyzer SHARED src/arglyzer.c src/option.c src/result.c)
