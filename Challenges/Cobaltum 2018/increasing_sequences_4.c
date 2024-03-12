/*
Task: https://app.codility.com/programmers/task/increasing_sequences/
Score: https://app.codility.com/demo/results/trainingUSK7N4-KYM/

Algorithm:
Traversing the array from beginning to end and if swapping places is necessary to meet the conditions, 
the array is modified at a given index and the replacement counter is increased by 1. Finally, the counter 
value is subtracted from the array length (inversion) and this value is compared with the current value 
replacement counter where the final result is a smaller value.
*/

#include <stdlib.h>

int solution(int A[], int B[], int N)
{
    int i, count = 0, temp;

    for (i = 1; i < N; i++)
    {
        if (A[i] > A[i - 1] && B[i] > B[i - 1])
            continue;
        else if (A[i] > B[i - 1] && B[i] > A[i - 1])
        {
            temp = A[i];
            A[i] = B[i];
            B[i] = temp;
            count++;
        }
        else
            return -1;
    }

    return (N - count < count) ? N - count : count;
}
