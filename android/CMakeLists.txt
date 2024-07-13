cmake_minimum_required(VERSION 3.4.1)
project(CppTurbo)

set (CMAKE_VERBOSE_MAKEFILE ON)
add_compile_options(
        -fexceptions
        -frtti
        -std=c++17
)

add_library(react-native-cpp-turbo            STATIC
  ../cpp/NativeCppTurboModule.cpp
)

target_include_directories(
  react-native-cpp-turbo PUBLIC ../cpp
)

target_link_libraries(react-native-cpp-turbo
  jsi
  react_nativemodule_core
  react_codegen_RNCppTurboSpec
)
