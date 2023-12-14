// WAP to store one student’s information (i.e. student’s roll no, name, gender, marks etc) of an educational institute and display all the data, using structure (Access the structure members using pointer).

#include <stdio.h>
#include <stdlib.h>

struct stud_info
{
    int roll;
    char name[100]; // pre define length, otherwise memory overflow
    char gender[7];
    float marks;
};

int main()
{
    int n, i;

    // printf("Enter the no. of students : ");
    // scanf("%d",&n);
    n = 1;
    i = 0;
    struct stud_info *st_list = (struct stud_info *)malloc(n * sizeof(struct stud_info));

    printf("Enter detail of student in format Roll, Name, Gender, Marks :\n");

    // for (i = 0; i<n; i++){

    // printf("Roll_no. of student %d : ",i+1);
    scanf("%d", &((st_list + i)->roll)); // pattern, regex from python
    // printf("Name of student %d : ",i+1);
    scanf(" %99[^\n]%*c", ((st_list + i)->name));
    // printf("Gender of student %d : ",i+1);
    scanf(" %6[^\n]%*c", ((st_list + i)->gender));
    // printf("Marks of student %d : ",i+1);
    scanf("%f", &((st_list + i)->marks));
    // }

    printf("Rollno - %d, Name - %s, Gender - %s, Marks - %.2f\n", st_list->roll, st_list->name, st_list->gender, st_list->marks);

    free(st_list);

    return 0;
}

// ctrl+shift+I refactor = formating