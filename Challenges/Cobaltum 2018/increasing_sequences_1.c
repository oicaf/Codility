/*
Task: https://app.codility.com/programmers/task/increasing_sequences/
Score: https://app.codility.com/demo/results/trainingQHRR9S-RU2/

Algorithm:
Using dynamic programming (DP table) and constantly updating the indexes of the DP table depending on 
the number of needed changes on the same indexes between table A and B, 0 = no replacement, 
1 = replacement, scanning performed from end to end and from end to beginning , the smallest number of 
necessary replacements wins.
*/

#include <stdlib.h>

int solution(int A[], int B[], int N)
{
    int i, j, count_L = 0, count_R = 0;
    int *DP = (int*)calloc(N, sizeof(int));

    for (i = 1; i < N; i++)
    {
        if (A[i] > A[i - 1] && B[i] > B[i - 1])
            continue;
        else if ((A[i] <= A[i - 1] && A[i] <= B[i - 1]) || (B[i] <= B[i - 1] && B[i] <= A[i - 1]))
            return -1;
        else
        {
            DP[i - 1] = 1;
            for (j = i - 1; j > 0; j--)
            {
                if (DP[j] == DP[j - 1])
                    if (A[j] > A[j - 1] && B[j] > B[j - 1])
                        continue;
                    else if (A[j] > B[j - 1] && B[j] > A[j - 1])
                        DP[j - 1] = (DP[j - 1] + 1) % 2;
                    else return -1;
                else
                    if (A[j] > B[j - 1] && B[j] > A[j - 1])
                        continue;
                    else if (A[j] > A[j - 1] && B[j] > B[j - 1])
                        DP[j - 1] = (DP[j - 1] + 1) % 2;
                    else return -1;
            }
        }
    }

    for (i = 0; i < N; i++)
        if (DP[i] == 1)
            count_L++;

    if (count_L == 0)
        return 0;

    for (i = 0; i < N; i++)
        DP[i] = 0;

    for (i = N - 2; i >= 0; i--)
    {
        if (A[i] < A[i + 1] && B[i] < B[i + 1])
            continue;
        else if ((A[i] >= A[i + 1] && A[i] >= B[i + 1]) || (B[i] >= B[i + 1] && B[i] >= A[i + 1]))
            return -1;
        else
        {
            DP[i + 1] = 1;
            for (j = i + 1; j < N - 1; j++)
            {
                if (DP[j] == DP[j + 1])
                    if (A[j] < A[j + 1] && B[j] < B[j + 1])
                        continue;
                    else if (A[j] < B[j + 1] && B[j] < A[j + 1])
                        DP[j + 1] = (DP[j + 1] + 1) % 2;
                    else return -1;
                else
                    if (A[j] < B[j + 1] && B[j] < A[j + 1])
                        continue;
                    else if (A[j] < A[j + 1] && B[j] < B[j + 1])
                        DP[j + 1] = (DP[j + 1] + 1) % 2;
                    else return -1;
            }
        }
    }

    for (i = 0; i < N; i++)
        if (DP[i] == 1)
            count_R++;       

    return (count_L < count_R) ? count_L : count_R;
}
