/*
Task: https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/
Score: https://app.codility.com/demo/results/trainingZSMHFX-F6H/
*/

struct Results solution(int A[], int N, int K)
{
	int i, j, tmp = 0;
	struct Results result;

	if (N < 2)
	{
		result.A = A;
		result.N = N;
		return result;		
	}
	else
	{
		for (i = 0; i < K; i++)
		{
			for (j = N - 1; j > 0; j--)
			{
				if(j == N - 1)
				{
					tmp = A[j];
					A[j] = A[j - 1];
				}
				else
					A[j] = A[j - 1];
			}
			A[0] = tmp;
		}
		result.A = A;
		result.N = N;
		return result;
	}
}
