/*
Task: https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/peaks/
Score: https://app.codility.com/demo/results/training2865UT-CAM/

Algorithm:
1. Creating an array/equivalent of the same length for the input containing only 0 and 1 where 1 means 
the top.
2. The initial max number of blocks is equal to the number of peaks.
3. A more accurate number of max blocks (for verification) results from the operation of calculating the 
remainder of dividing the array length by a more accurate max number of blocks.
4. Each block is scanned individually for the occurrence of at least one peak and if so, the result is 
equal to the currently specified maximum number of blocks.
5. If there is no peak in any of the blocks, the maximum number of blocks to be verified is reduced by 1 
and so on until successful.
6. When the maximum number of blocks is reduced by 1, the remainder of the division is always checked 
as in point 3.
7. The operation of calculating the remainder of division as in points 3 and 6 is necessary to create 
blocks of the same size.
*/

#include <stdbool.h>

int solution(int A[], int N)
{
    int i, peaks = 0, max_blocks, start_block, peak_found = false, peak_count = 0;
    int *P = (int*)malloc(N * sizeof(int));

    P[0] = 0;
    for (i = 1; i < N - 1; i++)
    {
        if (A[i -1] < A[i] && A[i] > A[i + 1])
        {
            P[i] = 1;
            peaks++;
        }
        else
            P[i] = 0;
    }
    P[N - 1] = 0;

    if (peaks == 0)
        return 0;

    max_blocks = peaks;
    while (N % max_blocks != 0)
        max_blocks--;

    if (max_blocks == 1)
        return 1;

    while (max_blocks > 1)
    {
        start_block = 0;
        while (start_block < N)
        {
            for (i = start_block; i < N / max_blocks + start_block; i++)
            {
                if (P[i] == 1)
                {
                    peak_found = true;
                    peak_count++;
                    break;
                }
            }

            if (peak_found != true)
            {
                peak_found = false;
                peak_count = 0;
                break;
            }
            
            peak_found = false;
            start_block += N / max_blocks;
        }

        if (max_blocks == peak_count)
            break;
        else
            while (N % --max_blocks != 0) {}
    }

    return max_blocks;
}
