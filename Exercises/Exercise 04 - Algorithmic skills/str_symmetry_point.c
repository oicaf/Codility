/*
Task: https://app.codility.com/programmers/trainings/4/str_symmetry_point/
Score: https://app.codility.com/demo/results/trainingX8H2R6-AQN/

Algorithm:
1. Words of even character length do not satisfy the conditions by default.
2. For words with odd character lengths, a middle point is determined and from this point opposite 
characters are compared successively, moving character by character to the beginning and end of the 
entire word at the same time.
3. If the expression meets all conditions, the index of the previously determined midpoint is returned.
*/

#include <string.h>

int solution(char *S)
{
    int length = strlen(S);

    if (length == 1)
        return 0;

    if (length % 2 == 0)
        return -1;

    int mid = length / 2;
    for (int offset = 1; offset <= mid; offset++)
        if (S[mid + offset] != S[mid - offset])
            return -1;

    return mid;
}
