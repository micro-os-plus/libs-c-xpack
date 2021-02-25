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

# https://cmake.org/cmake/help/v3.18/
# https://cmake.org/cmake/help/v3.18/manual/cmake-packages.7.html#package-configuration-file

if(micro-os-plus-libs-c-included)
  return()
endif()

set(micro-os-plus-libs-c-included TRUE)

message(STATUS "Including micro-os-plus-libs-c...")

# -----------------------------------------------------------------------------
# Dependencies.

find_package(micro-os-plus-diag-trace REQUIRED)
find_package(micro-os-plus-startup REQUIRED)

# -----------------------------------------------------------------------------
# The current folder.

get_filename_component(xpack_current_folder ${CMAKE_CURRENT_LIST_DIR} DIRECTORY)

# -----------------------------------------------------------------------------

if(NOT TARGET micro-os-plus-libs-c-interface)

  # Since this library provides non-weak symbols to customise
  # the newlib behaviour, it cannot be static, and the --whole-archive
  # trick has other disadvantages.
  add_library(micro-os-plus-libs-c-interface INTERFACE EXCLUDE_FROM_ALL)

  # ---------------------------------------------------------------------------

  target_sources(
    micro-os-plus-libs-c-interface

    INTERFACE
      ${xpack_current_folder}/src/stdlib/init-fini.c
      ${xpack_current_folder}/src/stdlib/assert.c
      ${xpack_current_folder}/src/stdlib/atexit.cpp
      ${xpack_current_folder}/src/stdlib/timegm.c
      ${xpack_current_folder}/src/stdlib/exit.c
      ${xpack_current_folder}/src/_sbrk.c
      ${xpack_current_folder}/src/c-syscalls-empty.cpp
  )

  target_include_directories(
    micro-os-plus-libs-c-interface

    INTERFACE
      ${xpack_current_folder}/include
  )

  target_link_libraries(
    micro-os-plus-libs-c-interface
    
    INTERFACE
      micro-os-plus::diag-trace-static
      micro-os-plus::startup-static
      micro-os-plus::architecture
  )

  # ---------------------------------------------------------------------------
  # Aliases.

  add_library(micro-os-plus::libs-c ALIAS micro-os-plus-libs-c-interface)
  message(STATUS "micro-os-plus::libs-c")

endif()

# -----------------------------------------------------------------------------
