# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/ReduceImage_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/ReduceImage_autogen.dir/ParseCache.txt"
  "ReduceImage_autogen"
  )
endif()
