/*
Task: https://app.codility.com/programmers/trainings/4/polygon_concavity_index/
Score: https://app.codility.com/demo/results/trainingKNWCUS-VV8/

Algorithm:
1. First, determine the global orientation of the polygon. Traverse successive triplets of points and find
the first non-zero cross product (cross). Its sign (+/-) determines the expected direction of rotation
(expected_sign). If all crosses are zero → all collinear points → return -1.
2. Then, check each vertex locally. For each point:
- ignore collinear segments (extend prev and next until cross ≠ 0),
- calculate cross for (prev, i, next).
3. Concavity Decision
- if cross = 0 → angle ~180°, ignore,
- if cross sign ≠ expected_sign → true concavity, return the point index.
4. If no point violates the orientation, the polygon is convex → return -1.
*/

#include <stdio.h>

struct Point2D
{
    int x;
    int y;
};

long long int cross(struct Point2D A[], int i, int j, int k)
{
    long long int x1, y1, x2, y2;

    x1 = A[j].x - A[i].x;
    y1 = A[j].y - A[i].y;
    x2 = A[k].x - A[j].x;
    y2 = A[k].y - A[j].y;

    return x1 * y2 - y1 * x2;
}

int solution(struct Point2D A[], int N)
{
    int i, j, orientation, prev, next, local_sign;
    long long int signed_area = 0, c;
    
    for (i = 0; i < N; i++)
    {
        j = (i + 1) % N;
        signed_area = signed_area + (long long int)A[i].x * A[j].y - (long long int)A[j].x * A[i].y;
    }

    if (signed_area == 0)
        return -1;

    orientation = (signed_area > 0) ? 1 : -1;

    for (i = 0; i < N; i++)
    {
        prev = (i - 1 + N) % N;
        next = (i + 1) % N;

        c = cross(A, prev, i, next);

        if (c == 0)
            continue;

        local_sign = (c > 0) ? 1 : -1;

        if (local_sign != orientation)
            return i;
    }
    return -1;
}
