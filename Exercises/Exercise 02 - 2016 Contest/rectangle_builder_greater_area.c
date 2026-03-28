/*
Task: https://app.codility.com/programmers/trainings/2/rectangle_builder_greater_area/
Score: https://app.codility.com/demo/results/trainingCQMQSP-TWT/

Strategy:
1. Sort the array using an algorithm with a time complexity of at most O(N * log(N)) in the worst case, because other
algorithms that can have a time complexity of O(N**2) in special cases generate TIMEOUTs for very large arrays.
2. Create an auxiliary array consisting only of usable elements, i.e., elements that have at least two identical
elements (pair) from which a fence can be built (two opposite sides).
3. Use the Binary Search algorithm to find the second pair of identical elements that fulfills task assumption.
4. If there are at least four identical elements (two identical pairs) at the same index, the result is immediately
incremented by 1 (square fence), for rectangular fences, Binary Search is used.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void merge(int array[], int left, int mid, int right) {
    int i, j;

    int *temp_L = malloc(((mid - left + 1) + 1) * sizeof(int));
    int *temp_R = malloc(((right - mid) + 1) * sizeof(int));

    for (i = 0; i < mid - left + 1; i++)
        temp_L[i] = array[left + i];

    for (i = 0; i < right - mid; i++)
        temp_R[i] = array[mid + 1 + i];

    temp_L[mid - left + 1] = INT_MAX;
    temp_R[right - mid] = INT_MAX;
    i = j = 0;

    for (int k = left; k <= right; k++) {
        if (temp_L[i] <= temp_R[j])
            array[k] = temp_L[i++];
        else
            array[k] = temp_R[j++];
    }
}

void merge_sort(int array[], int left, int right) {
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    merge_sort(array, left, mid);
    merge_sort(array, mid + 1, right);

    merge(array, left, mid, right);
}

int solution(int A[], int N, int X) {
    int i;

    if (N < 4)
        return 0;

    merge_sort(A, 0, N-1);

    int *usable_pairs = malloc((N + 1) * sizeof(int));
    int size = 0, pens = 0, pieces = 1;

    for (i = 1; i < N; i++) {
        if (A[i] == A[i-1])
            pieces++;
        if (A[i] != A[i-1] || (i == N-1)) {
            if (pieces < 2)
                continue;
            else if (pieces < 4)
                usable_pairs[size++] = A[i-1];
            else {
                usable_pairs[size++] = A[i-1];
                if ((long)A[i-1] * A[i-1] >= X)
                    pens++;
            }
            pieces = 1;
        }
    }

    int left, right, mid = 0;
    for (int x = 0; x < size - 1; x++) {
        left = x + 1;
        right = size - 1;
        while (left <= right) {
            mid = (left + right) / 2;
            if ((long)usable_pairs[x] * usable_pairs[mid] >= X)
                right = mid - 1;
            else
                left = mid + 1;
        }

        pens += size - (right + 1);
        if (pens > 1000000000) {
            free(usable_pairs);
            return -1;
        }
    }

    free(usable_pairs);
    return pens;
}
