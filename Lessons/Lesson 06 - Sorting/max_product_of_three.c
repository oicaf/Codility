/*
Task: https://app.codility.com/programmers/lessons/6-sorting/max_product_of_three/
Score: https://app.codility.com/demo/results/training43ET2Y-GZ8/
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
	int temp = 0, result;
	
	Sortowanie(A, 0, N - 1);

	result = A[N - 1] * A[N - 2] * A[N - 3];
	
	if (A[0] < 0 && A[1] < 0)
		temp = A[0] * A[1] * A[N - 1];
	if (result < temp)
		result = temp;
	
	return result;
}
