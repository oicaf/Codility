/*
Task: https://app.codility.com/programmers/lessons/11-sieve_of_eratosthenes/count_semiprimes/
Score: https://app.codility.com/demo/results/trainingPEHRHX-9ZX/

Algorithm:
1. Creating an auxiliary array where the composite number has an element with the value 1.
2. On the same table, separating/leaving only 'semiprimes', values = 1.
3. Based on the above table, create a new table with prefix sums (summing only ones and zeros).
4. For each query, in the interval a...b, based on the sum of prefixes, calculating the difference in 
the given slice.
*/

#include <stdlib.h>
#include <math.h>

struct Results solution(int N, int P[], int Q[], int M)
{
    int i, F[N + 1], k, j = 2, S[N + 2];
    int* A = (int*) malloc((M + 1) * sizeof(int));
    struct Results result;

    for(i = 0; i <= N; i++)
        F[i] = 0;

    for(i = 0; i <= N + 1; i++)
        S[i] = 0;    
 
    i = 2;
    while(i * i <= N)
    {
        if(F[i] == 0)
        {
            k = i * i;
            while(k <= N)
            {
                if(F[k] == 0)
                    F[k] = 1;
                k += i;
            }
        }

        i++;
    }

    for(i = N; i >= 8; i--)
    {
        while(F[i] > 0)
        {
            if(i % j == 0)
            {                   
                if(F[i / j] == 1)
                {
                    F[i] = 0;
                    j = 2;
                    break;
                }
                else
                {
                    j = 2;   
                    break;
                }
            }
            else
            {
                while(F[++j] > 0) {}
                if(j > sqrt(i))
                    break;
            }
        }
    }

    for(i = 0; i <= N; i++)
        S[i + 1] = S[i] + F[i];

    for(k = 0; k < M; k++)
    {
        if(Q[k] >= 4)
        {
            if(P[k] < 4)
                P[k] = 4;
        }

        A[k] = S[Q[k] + 1] - S[P[k]];
    }

    result.A = A;
    result.M = M;

    return result;
}
