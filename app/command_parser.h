#include<stdbool.h>
void parser_init(void);
bool parser_process_byte(char c);
bool parser_get_command(char *dest);
