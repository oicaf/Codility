/*
Task: https://app.codility.com/programmers/lessons/14-binary_search_algorithm/nailing_planks/
Score: https://app.codility.com/demo/results/trainingNFSD4N-M74/

Algorithm:
1. The strategy is to first sort the boards and then scan the nails and do the following:
- for each nail perform a binary search for a board,
- if a board is found, pierce the board (remove the boards from boards A and B), and then search again 
until the nail no longer hits the boards,
2. The list of boards should decrease until it reaches zero, which means that we have found the minimum 
number of nails needed.
3. If there are any boards left, return -1.
*/

#include <string.h>

void removeElement(int arr[], int size, int indexToRemove)
{
    int *src = &arr[indexToRemove + 1];
    int *dest = &arr[indexToRemove];
    int elementsToMove = size - indexToRemove - 1;

    memmove(dest, src, elementsToMove * sizeof(int));
}

void quick_sort(int A[], int B[], int left, int right)
{
    int i = left;
    int j = right;
    int x = A[(left + right) / 2];
    do
    {
        while (A[ i ] < x)
             i++;
       
        while (A[ j ] > x)
             j--;
       
        if (i <= j)
        {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;

            temp = B[i];
            B[i] = B[j];
            B[j] = temp;                    
           
            i++;
            j--;
        }

    } while (i <= j);
   
    if (left < j)
        quick_sort(A, B, left, j);
    if(right > i)
        quick_sort(A, B, i, right);
}

int solution(int A[], int B[], int N, int C[], int M)
{
    int nail_idx, nail_min = 2 * M + 1, nail_max = 0, beg, mid, end;
    
    quick_sort(A, B, 0, N - 1);

    for (nail_idx = 0; nail_idx < M; nail_idx++)
    {
        nail_min = (C[nail_idx] < nail_min) ? C[nail_idx]: nail_min;
        nail_max = (C[nail_idx] > nail_max) ? C[nail_idx]: nail_max;
    }
    if (nail_max < A[0] || nail_min > B[N - 1])
        return -1;

    for (nail_idx = 0; nail_idx < M; nail_idx++)
    {
        while (1)
        {
            beg = 0;
            end = N - 1;
            while (beg <= end)
            {
                mid = (beg + end) / 2;
                if (C[nail_idx] >= A[mid] && C[nail_idx] <= B[mid])
                {
                    removeElement(A, N, mid);
                    removeElement(B, N, mid);
                    N--;
                    if (N == 0)
                        return nail_idx + 1;
                    break;
                }
                else if (C[nail_idx] < A[mid])
                    end = mid - 1;
                else
                    beg = mid + 1;
            }
            if (beg > end)
                break;
        }
    }

    return -1;
}
