/*
Task: https://app.codility.com/programmers/task/array_closest_ascenders/
Score: https://app.codility.com/demo/results/trainingEJCG3Z-CMH/
*/

#include <stdlib.h>
#include <math.h>

struct Results solution(int A[], int N)
{
    int i, j, dist;
    int *R = (int*)malloc(N * sizeof(int));
    struct Results result;

    if (N == 0)
    {
        result.R = A;
        result.N = N;
        return result;
    }

    for (i = 0; i < N; i++)
    {
        dist = N;
        for (j = 0; j < N; j++)
        {
            if (A[j] > A[i])
            {
                if (abs(j - i) == 1)
                {
                    dist = 1;
                    break;
                }
                else
                {
                    dist = (abs(j - i) < dist) ? abs(j - i) : dist;
                    if (j - i > 0)
                        break;
                }
            }
        }
        R[i] = (dist == N) ? 0 : dist;
    }

    result.R = R;
    result.N = N;
    return result;
}
