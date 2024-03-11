/*
Task: https://app.codility.com/programmers/trainings/5/three_letters/
Score: https://app.codility.com/demo/results/training8XYJ5X-5JD/

Algorithm:
1. If A > B, in each iteration extract a maximum of two letters 'a' and one 'b' until A and B are equal 
(A == B).
2. If A < B, then the opposite to point 1.
3. If A == B, then in each iteration, extract a maximum of two letters 'a' and two 'b' until A and B are 
zero.
4. If A == 1 or B == 1, only one remaining letter 'a' or 'b' is extracted.
5. If A == 0 or B == 0, such cases are skipped without action.
6. The operation ends when A == B == 0, completing the text with the end of string '\0'.
*/

#include <stdlib.h>

char *solution(int A, int B)
{
    int i = 0;
    char *string = (char*)malloc((A + B + 1) * sizeof(char));

    while (A != 0 || B != 0)
    {
        if (A > B)
        {
            if (A >= 2)
            {
                string[i] = 'a';
                i++;
                string[i] = 'a';
                i++;
                A -= 2;
            }
            else if (A == 1)
            {
                string[i] = 'a';
                i++;
                A--;               
            }

            if (B >= 1)
            {
                string[i] = 'b';
                i++;
                B--;
            }
        }
        else if (A < B)
        {
            if (B >= 2)
            {
                string[i] = 'b';
                i++;
                string[i] = 'b';
                i++;
                B -= 2;
            }
            else if (B == 1)
            {
                string[i] = 'b';
                i++;
                B--;
            }

            if (A >= 1)
            {
                string[i] = 'a';
                i++;
                A--;               
            }
        }
        else
        {
            if (string[i - 1] == 'a')
            {
                if (A >= 2)
                {
                    string[i] = 'b';
                    i++;
                    string[i] = 'b';
                    i++;
                    B -= 2;
                    string[i] = 'a';
                    i++;
                    string[i] = 'a';
                    i++;
                    A -= 2;
                }                   
                else
                {
                    string[i] = 'b';
                    i++;
                    string[i] = 'a';
                    i++;
                    B--;
                    A--;
                }
            }
            else
            {
                if (A >= 2)
                {
                    string[i] = 'a';
                    i++;
                    string[i] = 'a';
                    i++;
                    A -= 2;
                    string[i] = 'b';
                    i++;
                    string[i] = 'b';
                    i++;
                    B -= 2;
                }                   
                else
                {
                    string[i] = 'a';
                    i++;
                    string[i] = 'b';
                    i++;
                    A--;
                    B--;
                }
            }
        }
    }

    string[i] = '\0';

    return string;
}
