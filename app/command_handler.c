#include<string.h>
#include<stdbool.h>
bool command_execute(const char *cmd)
{
    if(strcmp(cmd, "STATUS") == 0)
    {
        return true;
    }

    if(strcmp(cmd, "HELP") == 0)
    {
        return true;
    }

    return false;
}