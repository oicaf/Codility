/*
Task: https://app.codility.com/programmers/trainings/9/count_conforming_bitmasks/
Score: https://app.codility.com/demo/results/trainingMG5UAU-U9B/

Algorithm:
Counting zeros in each 30-bit mask (A, B and C) separately. The number of zeros in each mask means the 
number of 30-bit masks matching a given mask, i.e. two to the power of the number of zeros counted means 
the number of such combinations. Then sum these three results (powers), which gives the total number of 
30-bit masks matching the three masks A, B and C. Then you will remove the repetitions, because some 
masks may be repeated even several times. Removing repetitions involves counting zeros for each 
combination separately, which is an OR of each with each, i.e. A OR B, A OR C and B OR C. Two to the 
power of the number of counted zeros means the number of such combinations which is subtracted from the 
previous sum each time. . Finally, the number of zeros counted for the simultaneous OR combination of 
all three masks, i.e. A OR B OR C, is added to the total sum, as in extreme cases as follows:
A = 0000b
B = 0000b
C = 0000b
and
A = 1111b
B = 1111b
C = 1111b
you can see it and you can understand the mechanism.
*/

#include <math.h>

int power2zeros(int d)
{
	int zeros = 0;
	for (int i = 0; i < 30; i++)
	{
		if (d % 2 == 0)
			zeros++;
		d = d >> 1;
	}

	return pow(2, zeros);
}

int solution(int A, int B, int C)
{
	int count = 0;

	count += power2zeros(A);
	count += power2zeros(B);
	count += power2zeros(C);

	count -= power2zeros(A | B);
	count -= power2zeros(A | C);
	count -= power2zeros(B | C);
	count += power2zeros(A | B | C);

	return count;
}
