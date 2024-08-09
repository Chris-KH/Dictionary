# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Project-CS163_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Project-CS163_autogen.dir\\ParseCache.txt"
  "Project-CS163_autogen"
  )
endif()
