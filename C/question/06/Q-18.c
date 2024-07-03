#include <stdio.h>
#include <stdlib.h>

int compare_ints(const void *a, const void *b) 
{
    int int_a = *(int *)a;
    int int_b = *(int *)b;
    
    if (int_a < int_b) return -1;
    else if (int_a > int_b) return 1;
    else return 0;
}

static void swap(void *a, void *b, size_t size) 
{
    unsigned char *p = a, *q = b, tmp;
    for (size_t i = 0; i < size; i++) 
    {
        tmp = p[i];
        p[i] = q[i];
        q[i] = tmp;
    }
}

static void q_sort_recursive(void *base, size_t size, int (*compar)(const void *, const void *), int left, int right) 
{
    if (left >= right)
        return;

    void *pivot = base + left * size;
    int i = left;
    int j = right;

    while (i < j) 
    {
        while (i < right && compar(base + i * size, pivot) <= 0)
            i++;

        while (j > left && compar(base + j * size, pivot) > 0)
            j--;

        if (i < j)
            swap(base + i * size, base + j * size, size);
    }

    swap(base + left * size, base + j * size, size);

    q_sort_recursive(base, size, compar, left, j - 1);
    q_sort_recursive(base, size, compar, j + 1, right);
}

void q_sort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *)) 
{
    if (nmemb < 2 || size == 0)
        return;
    q_sort_recursive(base, size, compar, 0, nmemb - 1);
}

int main() 
{
    int arr[] = {5, 3, 8, 6, 2, 7, 4, 1};
    size_t arr_size = sizeof(arr) / sizeof(arr[0]);

    q_sort(arr, arr_size, sizeof(int), compare_ints);

    for (size_t i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    putchar('\n');

    return 0;
}
