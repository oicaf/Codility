/*
Task: https://app.codility.com/programmers/lessons/16-greedy_algorithms/tie_ropes/
Score: https://app.codility.com/demo/results/trainingF6ZXWB-FHV/

Algorithm:
1. Checking whether the length of a single rope or subsequent ropes is >= K:
- if so, move on to the next rope, etc.,
- if not, attach another rope and check if the sum is >= K etc.
2. If the sum of the lengths of a single rope or subsequent ropes >= K, the rope counter is increased by 1.
*/

int solution(int K, int A[], int N)
{
	int i = 0, j, sum = 0, ropes = 0;
	
	if (N == 1)
	{
		if (A[i] >= K)
			return ropes = 1;
		else
			return ropes;
	}
	
	while (i < N)
	{
		if (A[i] >= K)
		{
			ropes++;
			i++;
		}
		else
		{
			j = i + 1;
			
			if (j == N)
				sum = A[i];
			else
				sum += A[i] + A[j];
			
			while (j < N - 1 && sum < K)
			{
				j++;
				sum += A[j];
			}
			
			if (sum >= K)
				ropes++;
			
			i = j + 1;
			sum = 0;
		}
	}
	
	return ropes;
}
