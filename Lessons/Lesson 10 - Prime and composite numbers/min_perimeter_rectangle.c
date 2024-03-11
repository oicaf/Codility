/*
Task: https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/min_perimeter_rectangle/
Score: https://app.codility.com/demo/results/trainingNJ3AQ3-3NA/
*/

#include <math.h>

int solution(int N)
{
	int i, result;
	long int min_perimeter = 2000000002;
	
	for (i = 1; i <= sqrt(N); i++)
	{
		if (N % i == 0)
		{
			result = 2 * (i + N / i);
			min_perimeter = (result < min_perimeter) ? result: min_perimeter;
		}
	}

	return min_perimeter;
}
