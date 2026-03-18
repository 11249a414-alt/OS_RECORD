#include <stdio.h>

int main()
{
    int nb, np, i, j;
    int b[10], p[10], alloc[10];
    int min, pos;

    printf("Enter number of blocks: ");
    scanf("%d", &nb);

    printf("Enter size of each block:\n");
    for (i = 0; i < nb; i++)
        scanf("%d", &b[i]);

    printf("Enter number of processes: ");
    scanf("%d", &np);

    printf("Enter size of each process:\n");
    for (i = 0; i < np; i++)
        scanf("%d", &p[i]);

    for (i = 0; i < np; i++)
        alloc[i] = -1;

    for (i = 0; i < np; i++) {
        min = 9999;
        pos = -1;
        for (j = 0; j < nb; j++) {
            if (b[j] >= p[i] && b[j] < min) {
                min = b[j];
                pos = j;
            }
        }
        if (pos != -1) {
            alloc[i] = pos;
            b[pos] -= p[i];
        }
    }

    printf("\nProcess\tSize\tBlock\n");
    for (i = 0; i < np; i++) {
        if (alloc[i] != -1)
            printf("P%d\t%d\t%d\n", i + 1, p[i], alloc[i] + 1);
        else
            printf("P%d\t%d\tNot Allocated\n", i + 1, p[i]);
    }

    return 0;
}