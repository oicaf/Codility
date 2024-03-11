/*
Task: https://app.codility.com/programmers/lessons/11-sieve_of_eratosthenes/count_non_divisible/
Score: https://app.codility.com/demo/results/training383WN2-KQR/

Algorithm:
1. Create an auxiliary array that counts the occurrences of each element in the array.
2. For each element of the array, find the number of its divisors, including divisors resulting from 
division.
3. Subtracting the total number of divisors for a given element from the total number of elements in 
the array.
*/

#include <stdlib.h>

struct Results solution(int A[], int N)
{
    int i, j, div_sum = 0;
    int *count = (int*)calloc(2 * N + 1, sizeof(int));
    int *C = (int*)malloc(N * sizeof(int));
    struct Results result;

    for (i = 0; i < N; i++)
        count[A[i]]++;

    for (i = 0; i < N; i++)
    {
        for (j = 1; j * j <= A[i]; j++)
        {
            if (A[i] % j == 0)
            {
                if (A[i] != 1)
                {
                    if (j != A[i] / j)
                        div_sum += count[j] + count[A[i] / j];
                    else
                        div_sum += count[j];
                }
                else
                    div_sum = count[j];
            }
        }
        C[i] = N - div_sum;
        div_sum = 0;
    }
    result.C = C;
    result.L = N;

    return result;
}
