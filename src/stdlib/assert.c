/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus/)
 * Copyright (c) 2015 Liviu Ionescu.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/MIT/.
 */

#if (!(defined(__APPLE__) || defined(__linux__) || defined(__unix__))) \
    || defined(__DOXYGEN__)

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#include <micro-os-plus/diag/trace.h>

#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

// ----------------------------------------------------------------------------

#if !defined(MICRO_OS_PLUS_TRACE) && !defined(MICRO_OS_PLUS_USE_SEMIHOSTING_SYSCALLS)

void __attribute__ ((noreturn))
__assert_func (const char* file __attribute__ ((unused)),
               int line __attribute__ ((unused)),
               const char* function __attribute__ ((unused)),
               const char* failedexpr __attribute__ ((unused)))
{
  abort ();
}

#else

void __attribute__ ((noreturn))
__assert_func (const char* file, int line, const char* function,
               const char* failedexpr)
{
  // Not atomic, but otherwise the entire string might get too long,
  // and temporary buffer used by trace_printf() will overflow.
#if defined(MICRO_OS_PLUS_TRACE)

  trace_printf ("assertion \"%s\" failed\n", failedexpr);
  trace_printf ("file: \"%s\"\n", file);
  trace_printf ("line: %d\n", line);
  if (function != NULL)
    {
      trace_printf ("function: %s\n", function);
    }

#elif defined(MICRO_OS_PLUS_USE_SEMIHOSTING_SYSCALLS)

  printf ("assertion \"%s\" failed\n", failedexpr);
  printf ("file: \"%s\"\n", file);
  printf ("line: %d\n", line);
  if (function != NULL)
    {
      printf ("function: %s\n", function);
    }
#endif
  abort ();
  /* NOTREACHED */
}

#endif // !defined(MICRO_OS_PLUS_TRACE) && !defined(MICRO_OS_PLUS_USE_SEMIHOSTING_SYSCALLS)

// ----------------------------------------------------------------------------

#endif // !Unix

// ----------------------------------------------------------------------------
