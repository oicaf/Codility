/*
Task: https://app.codility.com/programmers/lessons/17-dynamic_programming/number_solitaire/
Score: https://app.codility.com/demo/results/trainingCEKXER-EQH/

Algorithm:
The idea is to linearly scan the input array and sum each element of this array with the max value of 
the element of the second array, which changes dynamically and in which the mentioned sums are saved in 
each iteration. The extra array is a kind a six-element window (dice) that follows the currently scanned 
element of the input array. For each element of the input array, an additional array is scanned (max. 6 
moves back - dice) in search of the maximum value, and when found, these two values are summed and then 
written to the last position of the additional array. The remaining elements of this array are moved down 
by one (the floating window), removing the first element from the previous iteration and inserting the 
second element from the previous iteration, etc. Except when the input array is of size six or less, then 
there is no sliding of the window because there is no has something to move around. When the input array 
has a size of 5 or less, saving the sum of two elements takes place in the currently scanned index of the 
input array because the entire cycle always ends at the last element of the input array.
*/

int solution(int A[], int N)
{
    int dice, arr, DP[6], max, result = 0;

    for (dice = 0; dice < 6; dice++)
        DP[dice] = A[0];

    for (arr = 1; arr < N; arr++)
    {
        max = DP[0];
        for (dice = 1; dice < 6; dice++)
        {
            if (arr > 5)
                DP[dice - 1] = DP[dice];

            max = DP[dice] > max ? DP[dice] : max;
        }

        if (arr < 5)
            result = DP[arr] = A[arr] + max;
        else
            result = DP[5] = A[arr] + max;
    }

    return result;
}
