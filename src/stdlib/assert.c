/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2015 Liviu Ionescu.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#include <micro-os-plus/diag/trace.h>

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// ----------------------------------------------------------------------------

void __assert_func (const char* file, int line, const char* func,
                    const char* failedexpr);

#if !defined(TRACE) && !defined(OS_USE_SEMIHOSTING_SYSCALLS)

void __attribute__ ((noreturn))
__assert_func (const char* file __attribute__ ((unused)),
               int line __attribute__ ((unused)),
               const char* func __attribute__ ((unused)),
               const char* failedexpr __attribute__ ((unused)))
{
  abort ();
}

#else

void __attribute__ ((noreturn))
__assert_func (const char* file, int line, const char* func,
               const char* failedexpr)
{
  // Not atomic, but otherwise the entire string might get too long,
  // and temporary buffer used by trace_printf() will overflow.
#if defined(TRACE)

  trace_printf ("assertion \"%s\" failed\n", failedexpr);
  trace_printf ("file: \"%s\"\n", file);
  trace_printf ("line: %d\n", line);
  if (func != NULL)
    {
      trace_printf ("function: %s\n", func);
    }

#elif defined(OS_USE_SEMIHOSTING_SYSCALLS)

  printf ("assertion \"%s\" failed\n", failedexpr);
  printf ("file: \"%s\"\n", file);
  printf ("line: %d\n", line);
  if (func != NULL)
    {
      printf ("function: %s\n", func);
    }
#endif
  abort ();
  /* NOTREACHED */
}

#endif /* !defined(TRACE) && !defined(OS_USE_SEMIHOSTING_SYSCALLS) */

// ----------------------------------------------------------------------------
