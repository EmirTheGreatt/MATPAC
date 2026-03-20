#include "matrix.h"
#include <math.h>

static void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

static void reverse(int arr[], size_t start, size_t end)
{
    while (start < end)
    {
        swap(&arr[start], &arr[end]);
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

    // Step 1: find pivot
    int i = (int)n - 2;
    while (i >= 0 && arr[i] >= arr[i + 1])
        i--;

    if (i < 0)
        return 0;

    // Step 2: find successor
    int j = (int)n - 1;
    while (arr[j] <= arr[i])
        j--;

    // Step 3: swap
    swap(&arr[i], &arr[j]);

    // Step 4: reverse suffix
    reverse(arr, i + 1, n - 1);

    // --- Compute parity ---
    size_t k = n - (i + 1);   // length of suffix
    int swaps = 1 + (k / 2);  // 1 (swap) + swaps from reversing

    if (swaps % 2 == 0)
        return 1;
    else
        return -1;
}
double  i_determinant(Matrix *M)
{
	if (M -> rows != M -> cols)
		return NAN;
	size_t n = M -> rows;
	int perm[n];
	for (int i = 0; i < n; i++)
		perm[i] = i;
	double to_be_returned = 0;
	double to_be_added = 1;
	for (int parity = 1; parity = next_perm(n, perm); parity)
	{
		for (size_t i = 0; i < n; i++)
			to_be_added *= get_coeff(M, i, perm[i]) * parity;
	}
	return to_be_returned;
}