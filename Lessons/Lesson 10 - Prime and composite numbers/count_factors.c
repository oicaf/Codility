/*
Task: https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/count_factors/
Score: https://app.codility.com/demo/results/trainingP8CKNQ-TQS/
*/

#include <math.h>

int solution(int N)
{
	int i = 1, factors = 0;
	
	if (N == 1)
		return factors = 1;
	
	while (i < sqrt(N))
	{
		if (N % i == 0)
			factors += 2;
		i++;
	}
	if (i == sqrt(N))
		factors += 1;
	
	return factors;
}

