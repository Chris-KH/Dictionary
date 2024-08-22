# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ProjectCS163_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ProjectCS163_autogen.dir\\ParseCache.txt"
  "ProjectCS163_autogen"
  )
endif()
