/*
Task: https://app.codility.com/programmers/trainings/4/first_unique/
Score: https://app.codility.com/demo/results/training9KCCT9-VTF/

Algorithm:
1. Searching for the maximum value in the input array.
2. Based on the above value, allocating dynamic memory for an auxiliary array that counts the number of 
occurrences of each element from the input array.
3. Scan the input array from the first element and check whether a given array element appears only once 
in the auxiliary array, if so, this is the final result.
4. Using calloc is more advantageous than malloc because it additionally resets the entire area (arrays) 
to zero and there is no need to create additional code to assign zeros to all elements of this area.
5. The CHAR type was intentionally used in the calloc because when the type was INT it went out of memory 
and a NULL pointer for size 1,000,000,000 was returned.
*/

#include <stdlib.h>

int solution(int A[], int N)
{
    int i, max = 0;

    for (i = 0; i < N; i++)
        max = A[i] > max ? A[i] : max;

    char *count = (char*)calloc((max + 1), sizeof(char));

    for (i = 0; i < N; i++)
        count[A[i]]++;

    for (i = 0; i < N; i++)
    {
        if (count[A[i]] == 1)
        {
            free(count);
            return A[i];
        }
    }

    free(count);
    return -1;
}
