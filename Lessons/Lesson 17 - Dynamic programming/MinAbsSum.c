/*
Task: https://app.codility.com/programmers/lessons/17-dynamic_programming/min_abs_sum/
Score: https://app.codility.com/demo/results/training3YNMUC-W8Z/

Strategy:
1. Convert the number to absolute values, as the sign is irrelevant when minimizing the difference.
2. Calculate the sum of all elements, as the value closest to sum/2 is sought.
3. Count the number of times each value occurs, count[x] = number of occurrences of x.
4. Construct possible sums (dp):
- dp[j] tells whether the sum j can be obtained,
- process the "i" value (1…max), not each element individually.
5. For each "i" value, use it a maximum of count[i] times,
controlling this by the counter in dp.
6. Finally, find the sum closest to sum/2.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int solution(int A[], int N) {
    int i, j;

    if (N == 0)
        return 0;
    if (N == 1)
        return abs(A[0]);

    int max = 0, sum = 0;
    for (i = 0; i < N; i++) {
        A[i] = abs(A[i]);
        max = A[i] > max ? A[i]: max;
        sum += A[i];
    }

    int *count = malloc((max + 1) * sizeof(int));
	for (i = 0; i <= max; i++)
		count[i] = 0;

    for (i = 0; i < N; i++)
        count[A[i]]++;

    int *dp = malloc((sum + 1) * sizeof(int));
    for (i = 0; i <= sum; i++)
        dp[i] = -1;

    dp[0] = 0;
    for (i = 1; i <= max; i++) {
        if (count[i] > 0) {
            for (j = 0; j <= sum; j++) {
                if (dp[j] >= 0)
                    dp[j] = count[i];
                else if (j >= i && dp[j - i] > 0)
                    dp[j] = dp[j - i] - 1;
            }
        }
    }

    int result = sum;
    for (i = 0; i <= sum/2; i++) {
        if (dp[i] >= 0) {
            int diff = sum - 2 * i;
            if (diff < result)
                result = diff;
        }
    }

    free(count);
    free(dp);
    return result;
}
