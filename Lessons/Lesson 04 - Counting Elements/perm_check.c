/*
Task: https://app.codility.com/programmers/lessons/4-counting_elements/perm_check/
Score: https://app.codility.com/demo/results/trainingE4HRCH-952/
*/

#include <stdlib.h>

int solution(int A[], int N)
{
	int i, result;
	int *count = (int*)malloc((N + 1) * sizeof(int));

	for (i = 0; i <= N; i++)
		count[i] = 0;
	
	for (i = 0; i < N; i++)
	{
		if (A[i] > N)								
			return result = 0;
		else
			count[A[i]] += 1;
	}
	
	for (i = 1; i <= N; i++)
	{
		if (count[i] == 0)
			return result = 0;
	}

	free(count);
	return result = 1;
}
