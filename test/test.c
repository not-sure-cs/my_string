#include<stdio.h>
#include "my_string.h"

int main()
{
    char* string1 = "What the fuck isHapenning";
    char* string2 = "What the fuck is hapEnning";
    int n = my_strlen(string1);
    if(my_is_empty(string2) == true)
        printf("Empty\n");

    else
        printf("Not Empty\n");
    
    printf("Length = %d\n", n);

    int m = my_strcasecmp(string1, string2);
    printf("R = %d\n", m);
    return 0;
}

