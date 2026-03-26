/*
Task: https://app.codility.com/programmers/trainings/4/first_unique/
Score: https://app.codility.com/demo/results/trainingEEEW9C-NW8/

Strategy:
1. Create pairs: (value, index).
2. Sort the data (pairs) by value.
3. Group the pairs: unique pairs first.
4. Iterate through only the unique pairs, finding the one with the smallest index.
5. Return the result from the original array.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int ind;
} pair;

void quick_sort(pair array[], int left, int right) {
    int i = left;
    int j = right;
    pair x = array[(left + right) / 2];

    do {
        while (array[i].val < x.val)
            i++;
        while (array[j].val > x.val)
            j--;

        if (i <= j) {
            pair temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }

    } while (i <= j);

    if (left < j)
        quick_sort(array, left, j);
    if (i < right)
        quick_sort(array, i, right);
}

int solution(int A[], int N) {
    int i;

    if (N == 1)
        return A[0];
    if (N == 2)
        return (A[0] == A[1]) ? -1 : A[0];

    pair *arr = malloc(N * sizeof(pair));

    for (i = 0; i < N; i++) {
        arr[i].val = A[i];
        arr[i].ind = i;
    }

    quick_sort(arr, 0, N - 1);

    int index = -1;
    pair tmp;

    if (arr[0].val != arr[1].val)
        index++;

    for (i = 1; i < N-1; i++) {
        if ((arr[i].val != arr[i-1].val) && (arr[i].val != arr[i+1].val)) {
            index++;
            tmp = arr[index];
            arr[index] = arr[i];
            arr[i] = tmp;
        }
    }

    if (arr[N-2].val != arr[N-1].val) {
        index++;
        tmp = arr[index];
        arr[index] = arr[N-1];
        arr[N-1] = tmp;
    }

    if (index == -1) {
        free(arr);
        return -1;
    }

    if (index == 0)
        return arr[0].val;

    int result = N;
    for (i = 0; i <= index; i++)
        result = (arr[i].ind < result) ? arr[i].ind : result;

    free(arr);
    return A[result];
}
