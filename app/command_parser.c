#include "command_parser.h"
#include <stdint.h>
#include <stdbool.h>

static char command_buffer[32];
static uint8_t index;
static bool command_ready;
static bool overflow_flag;

void parser_init(void)
{
    index = 0;
    command_ready = false;
    overflow_flag = false;
}

bool parser_process_byte(char c)
{
    if(command_ready)
    {
        return false;
    }

    /* Overflow mode: ignore everything until newline */
    if(overflow_flag)
    {
        if(c == '\n')
        {
            overflow_flag = false;
            index = 0;
        }

        return false;
    }

    /* Command complete */
    if(c == '\n')
    {
        command_buffer[index] = '\0';
        command_ready = true;
        return true;
    }

    /* Store normal character */
    if(index < sizeof(command_buffer) - 1)
    {
        command_buffer[index++] = c;
    }
    else
    {
        overflow_flag = true;
    }

    return false;
}

bool parser_get_command(char *dest)
{
    if(!command_ready)
    {
        return false;
    }

    uint8_t i = 0;

    while(command_buffer[i] != '\0')
    {
        dest[i] = command_buffer[i];
        i++;
    }

    dest[i] = '\0';

    command_ready = false;
    index = 0;

    return true;
}