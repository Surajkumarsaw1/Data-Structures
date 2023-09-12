#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, len;
    char *strptr = (char *)malloc(100 * sizeof(char));

    printf("Enter a string : ");
    scanf(" %99[^\n]%*c", strptr);

    for (i = 0; i < 100; i++)
    {
        if (*(strptr + i) == '\0')
        {
            break;
        }
        else
        {
            len++;
        }
    }
    printf("Length of string : %d\n", len);
    free(strptr);
    return 0;
}