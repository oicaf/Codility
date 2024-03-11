/*
Task: https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_slice_sum/
Score: https://app.codility.com/demo/results/trainingT2PRGJ-N3H/
*/

int solution(int A[], int N)
{
	int i, max_slice = 0;
	long int result = -2147483648;
	
	for (i = 0; i < N; i++)
	{
		if (max_slice + A[i] > 0)
		{
			if (result < 0)
				max_slice = A[i];
			else
				max_slice = max_slice + A[i];
		}
		else
		{
			if (result >= 0)
				max_slice = 0;
			else
				max_slice = A[i];
		}
		result = (max_slice > result) ? max_slice : result;
	}

	return result;
}
