/*
Task: https://app.codility.com/programmers/lessons/12-euclidean_algorithm/common_prime_divisors/
Score: https://app.codility.com/demo/results/trainingXHEPDT-8ZZ/

Algorithm:
1. Using Euclid's algorithm to find the GCD of two numbers, if GCD == 1 the answer is false.
2. Note that the GCD will have to contain all the prime factors of both numbers for the answer to be 
true, so check that new_a = a/gcd_a and new_b = b/gcd_b can be reduced to 1 by repeatedly dividing them 
by gcd(new_a, gcd) and gcd(new_b, gcd) until new_a and new_b reach 1, which means success, or 
gcd(new_a, gcd) or gcd(new_b, gcd) returns 1, which means failure.
*/

int gcd(int a, int b)
{
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

int solution(int A[], int B[], int Z)
{
    int i, _gcd, new_a, new_b, _gcd_a, _gcd_b, result = 0;
    
    for (i = 0; i < Z; i++)
    {
        if (A[i] == B[i])
        {
            result++;
            continue;
        }

        _gcd = gcd(A[i], B[i]);
        if (_gcd == 1)
            continue;

        new_a = A[i];
        new_b = B[i];
        _gcd_a = _gcd_b = _gcd;

        while (1)
        {
            if (new_a == 1 && new_b == 1)
            {
                result++;
                break;
            }

            if (new_a > 1)
            {
                new_a = new_a / _gcd_a;
                if (new_a > 1)
                {
                    _gcd_a = gcd(new_a, _gcd);
                    if (_gcd_a == 1)
                        break;
                }
            }

            if (new_b > 1)
            {
                new_b = new_b / _gcd_b;
                if (new_b > 1)
                {
                    _gcd_b = gcd(new_b, _gcd);
                    if (_gcd_b == 1)
                        break;
                }
            }
        }
    }

    return result;
}
