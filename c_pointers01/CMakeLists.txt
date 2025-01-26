cmake_minimum_required (VERSION 3.8)
enable_language(C)
add_executable (c_pointers01 "c_pointers01.c" "c_pointers01.h" "tools.c" "tools.h")

set_target_properties(c_pointers01 PROPERTIES
  C_STANDARD 17
  C_EXTENSIONS ON
)