// WAP to represent the polynomial of single variable using 1-D array and perform the addition of two polynomial equations.

#include <stdio.h>
#include <stdlib.h>

typedef int (*IntArray2Ptr)[2]; //{{max_degree,non-zero_coefficient},{degree,coefficient}}

void print_poly(int arr[][2])
{
    int degree = arr[0][0], n = arr[0][1];
    for (int i = n; i > 0; i--) // greater than 0, since arr[0] is storing polynomial information (max_degree, o_of_non-zero_coefficient)
    {
        if (arr[i][0] == 0)
        {
            printf("%d", arr[i][1]); // Use arr[i][0] as the degree
        }
        else if (arr[i][0] == 1)
        {
            printf("%dx", arr[i][1]); // Use arr[i][0] as the degree
        }
        else
        {
            printf("%dx^%d", arr[i][1], arr[i][0]); // Use arr[i][0] as the degree
        }
        if (i != 1)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

IntArray2Ptr input_polynomial()
{
    int degree, temp_coefcnt;

    printf("Enter maximum degree of x : ");
    scanf("%d", &degree);

    IntArray2Ptr polynomial = malloc((degree + 2) * sizeof(int[2])); // +2 for {{max_degree,no_of_non-zero_coefficient},{0,constant},...}

    if (polynomial == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    polynomial[0][0] = degree;
    polynomial[0][1] = 0; // number of non-zero coefficient
    printf("Enter Polynomial from lowest degree to highest degree : 4 2 3 (Hint: 4+2x+3x^2): ");

    for (int i = 0; i <= degree; i++)
    {
        scanf("%d", &temp_coefcnt);
        if (temp_coefcnt != 0)
        {
            polynomial[polynomial[0][1] + 1][0] = i;
            polynomial[polynomial[0][1] + 1][1] = temp_coefcnt;
            polynomial[0][1]++;
        }
    }

    polynomial = realloc(polynomial, (polynomial[0][1] + 1) * sizeof(int[2]));

    if (polynomial == NULL)
    {
        perror("Memory re-allocation failed");
        exit(EXIT_FAILURE);
    }

    return polynomial;
}

IntArray2Ptr sum_polynomial(int poly1[][2], int poly2[][2])
{
    int degree = poly1[0][0] > poly2[0][0] ? poly1[0][0] : poly2[0][0];
    IntArray2Ptr sum_poly = malloc((degree + 2) * sizeof(int[2]));

    int index1 = 1, index2 = 1, index_sp = 1;
    for (int i = 0; i <= degree; i++)
    {
        sum_poly[0][1] = index_sp;

        if (poly1[index1][0] == i && poly2[index2][0] == i)
        {
            sum_poly[index_sp][0] = i;
            sum_poly[index_sp][1] = poly1[index1][1] + poly2[index2][1];

            index1++;
            index2++;
            index_sp++;
        }
        else if (poly1[index1][0] == i)
        {
            sum_poly[index_sp][0] = i;
            sum_poly[index_sp][1] = poly1[index1][1];

            index1++;
            index_sp++;
        }
        else if (poly2[index2][0] == i)
        {
            sum_poly[index_sp][0] = i;
            sum_poly[index_sp][1] = poly2[index2][1];

            index2++;
            index_sp++;
        }
    }
    return sum_poly;
}

int main()
{
    IntArray2Ptr poly1 = input_polynomial(), poly2 = input_polynomial();

    IntArray2Ptr sum = sum_polynomial(poly1, poly2);
    if (sum == NULL)
    {
        printf("Failed to do addition.");
    }
    else
    {
        printf("\nSum of p1 and p2 is : \n");
        print_poly(sum);
    }

    return 0;
}