#include <stdio.h>
void shell_sort(int l[], int n)
{
    int gap = n / 2;
    while (gap > 0)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = l[i], j = i;
            while (j >= gap && l[j - gap] > temp)
            {
                l[j] = l[j - gap];
                j -= gap;
            }
            l[j] = temp;
        }
        gap /= 2;
    }
}
int main()
{
    int l[] = {12, 34, 54, 2, 3};
    int n = sizeof(l) / sizeof(l[0]);
    shell_sort(l, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", l[i]);
    }
    return 0;
}

void insertion_sort(int l[], int len)
{
    int i, j, key;
    for (i = 1; i < len; i++)
    {
        key = l[i];
        j = i - 1;
        while ((j >= 0) && (l[j] > key))
        {
            l[j + 1] = l[j];
            j--;
        }
        l[j + 1] = key;
    }
}