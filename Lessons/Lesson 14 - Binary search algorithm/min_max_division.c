/*
Task: https://app.codility.com/programmers/lessons/14-binary_search_algorithm/min_max_division/
Score: https://app.codility.com/demo/results/training27AJ66-UZA/

Algorithm:
1. Extracting the element with the maximum value from the input array and calculating the sum of all elements.
2. The result (candidate) is in the range from point 1 (min to max).
3. Using the binary search method, dividing the sum of the interval (min + max) by 2, narrowing down the 
subsequent search and checking how many blocks of the input table contain the result (middle) of the 
division operation.
4. If the number of blocks is less than the assumptions (K) of the task, we narrow the range from the 
top (max) by subtracting one from the previous division result and divide the next range (min + new max) 
by 2 again.
5. If the number of blocks is greater than the assumptions (K) of the task, we narrow the interval from 
the bottom (min) by adding one to the previous division result and the next interval (new min + max) is 
divided by 2.
6. The narrowing operation ends when the upper limit (max) is less than the lower limit (min), where the 
final result is the result of the last division operation described above.
*/

int count_blocks(int A[], int mid, int N)
{
    int sum = 0, blocks = 1;

    for (int i = 0; i < N; i++)
    {
        sum += A[i];
        if (sum > mid)
        {
            sum = A[i];
            blocks++;
        }

    }

    return blocks;
}

int solution(int K, int M, int A[], int N)
{
    int i, total_sum = 0, max_val = 0, min, mid, max, result = 0;

    for (i = 0; i < N; i++)
    {
        max_val = (max_val < A[i]) ? A[i] : max_val;
        total_sum += A[i];
    }

    min = max_val;
    max = total_sum;

    while (min <= max)
    {
        mid = (min + max) / 2;
        if (count_blocks(A, mid, N) > K)
            min = mid + 1;
        else
        {
            result = mid;
            max = mid - 1;
        }
    }

    return result;
}
