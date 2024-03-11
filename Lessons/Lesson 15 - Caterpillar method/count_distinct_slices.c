
/*
Task: https://app.codility.com/programmers/lessons/15-caterpillar_method/count_distinct_slices/
Score: https://app.codility.com/demo/results/trainingBVBSEH-4EA/

Algorithm:
1. The start starts with zero back (rear of the caterpillar) and front (front of the caterpillar).
2. The front increases by 1 in search of a duplicate (the back remains unchanged) and if it does not 
find a duplicate, it's over (maximum extreme case).
3. When there are only duplicates (min extreme case = length of the array), the front increases by 1 
and the back also increases by 1 reaching the front every time.
4. When the front encounters a duplicate anywhere, the back feeds to the front.
5. When the back follows the front, it clears a handy table (count) for duplicate control each time.
*/

#include <stdlib.h>

int solution(int M, int A[], int N)
{
	int back = 0, front = 0;
	long int result = 0;
	int *count = (int*)calloc(M + 1, sizeof(int));

	while (front < N)
	{
		while (front < N && count[A[front]] == 0)
		{
			count[A[front]] += 1;
			result += (front - back + 1);
			front++;
		}
		
		while (back < N && front < N && count[A[front]] != 0)
		{
			count[A[back]] = 0;
			back++;
		}
	}
	free(count);

	if (result > 1000000000)
		return 1000000000;

	return result;
}
