/*
Task: https://app.codility.com/programmers/lessons/7-stacks_and_queues/brackets/
Score: https://app.codility.com/demo/results/training5VUJVD-ZH6/
*/

#include <string.h>
#include <stdlib.h>

int solution(char *S)
{
	int i, j, N = strlen(S), size = 0;
	char ref[] = {'(', '{', '[', ']', '}', ')'};
	int *stack = (int*)malloc(N * sizeof(int));
	
	if (N == 0)
		return 1;
	
	if (N % 2 == 1)
		return 0;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < 6; j++)
		{
			if (S[i] == ref[j])
			{
				if (j <= 2)
				{
					stack[size] = S[i];
					size++;
					break;
				}
				else
				{
					size--;
					if (size < 0)
						return 0;
					
					switch(S[i])
					{
						case ']': if (stack[size] != '[')
									return 0;
									break;
						case '}': if (stack[size] != '{')
									return 0;
									break;
						case ')': if (stack[size] != '(')
									return 0;
									break;
					}
				}
			}
		}
	}
	free(stack);
	
	if (size != 0)
    return 0;
	else
		return 1;
}
