/*
Task: https://app.codility.com/programmers/task/longest_nonnegative_sum_slice/
Score: https://app.codility.com/demo/results/trainingFZH8E5-8TZ/

Algorithm:
Array scan by usage of "Brute Force" method.
*/

int solution(int A[], int N)
{
    int i, j, slice = 0, max_slice = 0;

    int sum = A[0];
    for (i = 1; i < N; i++)
        sum += A[i];

    if (sum >= 0)
        return N;

    for (i = 0; i < N; i++)
    {
        sum = 0;
        for (j = i; j < N; j++)
        {
            sum += A[j];
            if (sum >= 0)
            {
                slice = j - i + 1;
                max_slice = (slice > max_slice) ? slice : max_slice;
            }
        }
    }

    return max_slice;
}
