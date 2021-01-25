cmake_minimum_required(VERSION 3.5.1)
project(testing_c_code_with_system_calls)

include_directories(include)

# library to be tested
add_library(lib src/lib.c)

# executable just for the reference
add_executable(main src/main.c)
target_link_libraries(main lib)

# testing
include_directories(SYSTEM third_party/catch2/include third_party/fff/include)
add_executable(tests test/test_lib.cpp)
target_link_libraries(tests
  -Wl,--wrap=get_nprocs_conf
  lib
)
