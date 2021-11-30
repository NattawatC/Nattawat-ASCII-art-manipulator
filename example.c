#include <stdio.h>
#include <string.h>

input = strtok(input_buffer, "\n ")
while (input != NULL)
{
    printf("%s", input);
    input = strtok(NULL, "\n");
}
printf("\n");