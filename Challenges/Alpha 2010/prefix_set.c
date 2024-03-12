/*
Task: https://app.codility.com/programmers/task/prefix_set/
Score: https://app.codility.com/demo/results/trainingWCCCJP-CHX/

Algorithm:
1. Scanning the input table for the maximum value that determines the appropriate dynamic memory allocation 
for the auxiliary 'count' table.
2. The 'count' array is used to count/mark only the first occurrence of each unique value from the input 
array, marking such a case as one and increasing the unique number counter by 1 to collect the total 
number of unique numbers in the entire range of the input array. If a number repeats itself, this case 
is skipped/ignored.
3. In the second step, the input table is scanned again and if the value is one in the 'count' table, 
this place is marked with a zero in the 'count' table and the counter of unique numbers is decremented 
by 1. When the same value appears again, this is the case is overlooked/ignored.
4. When the unique number counter is reset, the current scanning index of the input table is returned, 
which is the final result.
*/

#include <stdlib.h>

int solution(int A[], int N)
{
    int i, max = 0, unique = 0;

    for (i = 0; i < N; i++)
        max = (A[i] > max) ? A[i] : max;

    int *count = (int*)calloc(max + 1, sizeof(int));

    for (i = 0; i < N; i++)
    {
        if (count[A[i]] == 0)
        {
            count[A[i]] = 1;
            unique++;
        }
    }

    for (i = 0; i < N; i++)
    {
        if (count[A[i]] == 1)
        {
            count[A[i]] = 0;
            unique--;
            if (unique == 0)
            {
                free(count);
                return i;
            }
        }
    }

    return 0;
}
