/*
Task: https://app.codility.com/programmers/lessons/4-counting_elements/max_counters/
Score: https://app.codility.com/demo/results/trainingNDJTAR-RKR/

Algorithm:
1. Resetting the counting array C.
2. Counting elements from array A to counting array C.
3. Current calculation of the maximum achieved max_counter.
4. If any element from the array A > N (N + 1) then the minimum counter level is reset to the maximum counter level.
5. Current comparison of the table C counter with the current minimum counter level (after reset) and, depending on the case:
- increase the current counter of array C by the minimum counter level + 1 or
- increasing the current counter of the C array by 1
6. Finally, review the entire array C and supplement the missing (not previously processed) counters with the value of the current minimum counter level.
*/

#include <stdlib.h>

struct Results solution(int N, int A[], int M)
{
    int i, min_counter = 0, max_counter = 0;
    int *C = (int*)malloc(N * sizeof(int));
    struct Results result;

    for (i = 0; i < N; i++)
        C[i] = 0;

    for (i = 0; i < M; i++)
    {
        if (A[i] > N)
            min_counter = max_counter;
        else
        {
            if (C[A[i] - 1] <= min_counter)
                C[A[i] - 1] = min_counter + 1;
            else
                C[A[i] - 1]++;
                        
            if (C[A[i] - 1] > max_counter)
                max_counter = C[A[i] - 1];
        }
    }

    for (i = 0; i < N; i++)
        if (C[i] < min_counter)
            C[i] = min_counter;

    result.C = C;
    result.L = N;
    return result;
}
