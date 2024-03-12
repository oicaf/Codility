/*
Task: https://app.codility.com/programmers/task/increasing_sequences/
Score: https://app.codility.com/demo/results/trainingTYQABM-RJU/

Algorithm:
Going first from the beginning of the array to the end and then vice versa and the smaller value / 
counter wins.
*/

#include <stdlib.h>

int solution(int A[], int B[], int N)
{
    int i, count_L = 0, count_R = 0, temp;
    int *copy_A = (int*)malloc(N * sizeof(int));
    int *copy_B = (int*)malloc(N * sizeof(int));

    for (i = 0; i < N; i++)
    {
        copy_A[i] = A[i];
        copy_B[i] = B[i];
    }

    for (i = 1; i < N; i++)
    {
        if (copy_A[i] > copy_A[i - 1] && copy_B[i] > copy_B[i - 1])
            continue;
        else if ((copy_A[i] <= copy_A[i - 1] && copy_A[i] <= copy_B[i - 1]) || (copy_B[i] <= copy_B[i - 1] && copy_B[i] <= copy_A[i - 1]))
            return -1;
        else
        {
            temp = copy_A[i];
            copy_A[i] = copy_B[i];
            copy_B[i] = temp;
            count_L++;
        }
    }

    if (count_L == 0)
        return 0;

    for (i = 0; i < N; i++)
    {
        copy_A[i] = A[i];
        copy_B[i] = B[i];
    }

    for (i = N - 2; i >= 0; i--)
    {
        if (copy_A[i] < copy_A[i + 1] && copy_B[i] < copy_B[i + 1])
            continue;
        else if ((copy_A[i] >= copy_A[i + 1] && copy_A[i] >= copy_B[i + 1]) || (copy_B[i] >= copy_B[i + 1] && copy_B[i] >= copy_A[i + 1]))
            return -1;
        else
        {
            temp = copy_A[i];
            copy_A[i] = copy_B[i];
            copy_B[i] = temp;
            count_R++;
        }            
    }

    return (count_L < count_R) ? count_L : count_R;
}
