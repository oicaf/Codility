/*
Task: https://app.codility.com/programmers/lessons/4-counting_elements/frog_river_one/
Score: https://app.codility.com/demo/results/trainingJVJXVW-Z4U/
*/

#include <stdlib.h>

int solution(int X, int A[], int N)
{
	int i, j, result = -1;
	int *count = (int*)malloc((X + 1) * sizeof(int));

	if (N < X)
		return result;

	for (i = 0; i <= X; i++)
		count[i] = 0;
	
	for (i = 0; i < N; i++)
	{
		count[A[i]] += 1;
		result = i;
		
		for (j = 1; j <= X; j++)
		{
			if (i < X - 1 || count[j] == 0) 
			{
				result = -1;
				break;
			}
		}
		if (result != -1)
			return result = i;
	}

	free(count);
	return result;
}
