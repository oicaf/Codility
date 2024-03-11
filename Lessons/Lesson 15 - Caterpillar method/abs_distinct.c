/*
Task: https://app.codility.com/programmers/lessons/15-caterpillar_method/abs_distinct/
Score: https://app.codility.com/demo/results/trainingZHN8UQ-QVD/

Algorithm:
1. Converting negative array elements (if any) to their absolute value.
2. If the array contained positive and negative elements before point 1 was performed, the array is sorted.
3. Comparing two adjacent elements of a sorted array by moving "caterpillar" from beginning to end.
4. If adjacent elements are equal, the counter is decremented by 1, by default the counter is equal to 
the size of the array.
*/

#include <math.h>

void Sortowanie(int A[], int left, int right)
{
    int i = left;
    int j = right;
    int x = A[(left + right ) / 2];

    do
    {
        while (A[i] < x)
             i++;
       
        while (A[j] > x)
             j--;
       
        if (i <= j)
        {
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
           
            i++;
            j--;
        }

    } while (i <= j);
   
    if (left < j)
		Sortowanie(A, left, j);
    if (right > i)
		Sortowanie(A, i, right);
}

int solution(int A[], int N)
{
	int i = 0, back, front, result = N;

	while (A[i] < 0)
	{
		A[i] = abs(A[i]);
		i++;
	}
	
	if (i != 0 && i != N)
		Sortowanie(A, 0, N - 1);
	
	for (back = 0; back < N - 1; back++)
	{
		front = back + 1;
		if (A[back] == A[front])
			result--;
	}
	
	return result;
}
