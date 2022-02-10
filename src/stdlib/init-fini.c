/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
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

// ----------------------------------------------------------------------------

// Empty initialisations. Normally should not be used, but if so,
// they must be used as a pair, and the startup code and linker
// script must be updated.

// ----------------------------------------------------------------------------

void
_init (void);

void
_fini (void);

// ----------------------------------------------------------------------------

void __attribute__ ((weak)) _init (void)
{
  ;
}

void __attribute__ ((weak)) _fini (void)
{
  ;
}

// ----------------------------------------------------------------------------

#endif // !Unix

// ----------------------------------------------------------------------------
