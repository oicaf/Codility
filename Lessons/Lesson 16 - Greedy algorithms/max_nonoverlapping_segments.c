/*
Task: https://app.codility.com/programmers/lessons/16-greedy_algorithms/max_nonoverlapping_segments/
Score: https://app.codility.com/demo/results/training38J3KJ-T8A/

Algorithm:
1. Check if segment 0 and 1 overlap:
- if so, increase the counter of overlapping segments by 1 and check whether segment 0 and 2 overlap, etc.,
- if not, check whether segment 1 and 2 overlap, etc.
2. The final result is the difference between the maximum number (that can be achieved) of non-overlapping 
segments and the number of overlapping segments.
*/

int solution(int A[], int B[], int N)
{
	int i = 0, j, overlapp = 0, max = N;
	
	while (i < N - 1)
	{
		j = i + 1;
		while (j < N && ((A[i] <= A[j] && A[j] <= B[i]) || (A[j] <= A[i] && A[i] <= B[j])))
		{
			overlapp++;
			j++;
		}
		i = j;
	}

	return max - overlapp;
}

