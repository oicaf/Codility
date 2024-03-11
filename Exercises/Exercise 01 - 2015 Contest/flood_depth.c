/*
Task: https://app.codility.com/programmers/trainings/1/flood_depth/
Score: https://app.codility.com/demo/results/trainingTV6REH-NQQ/

Algorithm:
1. The general approach is to scan the entire array and isolate the holes that have two peaks on the left 
and right and a minimum in between.
2. Each hole can collect a certain amount of water, the maximum collected amount of water (depth) in one 
of the holes is the result.
3. The amount of water is calculated when the three characteristic points mentioned above have been created.
4. If the right peak exceeds the height of the left peak, the current water depth in the hole between 
the left peak and the minimum is calculated, then the three parameters are reset and a new hole is 
separated from the beginning.
5. When the height of the right peak is <= the height of the left peak, the water depth is calculated as 
the difference between the right peak and the minimum.
6. As the blocks fall down, the minimum hole is determined each time.
*/

int solution (int A[], int N)
{
    int max_left, min, max_right, max_depth = 0;

    max_left = min = max_right = A[0];

    for (int block = 1; block < N; block++)
    {
        if (A[block] > A[block - 1])
        {
            if (A[block] > max_left)
            {
                max_depth = (max_left - min) > max_depth ? max_left - min : max_depth;
                max_left = min = max_right = A[block];
            }
            else
            {
                max_right = A[block];
                max_depth = (max_right - min) > max_depth ? max_right - min : max_depth;
            }
        }
        else if (A[block] < A[block - 1])
        {
            if (A[block] < min)
                min = A[block];
        }
    }

    return max_depth;
}
