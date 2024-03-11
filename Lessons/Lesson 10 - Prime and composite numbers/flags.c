/*
Task: https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/flags/
Score: https://app.codility.com/demo/results/trainingVSQ2M2-C55/

Algorithm:
1. Creating an auxiliary array with the number of all peaks, where the elements of the array denote the 
peak number.
2. The initial assumption is that the maximum number of flags that can be placed on the peaks is equal 
to the square root of the difference between the value of the last peak and the first peak + 1.
3. Scanning the peak table by verifying the distance between peaks vs the initial number of flags to be 
placed.
4. If after each iteration the initial number of possible flags is not equal to the currently maximum 
number of flags, then the maximum number of flags is reduced by 1, etc.
*/

#include <stdlib.h>
#include <math.h>

int solution(int A[], int N)
{
    int i, peaks = 0, flags = 1, dist = 0, max_flags;
    int *P = (int*)malloc((N / 2) * sizeof(int));

    for (i = 1; i < N - 1; i++)
    {
        if (A[i - 1] < A[i] && A[i] > A[i + 1])
        {
            P[peaks] = i;
            peaks++;
        }
    }

    if (peaks < 2)
        return peaks;

    max_flags = sqrt(P[peaks - 1] - P[0]) + 1;
        
    while (1)
    {
        for (i = 1; i < peaks; i++)
        {
            dist = dist + (P[i] - P[i - 1]);
            if (dist >= max_flags)
            {
                flags++;
                dist = 0;
                if (flags == max_flags)
                    return max_flags;
            }
        }

        flags = 1;
        max_flags--;
    }
}
