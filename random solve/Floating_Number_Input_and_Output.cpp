
#include <stdio.h>

int main()
{

    float a, b;
    float c, d;

    scanf("%f %f", &a, &b);
    scanf("%f %f", &c, &d);

    printf("A = %.6f, B = %.6f\n", a, b); // 7
    printf("C = %.6f, D = %.6f\n", c, d); // 8
    printf("A = %.1f, B = %.1f\n", a, b); // 9
    printf("C = %.1f, D = %.1f\n", c, d); // 10
    printf("A = %.2f, B = %.2f\n", a, b); // 11
    printf("C = %.2f, D = %.2f\n", c, d); // 12
    printf("A = %.3f, B = %.3f\n", a, b); // 13
    printf("C = %.3f, D = %.3f\n", c, d); // 14
    printf("A = %.3E, B = %.3E\n", a, b); // 15
    printf("C = %.3E, D = %.3E\n", c, d); // 16
    printf("A = %.0f, B = %.0f\n", a, b); // 17
    printf("C = %.0f, D = %.0f\n", c, d); // 18
}