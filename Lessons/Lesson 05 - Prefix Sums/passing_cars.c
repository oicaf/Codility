/*
Task: https://app.codility.com/programmers/lessons/5-prefix_sums/passing_cars/
Score: https://app.codility.com/demo/results/trainingKF9MQX-MU5/
*/

int solution(int A[], int N)
{
	int i, cond_1 = 0, cond_2 = 0;

	for (i = 0; i < N; i++)
	{
		if (A[i] == 0)
			cond_1 += 1;
		else
			cond_2 += cond_1;
	}
	
	if (cond_2 > 1000000000 || cond_2 < -1000000000)
		return -1;
	else
		return cond_2;
}
