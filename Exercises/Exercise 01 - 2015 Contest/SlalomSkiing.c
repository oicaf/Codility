/*
Task: https://app.codility.com/programmers/trainings/1/slalom_skiing/
Score: https://app.codility.com/demo/results/training4PRU7Q-SWD/

Strategy:
The LIS (Longest Increasing Subsequence) method was used here in a modified version for the task.
*/

#include <stdio.h>
#include <stdlib.h>

int lower_bound(long long int *tails, int size, long long int x) {
    int left = 0, right = size, mid;

    while (left < right) {
        mid = left + (right - left) / 2;
        if (tails[mid] >= x)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int solution(int A[], int N) {
    int i, j = 0, max = 0, len = 0, pos;
    long long int *T = malloc((3 * N) * sizeof(long long int));
    long long int *tails = malloc((3 * N) * sizeof(long long int));

    for (i = 0; i < N; i++)
        max = A[i] > max ? A[i] : max;
    max = max + 1;

    for (i = 0; i < N; i++) {
        T[j++] = 2 * max + A[i];
        T[j++] = 2 * max - A[i];
        T[j++] = A[i];
    }

for (i = 0; i < 3 * N; i++) {
    pos = lower_bound(tails, len, T[i]);
    tails[pos] = T[i];
    if (pos == len)
        len++;
}

    free(T);
    free(tails);
    return len;
}
