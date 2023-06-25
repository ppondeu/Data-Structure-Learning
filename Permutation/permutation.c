#include <stdio.h>

int check(char data[], int idx, char ch)
{
    int i = 0;
    while (i < idx)
    {
        if (data[i] == ch)
        {
            return 0;
        }
        ++i;
    }
    return 1;
}

void permutation(char data[], int idx, int N)
{
    if (idx == N)
    {
        data[N] = '\0';
        printf("%s\n", data);
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (check(data, idx, 'A' + i))
        {
            data[idx] = ('A' + i);
            permutation(data, idx + 1, N);
        }
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    char data[N + 1];

    permutation(data, 0, N);

    return 0;
}