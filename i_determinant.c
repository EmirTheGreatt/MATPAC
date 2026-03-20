#include "matrix.h"
#include <math.h>
#include <stddef.h>

/* ---------- swap (INT version) ---------- */
static void swap_int(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* ---------- reverse ---------- */
static void reverse(int arr[], size_t start, size_t end)
{
    while (start < end)
    {
        swap_int(&arr[start], &arr[end]);
        start++;
        end--;
    }
}

/*
 * Returns:
 *   +1 → next permutation exists and is even
 *   -1 → next permutation exists and is odd
 *    0 → no next permutation
 */
static int next_perm(size_t n, int arr[])
{
    if (n < 2)
        return 0;

    int i = (int)n - 2;
    while (i >= 0 && arr[i] >= arr[i + 1])
        i--;

    if (i < 0)
        return 0;

    int j = (int)n - 1;
    while (arr[j] <= arr[i])
        j--;

    swap_int(&arr[i], &arr[j]);

    size_t k = n - (i + 1);
    int swaps = 1 + (k / 2);

    reverse(arr, i + 1, n - 1);

    return (swaps % 2 == 0) ? 1 : -1;
}

/* ---------- determinant ---------- */
double i_determinant(Matrix *M)
{
    if (M->rows != M->cols)
        return NAN;

    size_t n = M->rows;

    int perm[n];
    for (size_t i = 0; i < n; i++)
        perm[i] = i;

    double result = 0.0;

    int parity = 1;  // <-- initialize BEFORE loop

    while (1)
    {
        double term = 1.0;

        for (size_t i = 0; i < n; i++)
            term *= get_coeff(M, i, perm[i]);

        result += parity * term;

        parity = next_perm(n, perm);
        if (parity == 0)
            break;
    }

    return result;
}