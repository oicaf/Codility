/*
Task: https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium
Score: https://app.codility.com/demo/results/training9RGMZQ-47Z/
*/

#include <stdlib.h>

int solution(int A[], int N)
{
	int i, tmp, leftSum = 0, rightSum = 0, result = 2000;
  
	for (i = 0; i < N; i++)
		rightSum += A[i];

	for (i = 0; i < N-1; i++)
	{
		leftSum += A[i];
		rightSum -= A[i];
		tmp = abs(leftSum - rightSum);
		
		if(tmp < result)
			result = tmp;
	}
	
	return result;
}
