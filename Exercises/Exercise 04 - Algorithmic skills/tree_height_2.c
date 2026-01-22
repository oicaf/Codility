/*
Task: https://app.codility.com/programmers/trainings/4/tree_height/
Score: https://app.codility.com/demo/results/trainingH3QPTP-9HA/

Algorithm:
Traversing the entire binary tree using the recursive method and determining the maximum height of the 
tree. The function calculating the height of each tree contains two counters, for the left and right 
subtrees.
*/

#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int x;
    struct tree *l;
    struct tree *r;
};

int dfs(struct tree *T, int count)
{
    int max_left, max_right, max = count;

    if (T->l != NULL)
    {
        count++;
        max_left = dfs(T->l, count);
        max = (max_left > max) ? max_left : max;
        count--;
    }

    if (T->r != NULL)
    {
        count++;
        max_right = dfs(T->r, count);
        max = (max_right > max) ? max_right : max;
        count--;
    }

    return max;
}

int solution(struct tree *T)
{
    return dfs(T, 0);
}
