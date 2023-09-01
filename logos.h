#ifndef __LOGOS_LOGGING_LIBRARY__
#define __LOGOS_LOGGING_LIBRARY__

#ifdef LOGS_ENABLE

#ifndef LOGS_FILENAME
#error "Undefined log filename"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define logos_general_log(...)                                    \
    {                                                             \
        FILE *log_file = fopen(LOGS_FILENAME, "a");               \
        if (!log_file) {                                          \
            fprintf(stderr, "logos: Fail to open log file %s\n",  \
                    LOGS_FILENAME);                               \
            exit(0);                                              \
        }                                                         \
        fprintf(log_file, __VA_ARGS__);                           \
        if (fclose(log_file)) {                                   \
            fprintf(stderr, "logos: Fail to close gol file %s\n", \
                    LOGS_FILENAME);                               \
            exit(0);                                              \
        }                                                         \
    }

#define logos_section(section)                          \
    logos_general_log("%ld %s\n", time(NULL), section)

#define logos_entry(entry, msg)                \
    logos_general_log("%ld %s %s %s %d %s\n",  \
                      time(NULL),              \
                      entry,                   \
                      __FILE__,                \
                      __func__,                \
                      __LINE__,                \
                      msg)

#define logos_init()                            \
    logos_section("INIT")

#define logos_deinit()                          \
    logos_section("DEINIT\n\n")

#define logos_note(msg)                         \
    logos_entry("NOTE", msg)

#define logos_warning(msg)                      \
    logos_entry("WARNING", msg)

#define logos_error(msg)                        \
    logos_entry("ERROR", msg)

#define logos_enter()                           \
    logos_note("ENTER");

#define logos_leave()                           \
    logos_note("LEAVE")

#else

#define logos_general_log(...) ;
#define logos_section(section) ;
#define logos_entry(entry, msg) ;
#define logos_init() ;
#define logos_deinit() ;
#define logos_note(msg) ;
#define logos_warning(msg) ;
#define logos_error(msg) ;

#endif

#endif
