/*
Task: https://app.codility.com/programmers/lessons/13-fibonacci_numbers/ladder/
Score: https://app.codility.com/demo/results/trainingP9WH3E-D5A/

Algorithm:
1. Calculation of the Fibonachi sequence for the length of the array L, with the attention that it must 
be immediately assumed by modulo 2^30 (30 is the max from the array B), because the Fibonaci number for 
the array with a length of max. 50,000 (assumption in the problem) significantly exceeds (> long double) 
max integer value (INT_MAX = 2^31).
2. The result is the modulus of the Fibonachi number of the array element A+1 and 2 to the power of the 
array element B.
*/

#include <stdlib.h>
#include <math.h>

struct Results solution(int A[], int B[], int L)
{
    int i;
    int *Fib = (int*)malloc((L + 2) * sizeof(int));
    int *C = (int*)malloc((L + 1) * sizeof(int));
    struct Results result;

    Fib[0] = 0;
    Fib[1] = 1;
    for (i = 2; i <= L + 1; i++)
        Fib[i] = (Fib[i - 1] + Fib[i - 2]) % (int)pow(2, 30);

    for (i = 0; i < L; i++)
        C[i] = Fib[A[i] + 1] % ((int)pow(2, B[i]));

    result.C = C;
    result.L = L;
    return result;
}
