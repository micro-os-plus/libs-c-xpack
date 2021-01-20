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

message(STATUS "Including micro-os-plus-libs-c...")

function(target_sources_micro_os_plus_libs_c target)

  get_filename_component(PARENT_DIR ${CMAKE_CURRENT_FUNCTION_LIST_DIR} DIRECTORY)

  target_sources(
    ${target}

    PRIVATE
      ${PARENT_DIR}/src/stdlib/init-fini.c
      ${PARENT_DIR}/src/stdlib/assert.c
      ${PARENT_DIR}/src/stdlib/atexit.cpp
      ${PARENT_DIR}/src/stdlib/timegm.c
      ${PARENT_DIR}/src/stdlib/exit.c
      ${PARENT_DIR}/src/_sbrk.c
      ${PARENT_DIR}/src/c-syscalls-empty.cpp
    )
endfunction()

function(target_include_directories_micro_os_plus_libs_c target)

  get_filename_component(PARENT_DIR ${CMAKE_CURRENT_FUNCTION_LIST_DIR} DIRECTORY)

  target_include_directories(
    ${target}

    PUBLIC
      ${PARENT_DIR}/include
  )
endfunction()

# -----------------------------------------------------------------------------
