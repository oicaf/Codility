/*
Task: https://app.codility.com/programmers/lessons/5-prefix_sums/genomic_range_query/
Score: https://app.codility.com/demo/results/training4J8DSX-TP6/

Algorithm:
1. The first step is to create a two-dimensional array where:
- the first dimension (N) refers to each nucleotide in the sequence of characters / nucleotides (subsequent points in the DNA sequence),
- the second dimension (4 i.e. A,C,G,T) represents the number of occurrences of a given nucleotide,
2. At the same time, each nucleotide is converted (on the fly) to its corresponding influence factor (1,2,3,4).
3. The second stage is to go through all queries (M) and find the minimum impact factor for each query by comparing whether there has been a change in the same positions / indexes between the beginning and the end of a given query (query), if so, this means the minimum factor impact for a given query as these coefficients
are arranged in ascending order, i.e. from the minimum impact factor to the maximum.
*/

#include <stdlib.h>
#include <string.h>

struct Results solution(char *S, int P[], int Q[], int M)
{
    int i, j, N = strlen(S), count[N + 1][4];
    int *A = (int*)malloc(M * sizeof(int));
    struct Results result;

    for (i = 0; i < 4; i++)
        count[0][i] = 0;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < 4; j++)
            count[i + 1][j] = count[i][j];
        
        switch(S[i])
        {
            case 'A':   count[i + 1][0] = count[i][0] + 1;
                        break;
            case 'C':   count[i + 1][1] = count[i][1] + 1;
                        break;
            case 'G':   count[i + 1][2] = count[i][2] + 1;
                        break;
            case 'T':   count[i + 1][3] = count[i][3] + 1;
                        break;
        }
    }

    for (int K = 0; K < M; K++)
    {
        for (i = 0; i < 4; i++)
            if (count[P[K]][i] != count[Q[K] + 1][i])
            {
                A[K] = i + 1;
                break;
            }
    }
    
    result.A = A;
    result.M = M;
    return result;
}

