#include <stdio.h>
#include <string.h>
int main()
{
    char st[20003];
    int shift;
    scanf("%s", st);
    scanf("%d", &shift);
    int len = strlen(st);
    for (int i = 0; i < len; i++)
    {
        int cur = st[i] - 'a';
        cur += shift;
        cur %= 26;
        st[i] = cur + 'a';
    }
    printf("%s\n", st);

    return 0;
}