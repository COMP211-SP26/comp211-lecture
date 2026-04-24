#ifndef SCANNER_H
#define SCANNER_H

char** scan_line(char* line, int* token_count);
void free_string_array(char** strings, int count);

#endif