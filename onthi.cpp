#include <stdio.h>
#include <malloc.h>

typedef int keytype;
typedef float othertype;
typedef struct
{
    keytype key;
    othertype other;
} banghi;

void swap(banghi *x, banghi *y)
{
    banghi temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void read_file(banghi x[], int *n)
{
    FILE *f;
    int i = 0;
    f = fopen("data.txt", "r");
    if (f != NULL)
    {
        while (!feof(f))
        {
            fscanf(f, "%d%f", &x[i].key, &x[i].other);
            i++;
        }
    }
    else
        printf("Loi mo file!\n");

    fclose(f);
    *n = i;
}

int findpivot(banghi x[], int i, int j)
{
    int k;
    keytype firstkey;
    k = i + 1;
    firstkey = x[i].key;
    while ((k <= j) && (x[k].key == firstkey))
        k++;
    if (k > j)
        return -1;
    else if (x[k].key > firstkey)
        return k;
    else
        return i;
}
int partition(banghi x[], int i, int j, keytype pivot)
{
    int L = i;
    int R = j;
    while (L <= R)
    {
        while (x[L].key < pivot)
            L++;
        while (x[R].key >= pivot)
            R--;
        if (L < R)
            swap(&x[L], &x[R]);
    }
    return L;
}
void Quick_Sort(banghi x[], int i, int j)
{
    int k, ip;
    keytype p;
    ip = findpivot(x, i, j);
    if (ip != -1)
    {
        p = x[ip].key;
        k = partition(x, i, j, p);
        Quick_Sort(x, i, k - 1);
        Quick_Sort(x, k, j);
    }
}
void print_data(banghi x[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%3d%5d%8.2f\n", i + 1, x[i].key, x[i].other);
    }
}
int main()
{
    banghi x[100];
    int n;
    read_file(x, &n);
    printf("Du lieu truoc khi sap xep\n");
    print_data(x, n);
    Quick_Sort(x, 0, n - 1);
    printf("Du lieu sau khi sap xep\n");

    print_data(x, n);
    return 0;
}