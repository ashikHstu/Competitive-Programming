#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int n;
    scanf("%d", &n);
    int ar[n * 2 + 3][n * 2 + 3];
    int total = n * 2 - 1;
    int st = 1;
    int ed = n * 2 - 1;
    for (int i = n; i >= 1; i--)
    {
        for (int j = st; j <= ed; j++)
            ar[st][j] = i;

        for (int j = st; j <= ed; j++)
            ar[j][st] = i;
        for (int j = st; j <= ed; j++)
            ar[j][ed] = i;
        for (int j = st; j <= ed; j++)
            ar[ed][j] = i;

        st++;
        ed--;
    }
    for (int i = 1; i <= total; i++)
    {
        for (int j = 1; j <= total; j++)
            printf("%d ", ar[i][j]);
        printf("\n");
    }
    return 0;
}