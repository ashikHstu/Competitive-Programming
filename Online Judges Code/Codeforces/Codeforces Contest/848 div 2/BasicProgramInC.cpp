#include <stdio.h>
int main()
{
    // int -> %d
    // double -> %lf
    // char -> %c
    // string -> %s

    double a;
    printf("Enter the value of a : ");
    scanf("%lf", &a);
    printf("The value of a is : %.2lf\n", a);

    return 0;
}