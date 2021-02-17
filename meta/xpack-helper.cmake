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

if(micro-os-plus-libs-c-included)
  return()
endif()

set(micro-os-plus-libs-c-included TRUE)

message(STATUS "Including micro-os-plus-libs-c...")

# -----------------------------------------------------------------------------

function(target_sources_micro_os_plus_libs_c target)

  get_filename_component(xpack_current_folder ${CMAKE_CURRENT_FUNCTION_LIST_DIR} DIRECTORY)

  target_sources(
    ${target}

    PRIVATE
      ${xpack_current_folder}/src/stdlib/init-fini.c
      ${xpack_current_folder}/src/stdlib/assert.c
      ${xpack_current_folder}/src/stdlib/atexit.cpp
      ${xpack_current_folder}/src/stdlib/timegm.c
      ${xpack_current_folder}/src/stdlib/exit.c
      ${xpack_current_folder}/src/_sbrk.c
      ${xpack_current_folder}/src/c-syscalls-empty.cpp
  )

endfunction()

# -----------------------------------------------------------------------------

function(target_include_directories_micro_os_plus_libs_c target)

  get_filename_component(xpack_current_folder ${CMAKE_CURRENT_FUNCTION_LIST_DIR} DIRECTORY)

  target_include_directories(
    ${target}

    PUBLIC
      ${xpack_current_folder}/include
  )

endfunction()

# -----------------------------------------------------------------------------

function(target_compile_definitions_micro_os_plus_libs_c target)

  # None

endfunction()

# =============================================================================

function(add_libraries_micro_os_plus_libs_c)

  # ---------------------------------------------------------------------------

  find_package(micro-os-plus-diag-trace)
  find_package(micro-os-plus-startup)
  
  # ---------------------------------------------------------------------------

  if(NOT TARGET micro-os-plus-libs-c-static)

    add_library(micro-os-plus-libs-c-static STATIC EXCLUDE_FROM_ALL)

    target_sources_micro_os_plus_libs_c(micro-os-plus-libs-c-static)
    target_include_directories_micro_os_plus_libs_c(micro-os-plus-libs-c-static)
    target_compile_definitions_micro_os_plus_libs_c(micro-os-plus-libs-c-static)

    add_library(micro-os-plus::libs-c-static ALIAS micro-os-plus-libs-c-static)
    message(STATUS "micro-os-plus::libs-c-static")

    target_link_libraries(
      micro-os-plus-libs-c-static
      
      PUBLIC
        micro-os-plus::diag-trace-static
        micro-os-plus::startup-static
        micro-os-plus::architecture
    )

  endif()

  # ---------------------------------------------------------------------------

endfunction()

# -----------------------------------------------------------------------------
