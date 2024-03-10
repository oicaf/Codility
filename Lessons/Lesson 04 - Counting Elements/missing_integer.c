/*
Task: https://app.codility.com/programmers/lessons/4-counting_elements/missing_integer/
Score: https://app.codility.com/demo/results/trainingUXCZKV-93K/
*/

#include <stdlib.h>

int solution(int A[], int N)
{
    int i;
    int *count = (int*)malloc((1000000 + 1) * sizeof(int));

    for (i = 0; i <= 1000000; i++)
        count[i] = 0;

    for (i = 0; i < N; i++)
    {
        if (A[i] > 0)
            count[A[i]]++;
    }
    
    for (i = 1; i <= 1000000; i++)
        if (count[i] == 0)
            break;

    return i;
}
