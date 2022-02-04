# Change & release log

Releases in reverse chronological order.

Please check
[GitHub](https://github.com/micro-os-plus/libs-c-xpack/issues/)
and close existing issues and pull requests.

## 2022-02-04

- 55c3eff cmake: add xpack_display_target_lists
- 4f6d2c1 _sbrk: fix warnings

## 2022-02-02

- d989d8c add meson support
- 813642d c-syscalls-empty.cpp fix casts

## 2022-01-28

- 1caf860 rework CMake, top config, no sources

## 2022-01-26

- v2.1.0
- rework CMake

## 2022-01-02

- v2.0.2

## 2021-03-09

- v2.0.1
- fix/silence warnings

## 2021-03-01

- v2.0.0

## 2021-02-28

- rename micro_os_plus

## 2021-02-07

- v1.1.1-pre
- [#8] - disable atexit.cpp if exceptions are active
- [#9] - add trace message to __register_exitproc()

## 2021-02-04

- v1.1.0
- first restructured release

## 2018-04-16

- v1.0.6
- move deps back to npm
- update README install

## 2018-01-25

- v1.0.5
- cosmetics

## 2018-01-24

- v1.0.4
- [#1] c-syscalls-empty.c: fix conditional macro
- [#2] _getpid() always return 1
- [#3] c-syscalls-empty.c: add trace::printf()
- [#4] c-syscalls-empty.c: add BRK calls on DEBUG
- rename c-syscalls-empty.cpp
- [#5] add extern "C" to c-syscalls.h
- [#6] exit.c: remove ARM specific code
- [#7] exit.c: add os_arch_*() calls

## 2018-01-09

- v1.0.3
- README updates

## 2017-10-04

- v1.0.2
- package.json clean-ups
- add CHANGELOG.md

## 2017-09-04

- v1.0.1
- initial version, copied from µOS++.
