/*
Task: https://app.codility.com/programmers/lessons/15-caterpillar_method/count_triangles/
Score: https://app.codility.com/demo/results/trainingB8D7BU-B88/
*/

void Sortowanie(int A[], int left, int right)
{
    int i = left;
    int j = right;
    int x = A[(left + right) / 2 ];

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
	int x, y, z, result = 0;
	
	if (N < 3)
		return result;
	
	Sortowanie(A, 0, N - 1);
	
	for (x = 0; x < N - 2; x++)
	{
		z = x + 2;
		
		for (y = x + 1; y < N - 1; y++)
		{
			while (z < N && A[x] + A[y] > A[z] && A[y] + A[z] > A[x] && A[z] + A[x] > A[y])
				z++;
			result += z - y - 1;
		}
	}

	return result;
}
