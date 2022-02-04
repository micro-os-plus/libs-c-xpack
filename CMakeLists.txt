#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2021 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/MIT/.
#
# -----------------------------------------------------------------------------

# This file is intended to be consumed by applications with:
#
# `add_subdirectory("xpacks/micro-os-plus-libs-c")`
#
# The result is an interface library that can be added to the linker with:
#
# `target_link_libraries(your-target PUBLIC micro-os-plus::libs-c)`

# -----------------------------------------------------------------------------
## Preamble ##

# https://cmake.org/cmake/help/v3.20/
cmake_minimum_required(VERSION 3.20)

project(
  micro-os-plus-libs-c
  DESCRIPTION "µOS++ complementary C library functions"
)

if(COMMAND xpack_get_package_name_and_version)
  xpack_get_package_name_and_version("${CMAKE_CURRENT_SOURCE_DIR}/package.json")
  message(VERBOSE "Processing xPack ${PACKAGE_JSON_NAME}@${PACKAGE_JSON_VERSION}...")
endif()

# -----------------------------------------------------------------------------
## The project library definitions ##

# https://cmake.org/cmake/help/v3.20/command/add_library.html?highlight=interface#normal-libraries
# PRIVATE: build definitions, used internally
# INTERFACE: usage definitions, passed up to targets linking to it
# PUBLIC: both

# Since this library provides non-weak symbols to customise
# the newlib behaviour, it cannot be static, and the --whole-archive
# trick has other disadvantages.
add_library(micro-os-plus-libs-c-interface INTERFACE EXCLUDE_FROM_ALL)

# -----------------------------------------------------------------------------
# Target settings.

target_include_directories(
  micro-os-plus-libs-c-interface

  INTERFACE
    "include"
)

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

target_compile_definitions(
  micro-os-plus-libs-c-interface

  INTERFACE
    # ... add preprocessor macro definitions.
)

target_link_libraries(
  micro-os-plus-libs-c-interface

  INTERFACE
    # Dependencies
    micro-os-plus::diag-trace
    micro-os-plus::startup
    micro-os-plus::architecture
)

if (COMMAND xpack_display_target_lists)
  xpack_display_target_lists(micro-os-plus-libs-c-interface)
endif()

# -----------------------------------------------------------------------------
# Aliases.

# https://cmake.org/cmake/help/v3.20/command/add_library.html#alias-libraries
add_library(micro-os-plus::libs-c ALIAS micro-os-plus-libs-c-interface)
message(VERBOSE "> micro-os-plus::libs-c -> micro-os-plus-libs-c-interface")

# -----------------------------------------------------------------------------
