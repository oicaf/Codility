/*
Task: https://app.codility.com/programmers/lessons/8-leader/equi_leader/
Score: https://app.codility.com/demo/results/training6PFKAD-CKC/

Algorithm:
1. Determining the leader (goldenLeader) in linear O(N) on the example of a lesson.
2. Linearly dividing the O(N) array into two subarrays, starting from A[1] and A[2...N-1] and ending 
with A[1...N-2] and A[N-1].
3. Checking the contents of subtables for the number of leaders, determining the presence of equileaders.
*/

int solution(int A[], int N)
{
	int i, size = 0, value, candidate = -1000000001, leader = -1, count = 0, temp = 0, equileaders = 0;
    
	for (i = 0; i < N; i++)
	{
		if (size == 0)
		{
			size += 1;
      		value = A[i];
    	}
		else
		{
			if (value != A[i])
				size -= 1;
      		else
				size += 1;
    	}
	}

	if (size > 0)
		candidate = value;
  
	for (i = 0; i < N; i++)
	{
		if (A[i] == candidate)
			count += 1;
	}
	
	if (count > N / 2)
		leader = candidate;

	if (leader == -1)
		return 0;
	
	for (i = 1; i < N; i++)
	{
		if ((A[i - 1] == leader && ++temp > i / 2) || (A[i - 1] != leader && temp > i / 2))
			if (count - temp > (N - i) / 2) 
				equileaders++;
	}

	return equileaders;
}
