/**
   @file logos.h
   @author Centrix14
   @date 07.09.2023
   @brief Main file
 */

/**
   @def logos_general_log(...)
   @brief General logging macro
   @param ... printf-formatted args
 
   This macro does all dirty work with files. It opens LOGOS_FILENAME
   and calls fprintf with given arguments for file.
 */

/**
   @def logos_section(section)
   @brief Writes section into log file
   @param section name of the section (string)

   Section contains 2 elements: time and section name
 */

/**
   @def logos_entry(entry)
   @brief Writes entry into log file
   @param entry name of the entry (string)
   @param msg entry message (string)

   Entry contains these elements:
   1. Time
   2. Entry name
   3. File name
   4. Function name
   5. Line number
   6. Entry message
 */

/**
   @def logos_init()
   @brief Writes init section

   All logs must start with INIT section.
 */

/**
   @def logos_deinit()
   @brief Writes deinit section

   All logs must end up with DEINIT section.
 */

/**
   @def logos_note(msg)
   @brief Writes note entry
   @param msg note message itself (string)

   NOTE is a general entry for some program-specific information.
 */

/**
   @def logos_warning(msg)
   @brief Writes warning entry
   @param msg warning message itself

   WARNING indicates some non-critical malfunctions.
 */

/**
   @def logos_error(msg)
   @brief Writes error entry
   @param msg error message itself

   Use ERROR to indicate some critical, important malfunction.
 */

/**
   @def logos_enter()
   @brief Writes enter entry

   Special type of NOTE that indicates that program enters in some function.
 */

/**
   @def logos_leave()
   @brief Writes leave entry

   Special type of NOTE that indicates that program leaves some function.
 */

#pragma once

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
#define logos_enter() ;
#define logos_leave() ;

#endif
