/*
Task: https://app.codility.com/programmers/trainings/7/arr_list_len/
Score: https://app.codility.com/demo/results/training92ATYZ-TQ4/

Algorithm:
Starting at index 0, the value of the element at that index is the next index in the link, etc. until 
an index is encountered at which the element is equal to -1. The number of indexes/nodes in the entire 
link is the final result.
*/

int solution(int A[], int N)
{
    int ind = 0, nodes = 1;

    while(A[ind] != -1)
    {
        nodes++;
        ind = A[ind];
    }

    return nodes;
}
