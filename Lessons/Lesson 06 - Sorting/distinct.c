/*
Task: https://app.codility.com/programmers/lessons/6-sorting/distinct/
Score: https://app.codility.com/demo/results/trainingYYD7JG-P84/
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
	int i, result = 1;
	
	if (N == 0)
		return result = 0;
	
	Sortowanie(A, 0, N - 1);
	
	for (i = 1; i < N; i++)
		if (A[i] != A[i - 1])
			result += 1;
	
	return result;
}
