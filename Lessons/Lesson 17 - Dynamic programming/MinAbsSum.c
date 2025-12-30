/*
Task: https://app.codility.com/programmers/lessons/17-dynamic_programming/min_abs_sum/
Score: https://app.codility.com/demo/results/trainingARJ3CW-U7A/

Algorithm:
1. Convert all elements of array A to absolute values ​​(array B).
2. Determine the max element of array B.
3. Sum all elements of array B.
4. Create an array (count) that counts the elements of array B.
5. Sum the elements of array 'count' starting with the highest values ​​(until exhaustion), while checking whether
the sum of the elements does not exceed the total sum of elements of array B divided by 2. If the next sum exceeds
the value of sum/2, the next, smaller element is checked, checking the condition, etc.
6. The solution ends by traversing the entire array 'count' (without the 0 index), while still maintaining the
condition that the sum of the elements of array 'count' cannot exceed the sum of the elements of array B divided
by 2.
7. Problem with defining one/last test case that generates an incorrect answer.
*/

#include <stdio.h>
#include <math.h>

int solution(int A[], int N)
{
    int i, sum = 0, result = 0, max = 0, B[N];

    if (N == 0)
        return 0;
    if (N == 1)
        return abs(A[0]);

    for (i = 0; i < N; i++)
    {
        B[i] = abs(A[i]);
        max = B[i] > max ? B[i]: max;
        sum += B[i];
    }

    int count[max + 1];

	for (i = 0; i <= max; i++)
		count[i] = 0;

    for (i = 0; i < N; i++)
    {
        if (B[i] > 0)
            count[B[i]]++;
    }

    for (i = max; i > 0; i--)
    {
        while (count[i] > 0)
        {
            if ((result + i) <= (sum / 2))
            {
                result += i;
                count[i]--;
            }
            else
                break;
        }
    }

    return sum - (2 * result);
}
