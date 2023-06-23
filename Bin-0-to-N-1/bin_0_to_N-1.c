#include <stdio.h>

void bin_bits(int n, char bin[], int i)
{
    if (i == n)
    {   
        bin[n] = '\0';
        printf("%s\n", bin);
        return;
    }
    bin[i] = '0';
    bin_bits(n, bin, i + 1);
    bin[i] = '1';
    bin_bits(n, bin, i + 1);
}
int main()
{
    int n;
    scanf("%d", &n);
    char bin[n + 1];
    bin_bits(n, bin, 0);
    return 0;
}