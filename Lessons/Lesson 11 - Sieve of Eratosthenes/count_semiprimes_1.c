/*
Task: https://app.codility.com/programmers/lessons/11-sieve_of_eratosthenes/count_semiprimes/
Score: https://app.codility.com/demo/results/training3ZJDVQ-69A/

Algorithm:
1. Creating an auxiliary 'primes' array where elements with a value of 0 are prime numbers and elements 
with a value > 0 are composite numbers, and a number greater than zero is also the first smallest 
divisor of a given composite number.
2. Creating an auxiliary array 's_primes', based on the previous 'primes' array, containing only 
"semi-prime" elements, in addition, this array contains an additional element = 0 as the first with 
index '0' and element = 50000 as the last with index ' size', both for the proper operation of the 
program (extreme margins closing the range of "semi-prime" numbers).
3. Scanning each query (query) in turn, determining the starting and ending indexes in the s_primes 
array on based on the given range from...to in each query.
4. The difference between the final index (end) and the starting index (start) determines the number 
of "semi-first" elements in a given query (query).
*/

#include <stdlib.h>

struct Results solution(int N, int P[], int Q[], int M)
{
    int i, j, size = 1, start = 0, end = -1;
    int *primes = (int*)calloc(N + 1, sizeof(int));
    int *s_primes = (int*)calloc(N, sizeof(int));
    int *A = (int*)malloc(M * sizeof(int));
    struct Results result;

    i = 2;
    while (i * i <= N)
    {
        if (primes[i] == 0)
        {
            j = i * i;
            while (j <= N)
            {
                if (primes[j] == 0)
                    primes[j] = i;
                j += i;
            }
        }
        i++;
    }

    for (i = 4; i <= N; i++)
    {
        if (primes[i] > 0)
            if (primes[i / primes[i]] == 0)
            {
                s_primes[size] = i;
                size++;
            }
    }
    s_primes[size] = 50000;

    for (i = 0; i < M; i++)
    {
        j = 1;
        while (j <= size)
        {
            if (P[i] <= s_primes[j])
            {
                start = j;
                break;
            }
            j++;
        }

        j = size - 1;
        while (j >= 0)
        {
            if (Q[i] >= s_primes[j])
            {
                end = j;
                break;
            }
            j--;
        }

        A[i] = end - start + 1;
    }
    result.A = A;
    result.M = M;
    free(primes);
    free(s_primes);

    return result;
}
