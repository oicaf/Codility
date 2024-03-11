/*
Task: https://app.codility.com/programmers/lessons/13-fibonacci_numbers/fib_frog/
Score: https://app.codility.com/demo/results/training82TCGG-E3J/

Algorithm:
1. Creating an auxiliary 'fib' array with a sequence of Fibonacci numbers where the last element of this 
array has a value slightly greater than the maximum possible length of one jump for an input array with 
a maximum length of 100,000 (the 'fib' array covers all possible cases).
2. Scanning the input table and, after encountering one, checking whether any distance from this position 
to all previous positions, up to the beginning is a Fibonacci number, if so, only the smallest number of 
jumps needed to reach from the initial edge to the target point (leaf), i.e. currently checked:
- 0 no possibility of jumping,
- 1 one jump is enough,
- 2 two jumps are needed using a leaf located between those positions where such an (intermediate) leaf 
was already there checked and its distance is already the Fibonacci number, etc.
- 3 etc.
3. On this basis, a second auxiliary 'reachable' array is created (mapping), where the element value > 0 
means that it is possible is to reach this position and the number means how many minimum jumps are needed 
to reach this position from the starting edge.
4. Finally, the 'reachable' table is scanned, where for each position > 0 it is checked whether from this 
position to the end of the edge the last jump is possible (there is a Fibonacci number), if so, the value 
of one, i.e. the last additional jump, is added to the value of the currently checked index. The smallest 
value is always remembered here, meaning the minimum number of jumps needed to get from one bank to the 
other (final result).
*/

#include <stdlib.h>

int solution(int A[], int N)
{
    int i, j, min_jumps = 100000;
    int *fib = (int*)calloc(27, sizeof(int));
    int *reachable = (int*)calloc(N, sizeof(int));

    if (N <= 2)
        return 1;

    fib[1] = 1;
    for (i = 2; i < 27; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    for (i = 0; i < N; i++)
    {
        if (A[i] == 1)
        {
            j = 2;
            reachable[i] = 100000;
            while (fib[j] <= i)  
            {
                if (reachable[i - fib[j]] > 0)
                    reachable[i] = (reachable[i - fib[j]] + 1 < reachable[i]) ? reachable[i - fib[j]] + 1 : reachable[i];
                j++;
            }
            if (fib[j] == i + 1)
                reachable[i] = 1;
        }
    }

    for (i = 0; i < N; i++)
    {
        if (reachable[i] > 0)
        {
            for (j = 0; j < 27; j++)
            {
                if (fib[j] == N - i)
                {
                    min_jumps = (reachable[i] + 1 < min_jumps) ? reachable[i] + 1 : min_jumps;
                    break;
                }
            }
        }
    }

    if (min_jumps == 100000)
        return -1;
    else
        return min_jumps;
}
