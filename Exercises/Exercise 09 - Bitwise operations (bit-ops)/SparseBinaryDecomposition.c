/*
Task: https://app.codility.com/programmers/trainings/9/sparse_binary_decomposition/
Score: https://app.codility.com/demo/results/training9AKKBU-FBK/

Algorithm:
The solution involves creating two variables p and q, where p takes on an initial value of N and q takes on an initial
value of zero. Variable p is regularly divided by 2, and if the remainder of two consecutive (adjacent) divisions by 2
is 1 (two ones next to each other), then the one in the more significant position is moved to the same position in
variable q (adding to the current sum in q). Simultaneously, the same one is subtracted from the current sum in p. The
procedure ends when variable p reaches zero. The result is located in variable q, which is one part of the decomposition;
the other part of the decomposition can be determined using the formula N - q.
*/

#include <stdio.h>
#include <math.h>

int solution(int N)
{
    int i, p = N, q = 0;

    if (N < 3)
        return 0;

    for (i = 1; p > 0; i++)
    {
        if (p % 2 > 0)
        {
            p = p / 2;
            if (p % 2 > 0)
            {
                p = p - 1;
                q = q + pow(2,i);
            }
        }
        else
            p = p / 2;
    }

    return q;
}
