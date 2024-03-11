/*
Task: https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_profit/
Score: https://app.codility.com/demo/results/training7HD25B-M4N/

Algorithm:
1. Linearly comparing O(N) adjacent elements and calculating their profit.
2. Profits and losses add up.
3. If, as a result of the calculations, the value is <= zero, it is reset to zero because we are counting/looking for the maximum possible profit.
4. The greatest profit that occurred is always remembered.
*/

int solution(int A[], int N)
{
	int i, max_profit = 0, result = 0;
	
	if (N == 1)
		return 0;
	
	for (i = 1; i < N; i++)
	{
		if (A[i] - A[i - 1] > 0)
			max_profit = max_profit + (A[i] - A[i - 1]);
		else
		{
			if (A[i - 1] - A[i] >= max_profit)
				max_profit = 0;
			else
				max_profit = max_profit - (A[i - 1] - A[i]);
		}
		result = (max_profit > result) ? max_profit : result;
	}
	
	if (result <= 0)
		return 0;
	else
		return result;
}
