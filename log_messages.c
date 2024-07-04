#include "log_messages.h"

void get_time() {
    time(&current_time);
    m_time = localtime(&current_time);
}

void log_message(LOG_LEVEL level, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    get_time();
    printf("%s", colors[level]);
    printf("[%d/%d/%d -> %d:%d:%d][%s] ", m_time -> tm_mday,
                                        m_time -> tm_mon,
                                        m_time -> tm_year + 1900,
                                        m_time -> tm_hour,
                                        m_time -> tm_min,
                                        m_time -> tm_sec,
                                        type[level]);
    vfprintf(stdout, fmt, args);
    printf("%s", colors[LOG_SUCCESS]);
    va_end(args);
}
