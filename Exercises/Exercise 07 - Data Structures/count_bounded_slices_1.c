/*
Task: https://app.codility.com/programmers/trainings/7/count_bounded_slices/
Score: https://app.codility.com/demo/results/trainingVCEZNA-WJT/

Algorithm:
1. Creating / building a compartmental (segment) tree using the recursive method, where each node is an 
index of a new / additional array with a structure in the form of min and max values - the main node 
(root) starts from index 1.
2. Traversing the entire tree (query function) using a recursive method, searching for slices that meet 
the task assumptions.
3. If the slice meets the condition, the difference between the right and left indexes is added to the 
current result/sum (slice = right - left).
*/

#include <stdlib.h>
#include <limits.h>

struct TreeNode
{
    int min;
    int max;
};

void buildSegmentTree(int arr[], struct TreeNode tree[], int start, int end, int treeNodeIndex)
{
    if (start == end)
    {
        tree[treeNodeIndex].min = arr[start];
        tree[treeNodeIndex].max = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    buildSegmentTree(arr, tree, start, mid, 2 * treeNodeIndex);
    buildSegmentTree(arr, tree, mid + 1, end, 2 * treeNodeIndex + 1);

    tree[treeNodeIndex].min = (tree[2 * treeNodeIndex].min < tree[2 * treeNodeIndex + 1].min) ? tree[2 * treeNodeIndex].min : tree[2 * treeNodeIndex + 1].min;
    tree[treeNodeIndex].max = (tree[2 * treeNodeIndex].max > tree[2 * treeNodeIndex + 1].max) ? tree[2 * treeNodeIndex].max : tree[2 * treeNodeIndex + 1].max;
}

struct TreeNode *createSegmentTree(int arr[], int n)
{
    int treeSize = 4 * n; // Suggested size for a typical array size of n
    struct TreeNode *tree = (struct TreeNode*)malloc(treeSize * sizeof(struct TreeNode));
    buildSegmentTree(arr, tree, 0, n - 1, 1); // Root node is at index 1
    return tree;
}

struct TreeNode query(struct TreeNode tree[], int treeNodeIndex, int start, int end, int left, int right)
{
    if (left > end || right < start)
    {
        struct TreeNode nullNode;
        nullNode.min = INT_MAX;
        nullNode.max = INT_MIN;
        return nullNode;
    }

    if (left <= start && right >= end)
        return tree[treeNodeIndex];

    int mid = (start + end) / 2;
    struct TreeNode leftResult = query(tree, 2 * treeNodeIndex, start, mid, left, right);
    struct TreeNode rightResult = query(tree, 2 * treeNodeIndex + 1, mid + 1, end, left, right);

    struct TreeNode result;
    result.min = (leftResult.min < rightResult.min) ? leftResult.min : rightResult.min;
    result.max = (leftResult.max > rightResult.max) ? leftResult.max : rightResult.max;

    return result;
}

int solution(int K, int A[], int N)
{
    int left, right = 0, count = 0;
    struct TreeNode result;

    struct TreeNode *tree = createSegmentTree(A, N);

    for (left = 0; left < N; left++)
    {
        while (right < N)
        {
            result = query(tree, 1, 0, N - 1, left, right);
            if (result.max - result.min <= K)
                right++;
            else
                break;

            count += (right - left);
            if (count > 1000000000)
                return 1000000000;
        }
    }

    free(tree);
    return count;
}
