# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\LogicQt_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\LogicQt_autogen.dir\\ParseCache.txt"
  "LogicQt_autogen"
  )
endif()
