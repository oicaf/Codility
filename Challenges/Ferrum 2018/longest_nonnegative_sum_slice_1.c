/*
Task: https://app.codility.com/programmers/task/longest_nonnegative_sum_slice/
Score: https://app.codility.com/demo/results/training9DBMCF-TZM/

Algorithm:
"Caterpillar" method used.
*/

#include <stdio.h>

int solution(int A[], int N)
{
    int total_sum = 0, tail = 0, head = 0, sum = 0, slice = 0, result = 0;

    for (int i = 0; i < N; i++)
        total_sum += A[i];

    if (total_sum >= 0)
        return N;

    while (head < N)
    {
        sum += A[head];
        if (sum < 0)
        {
            if (A[head + 1] == -1 || head + 1 == N)
            {
                total_sum -= A[tail];
                sum -= A[tail];
                tail++;
                if (total_sum >= 0)
                    return N - tail;
            }
        }
        else
        {
            slice = head - tail + 1;
            result = (slice > result) ? slice : result;
        }
        
        head++;
    }

    return result;
}

void main()
{
    int A[] = {-1, -1, 1, -1, 1, 0, 1, -1, -1}; // 7
    //int A[] = {1, 1, -1, -1, -1, -1, -1, 1, 1}; // 4
	//int A[] = {0, -1, 0, 0, 1, 0, -1, -1}; // 6    
    //int A[] = {-1, -1, 1, 1, -1, -1}; // 4
    //int A[] = {-1, -1, 1, 1}; // 4
    //int A[] = {-1, -1}; // 0
    //int A[] = {0, -1}; // 1
    //int A[] = {-1, 0}; // 1
    //int A[] = {1, -1}; // 2
    //int A[] = {-1, 1}; // 2
    //int A[] = {-1, -1, -1}; // 0
    //int A[] = {1, 0, -1}; // 
    int N = sizeof(A) / sizeof(A[0]);

    printf("%d\n", solution(A, N));
}
