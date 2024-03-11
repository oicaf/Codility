/*
Task: https://app.codility.com/programmers/lessons/15-caterpillar_method/min_abs_sum_of_two/
Score: https://app.codility.com/demo/results/trainingXR5M8P-NG4/

Algorithm:
1. Sort the array ascending.
2. If the array elements are only positive, the result is the sum of the first two array elements.
3. If the array elements are only negative, the result is the absolute value of the sum of the last two 
elements of the array.
4. If the elements of the array are positive and negative, the initial min absolute sum is the absolute 
sum of the two extreme elements board.
5. Then two absolute sums are compared, the current left + right minus 1 with the current right + left 
plus 1.
6. Depending on which sum is smaller, the leftmost marker is moved by 1 to the right or the rightmost 
marker is moved by 1 to the left.
7. This is a new starting point and the activity is repeated from point 5. until the left marker is 
larger than the right one.
8. In the meantime, in each loop, the currently calculated absolute sum is compared with the previous 
min absolute sum and the smallest value is always saved, which is the final result.
9. If the array has two elements, there is only one pass in the loop, which immediately gives the final 
result.
*/

#include <math.h>

void quick_sort( int A[], int left, int right )
{
    int i = left;
    int j = right;
    int x = A[(left + right) / 2 ];

    do
    {
        while (A[ i ] < x)
             i++;
       
        while (A[ j ] > x)
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
		quick_sort(A, left, j);
    if (right > i)
		quick_sort(A, i, right);
}

int solution(int A[], int N)
{
    int left = 0, right = N - 1, min_abs_sum;

    if (N == 1)
        return abs(A[0] + A[0]);

    quick_sort(A, 0, N - 1);

    if (A[0] >= 0)
        return A[0] + A[0];
    
    else if (A[N - 1] < 0)
        return abs(A[N - 1] + A[N - 1]);
    
    else
    {
        min_abs_sum = abs(A[left] + A[right]);
        while (left <= right)
        {
            if (N == 2 && left == right)
                return min_abs_sum;

            if (abs(A[left] + A[right - 1]) > abs(A[left + 1] + A[right]))
                left++;
            else if (abs(A[left] + A[right - 1]) < abs(A[left + 1] + A[right]))
                right--;
            else
            {
                right--;
                left++;
            }

            min_abs_sum = (abs(A[left] + A[right]) < min_abs_sum) ? abs(A[left] + A[right]) : min_abs_sum;
        }
    }

    return min_abs_sum;
}
