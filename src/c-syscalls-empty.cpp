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

#include <newlib/c-syscalls.h>
#include <micro-os-plus/architecture.h>
#include <micro-os-plus/diag/trace.h>

#include <errno.h>

using namespace micro_os_plus;

// ----------------------------------------------------------------------------

// Semihosting has its own set of implementations.

#if !defined(MICRO_OS_PLUS_USE_SEMIHOSTING_SYSCALLS)

int __attribute__ ((weak)) _chown (const char* path __attribute__ ((unused)),
                                   uid_t owner __attribute__ ((unused)),
                                   gid_t group __attribute__ ((unused)))
{
#if defined(MICRO_OS_PLUS_DEBUG) \
    && (defined(MICRO_OS_PLUS_DEBUG_SYSCALLS_BRK) \
        || defined(MICRO_OS_PLUS_DEBUG_SYSCALL_CHOWN_BRK))
  architecture::brk ();
#endif

  trace::printf ("%s() ENOSYS\n", __FUNCTION__);

  errno = ENOSYS;
  return -1;
}

int __attribute__ ((weak)) _close (int fildes __attribute__ ((unused)))
{
#if defined(MICRO_OS_PLUS_DEBUG) \
    && (defined(MICRO_OS_PLUS_DEBUG_SYSCALLS_BRK) \
        || defined(MICRO_OS_PLUS_DEBUG_SYSCALL_CLOSE_BRK))
  architecture::brk ();
#endif

  trace::printf ("%s() ENOSYS\n", __FUNCTION__);

  errno = ENOSYS;
  return -1;
}

int __attribute__ ((weak))
_execve (const char* name __attribute__ ((unused)),
         char* const argv[] __attribute__ ((unused)),
         char* const envp[] __attribute__ ((unused)))
{
#if defined(MICRO_OS_PLUS_DEBUG) \
    && (defined(MICRO_OS_PLUS_DEBUG_SYSCALLS_BRK) \
        || defined(MICRO_OS_PLUS_DEBUG_SYSCALL_EXECVE_BRK))
  architecture::brk ();
#endif

  trace::printf ("%s() ENOSYS\n", __FUNCTION__);

  errno = ENOSYS;
  return -1;
}

pid_t __attribute__ ((weak)) _fork (void)
{
#if defined(MICRO_OS_PLUS_DEBUG) \
    && (defined(MICRO_OS_PLUS_DEBUG_SYSCALLS_BRK) \
        || defined(MICRO_OS_PLUS_DEBUG_SYSCALL_FORK_BRK))
  architecture::brk ();
#endif

  trace::printf ("%s() ENOSYS\n", __FUNCTION__);

  errno = ENOSYS;
  return -1;
}

int __attribute__ ((weak)) _fstat (int fildes __attribute__ ((unused)),
                                   struct stat* st __attribute__ ((unused)))
{
  if (_isatty (fildes))
    {
      // The file is a character special file (a device like a terminal)
      st->st_mode = S_IFCHR;
      return 0;
    }

#if defined(MICRO_OS_PLUS_DEBUG) \
    && (defined(MICRO_OS_PLUS_DEBUG_SYSCALLS_BRK) \
        || defined(MICRO_OS_PLUS_DEBUG_SYSCALL_FSTAT_BRK))
  architecture::brk ();
#endif

  trace::printf ("%s() ENOSYS\n", __FUNCTION__);

  errno = ENOSYS;
  return -1;
}

pid_t __attribute__ ((weak)) _getpid (void)
{
  return 1;
}

int __attribute__ ((weak))
_gettimeofday (timeval* ptimeval __attribute__ ((unused)),
               void* ptimezone __attribute__ ((unused)))
{
#if defined(MICRO_OS_PLUS_DEBUG) \
    && (defined(MICRO_OS_PLUS_DEBUG_SYSCALLS_BRK) \
        || defined(MICRO_OS_PLUS_DEBUG_SYSCALL_GETTIMEOFDAY_BRK))
  architecture::brk ();
#endif

  trace::printf ("%s() ENOSYS\n", __FUNCTION__);

  errno = ENOSYS;
  return -1;
}

