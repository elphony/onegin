#ifndef PARSE_CMD_ARG_H
#define PARSE_CMD_ARG_H

#include <stddef.h>
#include <string.h>

struct Command {
    const char* com;
    int flag;
};

int parse_cmd_line(const char* string_cmd, const Command options[], size_t len);

#endif // PARSE_CMD_ARG_H