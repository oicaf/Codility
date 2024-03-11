/*
Task: https://app.codility.com/programmers/trainings/7/tree_longest_zig_zag/
Score: https://app.codility.com/demo/results/trainingSVME4A-KF4/

Algorithm:
Traversing the entire tree recursively using the DFS (Depth-First Search) method, remembering the largest 
(max) number of direction changes with each pass.
-1 - left direction,
 0 - neutral direction, e.g. at the beginning from the main root where there was no previously specified 
 direction,
 1 - direction to the right,
*/

#include <stdlib.h>

int dfs(struct tree *T, int dir, int count)
{
    int zigzag, max_left, max_right, max = count;

    if (T->l != NULL)
    {
        zigzag = count;
        if (dir == 1)
            zigzag++;
        max_left = dfs(T->l, -1, zigzag);
        max = (max_left > max) ? max_left : max;
    }

    if (T->r != NULL)
    {
        zigzag = count;
        if (dir == -1)
            zigzag++;
        max_right = dfs(T->r, 1, zigzag);
        max = (max_right > max) ? max_right : max;
    }

    return max;
}

int solution(struct tree *T)
{
    return dfs(T, 0, 0);
}
