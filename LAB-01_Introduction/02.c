// WAP to store n book’s data (title, author, publication, price etc.) using structures with dynamic memory allocation. Display all the books information of a particular author.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book_info
{
    char title[100];
    char auther[100]; // pre define length, otherwise memory overflow
    char publication[100];
    float price;
};

int main()
{
    int n, i, count;
    char auther[100];
    printf("Enter the no. of Book : ");
    scanf("%d", &n);

    struct book_info *book_list = (struct book_info *)malloc(n * sizeof(struct book_info));

    for (i = 0; i < n; i++)
    {

        printf("Title of book %d : ", i + 1);
        scanf(" %99[^\n]%*c", ((book_list + i)->title));
        printf("Auther of book %d : ", i + 1);
        scanf(" %99[^\n]%*c", ((book_list + i)->auther));
        printf("Publication of book %d : ", i + 1);
        scanf(" %99[^\n]%*c", ((book_list + i)->publication));
        printf("Price of book %d : ", i + 1);
        scanf("%f", &((book_list + i)->price));
    }

    printf("Enter the auther to search : ");
    scanf(" %99[^\n]%*c", auther);

    for (i = 0; i < n; i++)
    {
        if (strcmp(auther, (book_list + i)->auther) == 0)
        {
            printf("Title - %s\nAuther - %s\nPublicaton - %s\nPrice - %.2f\n\v", (book_list + i)->title, (book_list + i)->auther, (book_list + i)->publication, (book_list + i)->price);
            count++;
        }
    }
    if (count == 0)
    {
        printf("No match found.\n");
    }

    free(book_list);

    return 0;
}