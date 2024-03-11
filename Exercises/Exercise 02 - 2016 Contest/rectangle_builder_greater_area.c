/*
Task: https://app.codility.com/programmers/trainings/2/rectangle_builder_greater_area/
Score: https://app.codility.com/demo/results/trainingZYJRH6-2PY/

Algorithm:
1. Counting the occurrences of elements in the input array and saving the results in an auxiliary array 
(the number of each item).
2. Building another auxiliary board consisting only of elements to be used, i.e. those that have at 
least two identical elements (a pair) from which you can initially build a fence (two opposite sides).
3. Using the binary search algorithm to find a second pair of identical elements that meets the task 
assumption (>=X) where the first pair (multiplier x) is scanned in the main loop linearly from the 
beginning to the penultimate element of the array. After determining both pairs (x and, by default, y) 
that meet the task requirement, the number of remaining elements of the array (the next second pairs) is 
deducted (from this point) as they also/all the more meet the requirements as the array is sorted in 
ascending order.
4. If there are at least four identical elements (two pairs) under the same index, the result is immediately 
increased by 1 for such cases (square fence) and in the rest of the code where binary search is used, 
only rectangular fences are determined.
*/

#include <stdlib.h>

int solution(int A[], int N, int X)
{
    int i, max = 0, pens = 0, x, left, mid = 0, right;

    if (N < 4)
        return 0;

    for (i = 0; i < N; i++)
        max = A[i] > max ? A[i] : max;

    char *pieces = (char*)calloc(max + 1, sizeof(char));

    for (i = 0; i < N; i++)
        pieces[A[i]]++;

    int *usable_pairs = (int*)calloc(N + 1, sizeof(int));        

    int size = 0;
    for (i = 1; i <= max; i++)
    {
        if (pieces[i] < 2)
            continue;
        else if (pieces[i] < 4)
            usable_pairs[size++] = i;
        else
        {
            usable_pairs[size++] = i;
            if ((long)i * i >= X)
                pens++;
        }
    }

    free(pieces);

    for (x = 0; x < size - 1; x++)
    {
        left = x + 1;
        right = size - 1;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if ((long)usable_pairs[x] * usable_pairs[mid] >= X)
                right = mid - 1;
            else
                left = mid + 1;
        }

        pens += size - (right + 1);
        if (pens > 1000000000)
        {
            free(usable_pairs);
            return -1;
        }
    }

    free(usable_pairs);
    return pens;
}
