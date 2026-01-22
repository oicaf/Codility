/*
Task: https://app.codility.com/programmers/trainings/4/disappearing_pairs/
Score: https://app.codility.com/demo/results/training73HSXJ-A3G/

Algorithm:
The algorithm consists of a single pass through the entire array, considering three cases:
1. If there are no pairs, the entire content of the source array 'src' is copied into the destination array 'dest'.
2. If there are pairs, copying of the elements from the source array 'src' to the destination array 'dest' is suspended for
the duration of the pair occurrence.
3. If a new (non existing before) pair appears as a result of removal occurrence of a previous pair
(palindrome/symmetry case), the index of the destination array 'dest' is moved back by 1.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *solution(char *S)
{
    int i = 0, j = 0;
    unsigned char pair = 0;
    int N = strlen(S);
    char *src = malloc(N + 1);
    char *dest = malloc(N + 1);

    strcpy(src, S);
    strcpy(dest, S);

    while (dest != "")
    {
        strcpy(src, dest);
        while (src[i] != '\0')
        {
            if (src[i] != src[i + 1])
            {
                if (pair == 1)
                    pair = 0;
                else
                {
                    if (dest[j - 1] == src[i])
                        j--;
                    else
                    {
                        dest[j] = src[i];
                        j++;
                    }
                }
            }
            else
            {
                if (pair == 0)
                    pair = 1;
                else
                    pair = 0;
            }
            i++;
        }
        dest[j] = '\0';
        i = 0;
        j = 0;

        if (strlen(src) == strlen(dest))
            break;
    }

    return dest;
}
