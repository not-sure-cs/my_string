#include <stdbool.h>
#include <ctype.h>
#include "my_string.h"

//core string inspection

int my_strlen(const char* string)
{
    int n = 0;

    while(string[n] != '\0')
    {
        n++;
    }

    return n;
}

int my_strnlen(const char* string, const int max_len)
{
    int n = 0;

    while(string[n] != '\0' && n <= max_len)
    {
        n++;
    }

    return n;
}

bool my_is_empty(const char* string)
{
    const char* s = string;
    if (*s == '\0')
        return true;

    else
        return false;
    
}

//comparison and ordering

int my_strcmp(const char *str1, const char *str2)
{
    const char *ptr1 ,*ptr2;
    int n = 0;

    for(ptr1 = str1, ptr2 = str2; *ptr1 != '\0' && *ptr2 != '\0' ; ptr1++, ptr2++)
    {
        if(*ptr1 == *ptr2)
        {
            const char *p1 = ptr1 + 1, *p2 = ptr2 +1;
            n = 0;
            if( *p1 == '\0' && *p2 != '\0')
                
                n = -1;
            
            else if( *p2 == '\0' && *p1 != '\0')

                n = 1;
        
            continue;
        }
        else if((*ptr1 - *ptr2) > 0)
        {
            n = 1;
            break;
        }
        else if((*ptr1 - *ptr2) < 0)
        {
            n = -1;
            break;
        }
    }

    return n;
}

int my_strncmp(const char *str1, const char *str2, const int max_len)
{
    const char *ptr1 ,*ptr2;
    int n = 0, count = 0;

    for(ptr1 = str1, ptr2 = str2; *ptr1 != '\0' && *ptr2 != '\0' && count <= max_len ; ptr1++, ptr2++)
    {
        if(*ptr1 == *ptr2)
        {
            const char *p1 = ptr1 + 1, *p2 = ptr2 +1;
            n = 0;
            if( *p1 == '\0' && *p2 != '\0')
                
                n = -1; 
            
            else if( *p2 == '\0' && *p1 != '\0')

                n = 1;
        
            continue;
        }
        else if((*ptr1 - *ptr2) > 0)
        {
            n = 1;
            break;
        }
        else if((*ptr1 - *ptr2) < 0)
        {
            n = -1;
            break;
        }
    }

    return n;
}

int my_strcasecmp(const char *str1, const char *str2)
{
    const char *ptr1 ,*ptr2;
    int plow1, plow2;
    int n = 0;

    for(ptr1 = str1, ptr2 = str2; *ptr1 != '\0' && *ptr2 != '\0' ; ptr1++, ptr2++)
    {
        plow1 = tolower(*ptr1);
        plow2 = tolower(*ptr1);

        if(plow1 == plow2)
        {
            const char *p1 = ptr1 + 1, *p2 = ptr2 +1;
            n = 0;
            if( *p1 == '\0' && *p2 != '\0')
                
                n = -1;
            
            else if( *p2 == '\0' && *p1 != '\0')

                n = 1;
        
            continue;
        }
        else if((plow1 - plow2) > 0)
        {
            n = 1;
            break;
        }
        else if((plow1 - plow2) < 0)
        {
            n = -1;
            break;
        }
    }

    return n;
}

bool my_streq(const char *a, const char *b)
{
    if(my_strcmp(a, b) == 0)
        return true;

    else
        return false;
}

