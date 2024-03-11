/*
Task: https://app.codility.com/programmers/trainings/4/tree_height/
Score: https://app.codility.com/demo/results/trainingJ9J5Y3-UXF/

Algorithm:
Traversing the entire binary tree using the recursive method and determining the maximum height of the 
tree. The function calculating the height of each tree contains two counters, for the left and right 
subtrees, important assumptions:
-1 - means an empty tree with height -1 (NULL pointer for the tree),
 0 - means a tree of height 0 with only one node,
 1 - means a tree of height 1 with a root containing only one subtree with a node, left or right or 
both, etc...
*/

#include <stdlib.h>

int treeH(struct tree *T)
{
    int count_L = -1;
    int count_R = -1;

    if (T != NULL)
        count_L = 1 + treeH(T->l);

    if (T != NULL)
        count_R = 1 + treeH(T->r);

    return count_L > count_R ? count_L : count_R;
}

int solution(struct tree *T)
{
    if (T == NULL)
        return -1;    

    return treeH(T);
}
