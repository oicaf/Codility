/*
Task: https://app.codility.com/programmers/lessons/8-leader/dominator/
Score: https://app.codility.com/demo/results/trainingKAHMH6-SCS/
*/

#include <stdlib.h>

void quick_sort(int array[], int left, int right)
{
    int i = left;
    int j = right;
    int x = array[(left + right) / 2];
    
    do
    {
        while (array[i] < x)
            i++;
        
        while (array[j] > x)
            j--;

        if (i <= j)
        {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }

    } while (i <= j);

    if (left < j)
        quick_sort(array, left, j);
    
    if (i < right)
        quick_sort(array, i, right);
}

int solution(int A[], int N)
{
	int i, candidate, count = 0, ind = -1;
	int *temp = (int*)malloc(N * sizeof(int));

	if (N == 0)
		return ind;
	
	for (i = 0; i < N; i++)
		temp[i] = A[i];

	quick_sort (temp, 0, N - 1);

	candidate = temp[N / 2];
	for (i = 0; i < N; i++)
	{
		if (A[i] == candidate)
		{
			count += 1;
			ind = i;
		}
	}
	if (count > N / 2)
		return ind;
	else
		return -1;
}
