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

# -----------------------------------------------------------------------------

function(target_sources_micro_os_plus_libs_c target)

  get_filename_component(xpack_root_folder ${CMAKE_CURRENT_FUNCTION_LIST_DIR} DIRECTORY)

  target_sources(
    ${target}

    PRIVATE
      ${xpack_root_folder}/src/stdlib/init-fini.c
      ${xpack_root_folder}/src/stdlib/assert.c
      ${xpack_root_folder}/src/stdlib/atexit.cpp
      ${xpack_root_folder}/src/stdlib/timegm.c
      ${xpack_root_folder}/src/stdlib/exit.c
      ${xpack_root_folder}/src/_sbrk.c
      ${xpack_root_folder}/src/c-syscalls-empty.cpp
  )

endfunction()

# -----------------------------------------------------------------------------

function(target_include_directories_micro_os_plus_libs_c target)

  get_filename_component(xpack_root_folder ${CMAKE_CURRENT_FUNCTION_LIST_DIR} DIRECTORY)

  target_include_directories(
    ${target}

    PUBLIC
      ${xpack_root_folder}/include
  )

endfunction()

# -----------------------------------------------------------------------------
