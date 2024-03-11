/*
Task: https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_double_slice_sum/
Score: https://app.codility.com/demo/results/trainingXQ3V7K-MAC/
*/

int solution(int A[], int N)
{
    int i, max_left_sum[N], max_right_sum[N], max_double_sum, result = 0;

	max_left_sum[0] = 0;
    for (i = 1; i < N - 1; i++)
    {
        if (A[i] + max_left_sum[i - 1] < 0)
            max_left_sum[i] = 0;
        else
            max_left_sum[i] = A[i] + max_left_sum[i - 1];
    }
    max_left_sum[i] = 0;

	max_right_sum[N - 1] = 0;
    for (i = N - 2; i > 0; i--)
    {
        if (A[i] + max_right_sum[i + 1] < 0)
            max_right_sum[i] = 0;
        else
            max_right_sum[i] = A[i] + max_right_sum[i + 1];
    }
    max_right_sum[i] = 0;

    for (i = 1; i < N - 1; i++)
    {
        max_double_sum = max_left_sum[i - 1] + max_right_sum[i + 1];
        result = (max_double_sum > result) ? max_double_sum : result;
    }

	return result;
}
