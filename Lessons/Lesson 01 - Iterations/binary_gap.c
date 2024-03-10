/*
Task: https://app.codility.com/programmers/lessons/1-iterations/binary_gap/
Score: https://app.codility.com/demo/results/trainingPKPN2W-JWA/

Algorithm (cyclically extracting the remainder from division by 2):
1. Eliminate leading zeros if they appear while waiting for the first one.
2. After the first 1 appears and the last one disappears (several 1s may appear in a row), the countdown of zeros begins.
3. The counting of zeros continues until the next one is encountered.
4. If, after encountering another 1, the result of dividing the argument by 2 is 0, it ends with the result of the number of zeros
between ones.
5. If, after encountering another 1, the result of dividing the argument by 2 is not 0, the zeros are counted further between the subsequent 1's, if they occur, because if they do not occur anymore, it ends with the last result.
6. The largest number of zeros between ones is stored in an auxiliary variable.
7. If the argument from the beginning or as a result of division is < 5, it ends immediately with the result 0.
*/

int solution(int N)
{
	int tmp = 0, result = 0;
	
	while (!(N % 2))
		N /= 2;

	do
	{
		if (N < 5)
			break;

		if (tmp > result)
			result = tmp;
		tmp = 0;

		while (N % 2)
		{
			N /= 2;
			if (N < 2)
			{
				result = 0;
				break;
			}				
		}	

		while (!(N % 2))
		{
			tmp++;
			N /= 2;
		}

	} while (N /= 2);
	
	if (tmp > result)
	{
		result = tmp;
		return result;
	}
	else
		return result;
}
