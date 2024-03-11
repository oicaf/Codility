/*
Task: https://app.codility.com/programmers/lessons/12-euclidean_algorithm/chocolates_by_numbers/
Score: https://app.codility.com/demo/results/training7GNWBV-8BM/

Algorithm:
N and M meet at their least common multiply. Dividing this LCM by M gets the number of steps (chocolates) 
that can be eaten.
*/

int gcd(int a, int b)
{
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

int solution(int N, int M)
{
    unsigned long int lcm = (unsigned long int)N * M / gcd(N, M);

    return lcm / M;
}
