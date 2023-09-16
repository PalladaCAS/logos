# About
logos is a header-only logging library. It is very simple and hasn't any "killer features".

# Log format
logos provides simple human & machine-readable logs. Every line of log may be either section or entry.

If line is a section, it use following syntax:

```
time section-name
```

If line is an entry, it use this syntax:

```
time entry-type file func line message
```

+ `time` represented in seconds
+ `section-name` may be anything, but logos has 2 built-in types: `INIT` for programm starting and `DEINIT` for programm ending.
+ `entry-type` may be anything, but logos has 4 built-in types:
  - `NOTE` for some internal information
  - `WARNING` for non-critical malfunctions
  - `ERROR` for critical malfunctions
  - `FAIL` for errors, that will automatically end with `exit()` (exit-code you can pass to macro)
  
# Log management
Also i have a plan to write full-featured log management system for logos. But now it's only _plans_.

# Documentation
Documentation for this library written in doxygen. You can automatically generate it this way:

``` shell
doxygen Doxyfile
```

# Compiler comatibility
This library is compatible with any C compiler that can deal with `#pragma once`.
