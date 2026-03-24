/*
Task: https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/flags/
Score: https://app.codility.com/demo/results/training7BN39P-HRE/

Strategy:
1. Finding all peaks.
Traverse the array and record the indices of elements that are greater than their neighbors.
2. Estimating the maximum number of flags.
The maximum number of flags ≈ the square root of the distance between the first and last peak.
3. Testing from the maximum number of flags downward.
For each possible number of flags, K, check whether they can be set.
4. Greedy flag setting.
- the first flag on the first peak,
- subsequent flags only if they are ≥ K away from the last flag,
5. Returning the first working K.
The first number of flags that can be set is the result.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int solution(int A[], int N) {
    int i;
    
    int peaks = 0;
    int *P = malloc((N / 2) * sizeof(int));
    for (i = 1; i < N - 1; i++) {
        if (A[i - 1] < A[i] && A[i] > A[i + 1]) {
            P[peaks] = i;
            peaks++;
        }
    }
    if (peaks < 2)
        return peaks;

    int max_flags = ceil(sqrt(P[peaks - 1] - P[0]));
    while (1) {
        int flags = 1;
        int last = P[0];
        for (i = 1; i < peaks; i++) {
            if (abs(last - P[i]) >= max_flags) {
                flags++;
                last = P[i];
                if (flags == max_flags) {
                    free(P);
                    return flags;
                }
            }
        }
        max_flags--;
    }
}
