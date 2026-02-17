/*
Task: https://app.codility.com/programmers/trainings/2/dwarfs_rafting/
Score: https://app.codility.com/demo/results/trainingXABP6S-465/

Strategy:
1. Convertion the seat numbers for barrels (S) and dwarfs (T) into indices for a two-dimensional character array
filling them with the characters 'b' (barrel) and 'd' (dwarf), initialization the array with 'f' (free) while
creating the array.
2. Split the array into four quadrants: q1, q2, q3, and q4, with the number of dwarfs 'd' and free seats 'f' for
each quadrant.
3. Diagonal comparison of quadrants q1 with q4 and q2 with q3, comparing the sums of dwarfs and free seats in each
quadrant. If the sums are different, subtract the difference from the number of free seats 'f' in the quadrant with
the greater sum so that the sums are equal. The diagonal sums need not be identical in each quadrant.
4. Finally, summing up all the remaining free spaces in each quarter giving the final result.
*/

#include <stdio.h>
#include <stdlib.h>

int solution(int N, char *S, char *T) {
    int i, j, row, col, front, back, left, right;
    char **raft = malloc(N * sizeof(char *));
    for (i = 0; i < N; i++)
        raft[i] = malloc(N * sizeof(char));
    
    struct quarter {
        int dwarf;
        int free;
    } q1, q2, q3, q4;
    
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            raft[i][j] = 'f';

    i = 0;
    while (S[i] != '\0') {
        while (S[i] != ' ' && S[i] != '\0') {
            switch (S[i]) {
                case '1'...'9':
                    row = 0;
                    if (S[i + 1] >= '0' && S[i + 1] <= '9') {
                        row = (int)(S[i] - '0') * 10;
                        i++;
                    }
                    row = row + (int)(S[i] - '0');
                    break;
                case 'A'...'Z':
                    col = (int)(S[i] - '@');
                    break;
            }
            i++;
        }
        raft[row - 1][col - 1] = 'b';
        if (S[i] != '\0')
            i++;
    }

    i = 0;
    while (T[i] != '\0') {
        while (T[i] != ' ' && T[i] != '\0') {
            switch (T[i]) {
                case '1'...'9':
                    row = 0;
                    if (T[i + 1] >= '0' && T[i + 1] <= '9') {
                        row = (int)(T[i] - '0') * 10;
                        i++;
                    }
                    row = row + (int)(T[i] - '0');
                    break;
                case 'A'...'Z':
                    col = (int)(T[i] - '@');
                    break;
            }
            i++;
        }
        raft[row - 1][col - 1] = 'd';
        if (T[i] != '\0')
            i++;
    }

    q1.dwarf = 0;
    q1.free = 0;
    for (i = 0; i < N / 2; i++) {
        for (j = 0; j < N / 2; j++) {
            if (raft[i][j] == 'd')
                q1.dwarf++;
            if (raft[i][j] == 'f')
                q1.free++;
        }
    }

    q2.dwarf = 0;
    q2.free = 0;
    for (i = 0; i < N / 2; i++) {
        for (j = N / 2; j < N; j++) {
            if (raft[i][j] == 'd')
                q2.dwarf++;
            if (raft[i][j] == 'f')
                q2.free++;
        }
    }

    q3.dwarf = 0;
    q3.free = 0;
    for (i = N / 2; i < N; i++) {
        for (j = 0; j < N / 2; j++) {
            if (raft[i][j] == 'd')
                q3.dwarf++;
            if (raft[i][j] == 'f')
                q3.free++;
        }
    }

    q4.dwarf = 0;
    q4.free = 0;
    for (i = N / 2; i < N; i++) {
        for (j = N / 2; j < N; j++) {
            if (raft[i][j] == 'd')
                q4.dwarf++;
            if (raft[i][j] == 'f')
                q4.free++;
        }
    }

    if ((q1.dwarf + q1.free) > (q4.dwarf + q4.free)) {
        q1.free = q1.free - ((q1.dwarf + q1.free) - (q4.dwarf + q4.free));
        if (q1.free < 0)
            return -1;
    }
    if ((q4.dwarf + q4.free) > (q1.dwarf + q1.free)) {
        q4.free = q4.free - ((q4.dwarf + q4.free) - (q1.dwarf + q1.free));
        if (q4.free < 0)
            return -1;
    }
    if ((q2.dwarf + q2.free) > (q3.dwarf + q3.free)) {
        q2.free = q2.free - ((q2.dwarf + q2.free) - (q3.dwarf + q3.free));
        if (q2.free < 0)
            return -1;
    }
    if ((q3.dwarf + q3.free) > (q2.dwarf + q2.free)) {
        q3.free = q3.free - ((q3.dwarf + q3.free) - (q2.dwarf + q2.free));
        if (q3.free < 0)
            return -1;
    }

    front = q1.dwarf + q1.free + q2.dwarf + q2.free;
    back = q3.dwarf + q3.free + q4.dwarf + q4.free;
    left = q1.dwarf + q1.free + q3.dwarf + q3.free;
    right = q2.dwarf + q2.free + q4.dwarf + q4.free;
    
    if (front == back && left == right)
        return q1.free + q2.free + q3.free + q4.free;
    else
        return -1;
}
