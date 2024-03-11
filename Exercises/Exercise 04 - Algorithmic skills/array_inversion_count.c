/*
Task: https://app.codility.com/programmers/trainings/4/array_inversion_count/
Score: https://app.codility.com/demo/results/trainingBF7EZU-KQ3/

Algorithm:
Counting the number of inversions/replacements of array elements during sorting. Modifications to the 
standard merge sort algorithm are in the following areas:
- merge and merge_sort functions return the number of counts (count variable added),
- added lines of code with the "tricky part" comment,
- recursive calls to the merge_sort and merge functions take into account the count variable (summing 
after each call),
The following extreme case results after sorting further help to understand the concept:
- if the elements of the array after sorting are decreasing, the number of all possible combinations of 
pairs gives the final result, meeting the assumptions of the task, e.g. [5, 4, 3, 2, 1] = 10,
- if the elements of the array after sorting are increasing, then none of the pairs satisfies the task, 
e.g. [1, 2, 3, 4, 5] = 0,
*/

#include <stdlib.h>
#include <limits.h>

int merge(int array[], int left, int mid, int right)
{
    int i, j, count = 0;

    int *temp_L = (int*) malloc(((mid - left + 1) + 1) * sizeof(int));
    int *temp_R = (int*) malloc(((right - mid) + 1) * sizeof(int));

    for (i = 0; i < mid - left + 1; i++)
        temp_L[i] = array[left + i];

    for (i = 0; i < right - mid; i++)
        temp_R[i] = array[mid + 1 + i];

    temp_L[mid - left + 1] = INT_MAX;
    temp_R[right - mid] = INT_MAX;
    
    i = j = 0;
    for (int k = left; k <= right; k++)
    {
        if (temp_L[i] <= temp_R[j])
            array[k] = temp_L[i++];
        else
        {
            count += j + (mid + 1) - k; //tricky part
            array[k] = temp_R[j++];
        }
    }

    free(temp_L);
    free(temp_R);
    return count;
}

int merge_sort(int array[], int left, int right)
{
    int count = 0;

    if (left >= right)
        return count;

    int mid = (left + right) / 2;

    count += merge_sort(array, left, mid);
    count += merge_sort(array, mid + 1, right);

    count += merge(array, left, mid, right);

    return count;
}

int solution(int A[], int N)
{
    int result = merge_sort(A, 0, N - 1);
    return result > 1000000000 ? -1 : result;
}
