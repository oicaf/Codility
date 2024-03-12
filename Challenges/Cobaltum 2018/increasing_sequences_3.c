/*
Task: https://app.codility.com/programmers/task/increasing_sequences/
Score: https://app.codility.com/demo/results/trainingFSSDCF-KSG/

Algorithm:
Using dynamic programming and constantly updating (dynamically) the DP table with replacement operations 
on given indexes.
*/

#include <stdlib.h>

int solution(int A[], int B[], int N)
{
    int i, j, count = 0, result = 0;
    int *DP = (int*)calloc(N, sizeof(int));

    for (i = 1; i < N; i++)
    {
        if (DP[i - 1] == 0)
        {
            if (A[i] > A[i - 1] && B[i] > B[i - 1])
                continue;
            else if (A[i] > B[i - 1] && B[i] > A[i - 1])
            {
                DP[i] = 1;
                count++;
                if (count > result && (i + 1 - count) < count)
                {
                    for (j = i; j >= 0; j--)
                        DP[j] = (DP[j] + 1) % 2;
                }
                count = i + 1 - count;
                result = count;
            }
            else
                return -1;
        }
        else // DP[i - 1] == 1
        {
            if (A[i] > B[i - 1] && B[i] > A[i - 1])
                continue;
            else if (A[i] > A[i - 1] && B[i] > B[i - 1])
            {
                DP[i] = 1;
                count++;
                if (count > result && (i + 1 - count) < count)
                {
                    for (j = i; j >= 0; j--)
                        DP[j] = (DP[j] + 1) % 2;
                }
                count = i + 1 - count;
                result = count;
            }
            else
                return -1;
        }
    }

    return (N - result < result) ? N - result : result;
}
