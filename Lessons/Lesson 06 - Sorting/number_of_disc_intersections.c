/*
Task: https://app.codility.com/programmers/lessons/6-sorting/number_of_disc_intersections/
Score: https://app.codility.com/demo/results/training7DY8P7-CRM/
*/

#include <stdlib.h>

void quick_sort(long long array[], int left, int right)
{
    int i = left;
    int j = right;
    long long x = array[(left + right) / 2];
    
    do
    {
        while (array[i] < x)
            i++;
        
        while (x < array[j])
            j--;

        if (i <= j)
        {
            long long temp = array[i];
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
    int i, j = 0, result = 0;

    long long *left = (long long*) malloc((N + 1) * sizeof(long long));
    long long *right = (long long*) malloc((N + 1) * sizeof(long long));

    for (i = 0; i < N; i++)
        right[i] = (long long) i + A[i];
    quick_sort(right, 0, N -1);
 
    for (i = 0; i < N; i++)
        left[i] = i - A[i];
    quick_sort(left, 0, N -1);
 
    for (i = 0; i < N; i++)
    {
        while (j < N && left[j] <= right[i])
        {
            result = result + j - i;
            j++;
        }

        if (result > 10000000) return -1;
    }

    return result;
}
