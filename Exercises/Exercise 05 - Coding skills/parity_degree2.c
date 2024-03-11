/*
Task: https://app.codility.com/programmers/trainings/5/parity_degree/
Score: https://app.codility.com/demo/results/training9YUTHG-QJR/

Algorithm:
The number of cycles of each iteration increasing the numerator (power) by 1 until the remainder of the 
argument divided by the power (numerator) of two is one is the final result - 1.
*/

#include <math.h>

int solution(int N)
{
    int power = 1;

    while(!(N % (int) pow(2, power)))
        power++;

    return power - 1;
}