int __attribute__ ((weak)) _isatty (int fildes __attribute__ ((unused)))
{
  if (fildes == STDOUT_FILENO || fildes == STDERR_FILENO)
    {
      return 1;
    }

#if defined(MICRO_OS_PLUS_DEBUG) \
    && (defined(MICRO_OS_PLUS_DEBUG_SYSCALLS_BRK) \
        || defined(MICRO_OS_PLUS_DEBUG_SYSCALL_ISATTY_BRK))
  architecture::brk ();
#endif

  trace::printf ("%s() false\n", __FUNCTION__);

  return 0;
}

int __attribute__ ((weak))
_kill (pid_t pid __attribute__ ((unused)), int sig __attribute__ ((unused)))
{
#if defined(MICRO_OS_PLUS_DEBUG) \
    && (defined(MICRO_OS_PLUS_DEBUG_SYSCALLS_BRK) \
        || defined(MICRO_OS_PLUS_DEBUG_SYSCALL_KILL_BRK))
  architecture::brk ();
#endif

  trace::printf ("%s() ENOSYS\n", __FUNCTION__);

  errno = ENOSYS;
  return -1;
}

int __attribute__ ((weak))
_link (const char* existing __attribute__ ((unused)),
       const char* _new __attribute__ ((unused)))
{
#if defined(MICRO_OS_PLUS_DEBUG) \
    && (defined(MICRO_OS_PLUS_DEBUG_SYSCALLS_BRK) \
        || defined(MICRO_OS_PLUS_DEBUG_SYSCALL_LINK_BRK))
  architecture::brk ();
#endif

  trace::printf ("%s() ENOSYS\n", __FUNCTION__);

  errno = ENOSYS;
  return -1;
}

off_t __attribute__ ((weak))
_lseek (int fildes __attribute__ ((unused)), int ptr __attribute__ ((unused)),
        int dir __attribute__ ((unused)))
{
  if (_isatty (fildes))
    {
      return 0;
    }

#if defined(MICRO_OS_PLUS_DEBUG) \
    && (defined(MICRO_OS_PLUS_DEBUG_SYSCALLS_BRK) \
        || defined(MICRO_OS_PLUS_DEBUG_SYSCALL_LSEEK_BRK))
  architecture::brk ();
#endif

  trace::printf ("%s() ENOSYS\n", __FUNCTION__);

  errno = ENOSYS;
  return -1;
}

int __attribute__ ((weak))
_open (const char* file __attribute__ ((unused)),
       int flags __attribute__ ((unused)), int mode __attribute__ ((unused)))
{
#if defined(MICRO_OS_PLUS_DEBUG) \
    && (defined(MICRO_OS_PLUS_DEBUG_SYSCALLS_BRK) \
        || defined(MICRO_OS_PLUS_DEBUG_SYSCALL_OPEN_BRK))
  architecture::brk ();
#endif

  trace::printf ("%s() ENOSYS\n", __FUNCTION__);

  errno = ENOSYS;
  return -1;
}

int __attribute__ ((weak))
_openat (int dirfd __attribute__ ((unused)),
         const char* name __attribute__ ((unused)),
         int flags __attribute__ ((unused)), int mode __attribute__ ((unused)))
{
#if defined(MICRO_OS_PLUS_DEBUG) \
    && (defined(MICRO_OS_PLUS_DEBUG_SYSCALLS_BRK) \
        || defined(MICRO_OS_PLUS_DEBUG_SYSCALL_OPENAT_BRK))
  architecture::brk ();
#endif

  trace::printf ("%s() ENOSYS\n", __FUNCTION__);

  errno = ENOSYS;
  return -1;
}

ssize_t __attribute__ ((weak))
_read (int fildes __attribute__ ((unused)), void* ptr __attribute__ ((unused)),
       size_t len __attribute__ ((unused)))
{
#if defined(MICRO_OS_PLUS_DEBUG) \
    && (defined(MICRO_OS_PLUS_DEBUG_SYSCALLS_BRK) \
        || defined(MICRO_OS_PLUS_DEBUG_SYSCALL_READ_BRK))
  architecture::brk ();
#endif

  trace::printf ("%s() ENOSYS\n", __FUNCTION__);

  errno = ENOSYS;
  return -1;
}

