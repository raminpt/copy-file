#ifndef LOG_MESSAGES_H
#define LOG_MESSAGES_H

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>

typedef enum {
    LOG_WARN,
    LOG_SUCCESS,
    LOG_INFO,
    LOG_ERR,
    LOG_LEVEL_LEN
} LOG_LEVEL;

static char * type[LOG_LEVEL_LEN] = {
    "WARN",
    "SUCCESS",
    "INFO",
    "ERR"
};

static char *colors[LOG_LEVEL_LEN] = {
    "\033[0;34m",   // blue
    "\033[0;37m",   // white
    "\033[0;33m",   // yellow
    "\033[0;31m"    // red
};


static time_t current_time;
static struct tm * m_time;

void get_time();

void log_message(LOG_LEVEL level, const char *fmt, ...);

#endif //LOG_MESSAGES_H
