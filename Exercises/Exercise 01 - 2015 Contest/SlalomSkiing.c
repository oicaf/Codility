/*
Task: https://app.codility.com/programmers/trainings/1/slalom_skiing/
Score: https://app.codility.com/demo/results/trainingSTU3TM-ES9/

Strategy:
The LIS (Longest Increasing Subsequence) method was used here in a modified version for the task.
*/

#include <stdio.h>
#include <stdlib.h>

int lower_bound(long long int *tails, int size, long long int x) {
    int left = 0, right = size, mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (x < tails[mid])
            right = mid - 1;
        else if (x > tails[mid])
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int solution(int A[], int N) {
    int i, j = 0, max = 0, len = 0, pos;
    long long int *T = malloc((3 * N) * sizeof(long long int));
    long long int *tails = malloc((3 * N + 1) * sizeof(long long int));

    for (i = 0; i < 3 * N + 1; i++)
        tails[i] = -1;

    for (i = 0; i < N; i++)
        max = A[i] > max ? A[i] : max;
    max = max + 1;

    for (i = 0; i < N; i++) {
        T[j++] = 2 * max + A[i];
        T[j++] = 2 * max - A[i];
        T[j++] = A[i];
    }

    tails[0] = -1;
    for (i = 0; i < 3 * N; i++) {
        pos = lower_bound(tails, len, T[i]);
        if (tails[pos] == -1) {
            tails[pos] = T[i];
            len++;
        }
        else
            tails[pos] = (tails[pos] < T[i]) ? tails[pos] : T[i];
    }

    free(T);
    free(tails);
    return len;
}
