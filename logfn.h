#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

uint8_t is_log_color_support = 0;

void initLogFn() { is_log_color_support = isatty(STDERR_FILENO); }

#define logf stderr

#define logDebug(fmt, ...)                                                     \
    do {                                                                       \
        const char* const restrict prefix =                                    \
            is_log_color_support ? "\x1b[1;35m[Debug]\x1b[0m" : "[Debug]";     \
        fprintf(logf, "%s " fmt "\n", prefix, ##__VA_ARGS__);                  \
    } while (0)

#define logInfo(fmt, ...)                                                      \
    do {                                                                       \
        const char* const restrict prefix =                                    \
            is_log_color_support ? "\x1b[1;32m[Info]\x1b[0m" : "[Info]";       \
        fprintf(logf, "%s " fmt "\n", prefix, ##__VA_ARGS__);                  \
    } while (0)

#define logWarning(fmt, ...)                                                   \
    do {                                                                       \
        const char* const restrict prefix =                                    \
            is_log_color_support ? "\x1b[1;33m[Warning]\x1b[0m" : "[Warning]"; \
        fprintf(logf, "%s " fmt "\n", prefix, ##__VA_ARGS__);                  \
    } while (0)

#define logError(fmt, ...)                                                     \
    do {                                                                       \
        const char* const restrict prefix =                                    \
            is_log_color_support ? "\x1b[1;31m[Error]\x1b[0m" : "[Error]";     \
        fprintf(logf, "%s " fmt "\n", prefix, ##__VA_ARGS__);                  \
    } while (0)
//
