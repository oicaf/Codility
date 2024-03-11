/*
Task: https://app.codility.com/programmers/lessons/7-stacks_and_queues/nesting/
Score: https://app.codility.com/demo/results/training237NTJ-AF5/
*/

#include <string.h>
#include <stdlib.h>

int solution(char *S)
{
	int i, N = strlen(S), size = 0;
	int *stack = (int*)malloc(N * sizeof(int));
	
	if (N == 0)
		return 1;
	
	if (N % 2 == 1)
		return 0;

	for (i = 0; i < N; i++)
	{
		if (S[i] == '(')
		{
			stack[size] = S[i];
			size++;
		}
		else
		{
			size--;
			if (size < 0)
				return 0;

			if (stack[size] != '(')
				return 0;
		}
	}
	free(stack);	

	if (size != 0)
		return 0;
	else
		return 1;
}