int __attribute__ ((weak))
_readlink (const char* path __attribute__ ((unused)),
           void* buf __attribute__ ((unused)),
           size_t bufsize __attribute__ ((unused)))
{
#if defined(MICRO_OS_PLUS_DEBUG) \
    && (defined(MICRO_OS_PLUS_DEBUG_SYSCALLS_BRK) \
        || defined(MICRO_OS_PLUS_DEBUG_SYSCALL_READLINK_BRK))
  architecture::brk ();
#endif

  trace::printf ("%s() ENOSYS\n", __FUNCTION__);

  errno = ENOSYS;
  return -1;
}

int __attribute__ ((weak)) _stat (const char* file __attribute__ ((unused)),
                                  struct stat* st __attribute__ ((unused)))
{
#if defined(MICRO_OS_PLUS_DEBUG) \
    && (defined(MICRO_OS_PLUS_DEBUG_SYSCALLS_BRK) \
        || defined(MICRO_OS_PLUS_DEBUG_SYSCALL_STAT_BRK))
  architecture::brk ();
#endif

  trace::printf ("%s() ENOSYS\n", __FUNCTION__);

  errno = ENOSYS;
  return -1;
}

int __attribute__ ((weak))
_symlink (const char* existing __attribute__ ((unused)),
          const char* _new __attribute__ ((unused)))
{
#if defined(MICRO_OS_PLUS_DEBUG) \
    && (defined(MICRO_OS_PLUS_DEBUG_SYSCALLS_BRK) \
        || defined(MICRO_OS_PLUS_DEBUG_SYSCALL_SYMLINK_BRK))
  architecture::brk ();
#endif

  trace::printf ("%s() ENOSYS\n", __FUNCTION__);

  errno = ENOSYS;
  return -1;
}

clock_t __attribute__ ((weak))
_times (tms* buf __attribute__ ((unused)))
{
#if defined(MICRO_OS_PLUS_DEBUG) \
    && (defined(MICRO_OS_PLUS_DEBUG_SYSCALLS_BRK) \
        || defined(MICRO_OS_PLUS_DEBUG_SYSCALL_TIMES_BRK))
  architecture::brk ();
#endif

  trace::printf ("%s() ENOSYS\n", __FUNCTION__);

  errno = ENOSYS;
  return static_cast<clock_t> (-1);
}

int __attribute__ ((weak)) _unlink (const char* name __attribute__ ((unused)))
{
#if defined(MICRO_OS_PLUS_DEBUG) \
    && (defined(MICRO_OS_PLUS_DEBUG_SYSCALLS_BRK) \
        || defined(MICRO_OS_PLUS_DEBUG_SYSCALL_UNLINK_BRK))
  architecture::brk ();
#endif

  trace::printf ("%s() ENOSYS\n", __FUNCTION__);

  errno = ENOSYS;
  return -1;
}

pid_t __attribute__ ((weak)) _wait (int* status __attribute__ ((unused)))
{
#if defined(MICRO_OS_PLUS_DEBUG) \
    && (defined(MICRO_OS_PLUS_DEBUG_SYSCALLS_BRK) \
        || defined(MICRO_OS_PLUS_DEBUG_SYSCALL_WAIT_BRK))
  architecture::brk ();
#endif

  trace::printf ("%s() ENOSYS\n", __FUNCTION__);

  errno = ENOSYS;
  return -1;
}

ssize_t __attribute__ ((weak))
_write (int fildes __attribute__ ((unused)),
        const void* ptr __attribute__ ((unused)),
        size_t len __attribute__ ((unused)))
{
#if defined(MICRO_OS_PLUS_DEBUG) \
    && (defined(MICRO_OS_PLUS_DEBUG_SYSCALLS_BRK) \
        || defined(MICRO_OS_PLUS_DEBUG_SYSCALL_WRITE_BRK))
  architecture::brk ();
#endif

  trace::printf ("%s() ENOSYS\n", __FUNCTION__);

  errno = ENOSYS;
  return -1;
}

// ----------------------------------------------------------------------------

#endif // !defined(MICRO_OS_PLUS_USE_SEMIHOSTING_SYSCALLS)

// ----------------------------------------------------------------------------

#endif // !Unix

// ----------------------------------------------------------------------------
