/*
Task: https://app.codility.com/programmers/lessons/3-time_complexity/perm_missing_elem/
Score: https://app.codility.com/demo/results/trainingUSPYGT-GK6/

Algorithm:
The first iteration is XOR through all elements of the array and then (second iteration) XOR the result from the first iteration by
all scope elements.
*/

int solution(int A[], int N)
{
	int i, result = 0;
	
	for (i = 0; i < N; i++)
		result ^= A[i];

	for (i = 1; i <= N + 1; i++)
		result ^= i;

	return result;
}
