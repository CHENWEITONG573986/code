# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\NotaBook_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\NotaBook_autogen.dir\\ParseCache.txt"
  "NotaBook_autogen"
  )
endif()
