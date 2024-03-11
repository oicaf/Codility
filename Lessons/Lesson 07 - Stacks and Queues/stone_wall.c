/*
Task: https://app.codility.com/programmers/lessons/7-stacks_and_queues/stone_wall/
Score: https://app.codility.com/demo/results/trainingN66A8B-J3F/

Algorithm:
1. Using a stack to store heights that are less than the current height.
2. The rectangle ends when the top of the stack is equal to the current height.
*/

#include <stdlib.h>

int solution(int H[], int N)
{
    int size = 0, blocks = 0;
    int *stack = (int*)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
    {
        while (size != 0 && H[i] < stack[size - 1])
            size--;

        if (size != 0 && H[i] == stack[size - 1])
            continue;
        else
        {
            stack[size] = H[i];
            size++;
            blocks++;
        }
    }
    free(stack);

    return blocks;
}
