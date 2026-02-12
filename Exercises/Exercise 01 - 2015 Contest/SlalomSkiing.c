/*
Task: https://app.codility.com/programmers/trainings/1/slalom_skiing/
Score: https://app.codility.com/demo/results/trainingJGRS7E-435/

Strategy:
The LIS (Longest Increasing Subsequence) method has been used with some modifications/adaptations.
*/

#include <stdio.h>
#include <stdlib.h>

int binary_search(long long int *dp, int size, long long int x) {
    int left = 0, right = size, mid;

    while (left < right) {
        mid = (left + right) / 2;
        if (x > dp[mid])
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int solution(int A[], int N) {
    int i, j = 0, max = 0, len = 0, pos;
    long long int *triple = malloc((3 * N) * sizeof(long long int));
    long long int *dp = malloc(N * sizeof(long long int));

    for (i = 0; i < N; i++)
        max = A[i] > max ? A[i] : max;

    for (i = 0; i < N; i++) {
        triple[j++] = (long long int)2 * max + A[i];
        triple[j++] = 2 * max - A[i];
        triple[j++] = A[i];
    }

    for (i = 0; i < 3 * N; i++) {
        pos = binary_search(dp, len, triple[i]);
        dp[pos] = triple[i];
        if (pos == len)
             len++;
    }

    free(triple);
    free(dp);
    return len;
}
