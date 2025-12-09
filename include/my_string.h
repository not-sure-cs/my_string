#ifndef _MY_STRING_H
#define _MY_STRING_H

#include <stdbool.h>
#include <ctype.h>

int my_strlen(const char* string);
int my_strnlen(const char* string, const int max_len);
bool my_is_empty(const char* string);
int my_strcmp(const char *str1, const char *str2);
int my_strncmp(const char *str1, const char *str2, const int max_len);
int my_strcasecmp(const char *str1, const char *str2);
bool my_streq(const char *a, const char *b);

#endif