/*
Task: https://app.codility.com/programmers/task/falling_disks/
Score: https://app.codility.com/demo/results/training7QGU7W-3VR/

Algorithm:
1. Searching in a given range, from the top to the bottom of the well, for the smallest clearance / hole 
with its index.
2. Checking the disks one by one whether they pass through the hole and:
- if so, the counter of disks falling into the well is increased and at the same time the size of the 
array representing the depth of the well is decreased,
- if not, only the size of the array representing the well depth is reduced,
3. If the disk does not fit in the current smallest hole, then:
- if the bottom of the well is below the index of the smallest hole, the size of the table (well) is 
reduced cyclically by 1 until the level of the bottom of the well is equal to the index of the smallest 
hole, then the smallest clearance / hole with its index is searched again in a new / smaller range,
- if the bottom of the well is above the index of the smallest hole, the smallest clearance/hole is 
immediately searched again along with its index in a new/smaller range,
4. Repeating points 2 - 3 until the disks are exhausted or the entire well is filled (no space for 
additional disks), depending on what happened first, and the current number of disks placed in the well 
is returned.
*/

int solution(int A[], int N, int B[], int M)
{
    int i, j = 0, min_ring_diam = 0, min_ring_idx = N;

    while (j < M && N > 0)
    {
        if (N <= min_ring_idx && B[j] > min_ring_diam)
        {
            min_ring_diam = 1000000000;
            for (i = 0; i < N; i++)
            {
                if (A[i] < min_ring_diam)
                {
                    min_ring_diam = A[i];
                    min_ring_idx = i;
                }
            }
        }

        if (B[j] <= min_ring_diam)
        {
            j++;
            N--;
        }
        else
            N--;
    }

    return j;
}
