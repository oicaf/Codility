/*
Task: https://app.codility.com/programmers/trainings/5/parity_degree/
Score: https://app.codility.com/demo/results/training6YW3MQ-Z6H/

Algorithm:
The number of bit shifts to the right by one in the input argument until one appears on the least 
significant bit 0 (LSB) is the highest power of two that divides the input argument without remainder.
*/

int solution(int N)
{
    int power = 0;

    while(!(N % 2))
    {
        power++;
        N = N >> 1;
    }

    return power;
}
