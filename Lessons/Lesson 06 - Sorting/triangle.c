/*
Task: https://app.codility.com/programmers/lessons/6-sorting/triangle/
Score: https://app.codility.com/demo/results/trainingBVG9VT-TEU/
*/

void Sortowanie(int A[], int left, int right)
{
    int i = left;
    int j = right;
    int x = A[(left + right) / 2];
    do
    {
        while (A[ i ] < x)
            i++;
       
        while (A[ j ] > x)
            j--;
       
        if (i <= j)
        {
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
            i++;
            j--;
        }

    } while (i <= j);
   
    if (left < j)
        Sortowanie(A, left, j);
    if (right > i)
        Sortowanie(A, i, right);
}

int solution(int A[], int N)
{
	int i, result = 0;
	unsigned int temp;
	
	if (N < 3)
		return result;
	
	Sortowanie(A, 0, N - 1);
	
	for (i = 0; i < N - 2; i++)
	{
		if (A[i] > 0)
		{
			temp = A[i] + A[i + 1];
			if (temp > A[i + 2])
			{
				temp = A[i + 1] + A[i + 2];
				if (temp > A[i])
				{
					temp = A[i + 2] + A[i];
					if (temp > A[i + 1])
						return result = 1;
				}
			}
		}
	}

	return result;
}
