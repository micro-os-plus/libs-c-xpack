#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2021 Liviu Ionescu
#
# This Source Code Form is subject to the terms of the MIT License.
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/MIT/.
#
# -----------------------------------------------------------------------------

# https://cmake.org/cmake/help/v3.20/

# PRIVATE: build definitions, used internally
# INTERFACE: usage definitions, passed up to targets linking to it
# PUBLIC: both

if(COMMAND xpack_get_package_name_and_version)
  xpack_get_package_name_and_version("${CMAKE_CURRENT_SOURCE_DIR}/../package.json")
  message(VERBOSE "Processing xPack ${PACKAGE_JSON_NAME}@${PACKAGE_JSON_VERSION}...")
endif()

# -----------------------------------------------------------------------------

# Since this library provides non-weak symbols to customise
# the newlib behaviour, it cannot be static, and the --whole-archive
# trick has other disadvantages.
add_library(micro-os-plus-libs-c-interface INTERFACE EXCLUDE_FROM_ALL)

# -----------------------------------------------------------------------------

target_sources(
  micro-os-plus-libs-c-interface

  INTERFACE
    "src/stdlib/assert.c"
    "src/stdlib/atexit.cpp"
    "src/stdlib/exit.c"
    "src/stdlib/init-fini.c"
    "src/stdlib/timegm.c"
    "src/_sbrk.c"
    "src/c-syscalls-empty.cpp"
)

message(VERBOSE "+ sources/src/stdlib/assert.c")
message(VERBOSE "+ sources/src/stdlib/atexit.cpp")
message(VERBOSE "+ sources/src/stdlib/exit.c")
message(VERBOSE "+ sources/src/stdlib/init-fini.c")
message(VERBOSE "+ sources/src/stdlib/timegm.c")
message(VERBOSE "+ sources/src/_sbrk.c")
message(VERBOSE "+ sources/src/c-syscalls-empty.cpp")

target_include_directories(
  micro-os-plus-libs-c-interface

  INTERFACE
    "include"
)

message(VERBOSE "+ sources/include")

target_link_libraries(
  micro-os-plus-libs-c-interface

  INTERFACE
    micro-os-plus::diag-trace
    micro-os-plus::startup
    micro-os-plus::architecture
)

# -----------------------------------------------------------------------------
# Aliases.

add_library(micro-os-plus::libs-c ALIAS micro-os-plus-libs-c-interface)
message(VERBOSE "micro-os-plus::libs-c -> micro-os-plus-libs-c-interface")

# -----------------------------------------------------------------------------
