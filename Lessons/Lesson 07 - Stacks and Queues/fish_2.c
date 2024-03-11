/*
Task: https://app.codility.com/programmers/lessons/7-stacks_and_queues/fish/
Score: https://app.codility.com/demo/results/training5VDK63-QB9/

The algorithm consists in linearly comparing each fish from A, along with its direction B, to the current 
fish in the stack. It is on the stack always the most current (survived the previous fight) fish to be 
compared with the next one from A. If the stack is reset to zero, it means that there is a survivor. 
The sum of survivors and the size of the stack is the final result.
*/

#include <stdlib.h>

int solution(int A[], int B[], int N)
{
	int i, survivors = 0, size = 0;
  	int *stack = (int*)malloc(N * sizeof(int));

	for (i = 0; i < N; i++)
	{
		if (B[i] == 0)
		{
			while (size != 0)
			{
				if (stack[size] > A[i])
					break;
        		else
					size--;
      		}
			if (size == 0)
				survivors++;
    	}
		else
			stack[++size] = A[i];
    }
	free(stack);
	return survivors + size;
}
