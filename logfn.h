#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

uint8_t is_log_color_support = 0;

void initLogFn() { is_log_color_support = isatty(STDERR_FILENO); }

#define logf stderr

#define logDebug(fmt, ...)                                                     \
    do {                                                                       \
        const char* const restrict prefix =                                    \
            is_log_color_support ? "\x1b[1;35m[debug]\x1b[0m" : "[debug]";     \
        fprintf(logf, "%s " fmt "\n", prefix, ##__VA_ARGS__);                  \
    } while (0)

#define logInfo(fmt, ...)                                                      \
    do {                                                                       \
        const char* const restrict prefix =                                    \
            is_log_color_support ? "\x1b[1;32m[info]\x1b[0m" : "[info]";       \
        fprintf(logf, "%s " fmt "\n", prefix, ##__VA_ARGS__);                  \
    } while (0)

#define logWarning(fmt, ...)                                                   \
    do {                                                                       \
        const char* const restrict prefix =                                    \
            is_log_color_support ? "\x1b[1;33m[warning]\x1b[0m" : "[warning]"; \
        fprintf(logf, "%s " fmt "\n", prefix, ##__VA_ARGS__);                  \
    } while (0)

#define logError(fmt, ...)                                                     \
    do {                                                                       \
        const char* const restrict prefix =                                    \
            is_log_color_support ? "\x1b[1;31m[error]\x1b[0m" : "[error]";     \
        fprintf(logf, "%s " fmt "\n", prefix, ##__VA_ARGS__);                  \
    } while (0)
//
