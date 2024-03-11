/*
Task: https://app.codility.com/programmers/lessons/7-stacks_and_queues/fish/
Score: https://app.codility.com/demo/results/trainingSSZN99-BBM/

Algorithm:
1. If fish swim against the current (0) and do not encounter others swimming in the opposite direction (1) 
that are larger than them, the survivors counter is increased, the number of which indicates the number 
of such fish.
2. If fish swim with the current (1) and do not encounter others swimming in the opposite direction (0) 
that are larger than them, the pile is increased, the size of which indicates the number of such fish.
3. The final result is the sum of survivors and the size of the stack.
4. If two fish swimming in the opposite direction (towards each other) meet, then:
- if the fish swimming with the current wins (1), it stays in the stack and is ready to fight the next 
fish swimming towards it and if he wins along the way with everyone, then it ends,
- if the fish swimming against the current wins (0), it continues to fight with others swimming towards 
it (removed from the stack) and if the stack is empty (size = 0) and there are no more fish to fight, 
the survivors counter is increased by 1,
*/

#include <stdlib.h>

int solution(int A[], int B[], int N)
{
    int fish = 0, size = 0, survivors = 0;
    int *stack = (int*)malloc(N * sizeof(int));

    while (fish < N)
    {
        if (B[fish] == 0)
        {
            if (size > 0)
            {
                while (size > 0)
                {
                    if (stack[size - 1] > A[fish])
                    {
                        survivors--;
                        break;
                    }
                    else
                        size--;
                }
            }
            survivors++;
        }
        else // B[fish] == 1
        {
            if (B[fish + 1] == 0 && fish + 1 < N)
            {
                if (A[fish] > A[fish + 1])
                {
                    stack[size] = A[fish];
                    size++;
                }
                else // A[fish] < A[fish + 1]
                {
                    if (size > 0)
                        fish--;
                    else
                        survivors++;
                }
                fish++;
            }
            else // B[fish + 1] == 1 || fish + 1 == N
            {
                stack[size] = A[fish];
                size++;                
            }
        }
        fish++;
    }
    free(stack);
    return survivors + size;
}
