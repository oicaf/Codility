/*
Task: https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/
Score: https://app.codility.com/demo/results/trainingJ27H48-WUC/

Algorithm:
Using the XOR operator through all elements of the array, extracting one unpaired element which is the result.
*/

#include <stdio.h>

int solution(int A[], int N)
{
    int result = A[0];

    if (N == 1)
        return result;

    for (int i = 1; i < N; i++)
        result ^= A[i];

    return result;
}

void main()
{
    int A[] = {9, 3, 9, 3, 9, 7, 9}, N = sizeof(A) / sizeof(A[0]);

    printf("%d\n", solution(A, N));
}