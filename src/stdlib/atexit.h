/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2016 Liviu Ionescu.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/MIT/.
 */

#if (!(defined(__APPLE__) || defined(__linux__) || defined(__unix__) \
       || defined(__EXCEPTIONS))) \
    || defined(__DOXYGEN__)

// ----------------------------------------------------------------------------

#define _LITE_EXIT

/*
 *  Common definitions for atexit-like routines
 */

#if defined(__cplusplus)
extern "C"
{
#endif // defined(__cplusplus)

  // --------------------------------------------------------------------------

  enum __atexit_types
  {
    __et_atexit, // 0
    __et_onexit, // 1
    __et_cxa // 2
  };

  extern void
  __call_exitprocs (int, void*);

  typedef void (*exit_function_t) (void);

  extern int
  __register_exitproc (int, exit_function_t fn, void*, void*);

  extern void
  micro_os_plus_run_fini_array (void);

  // --------------------------------------------------------------------------

#if defined(__cplusplus)
}
#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // !Unix

// ----------------------------------------------------------------------------
