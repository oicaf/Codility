// Task: https://app.codility.com/programmers/lessons/3-time_complexity/frog_jmp/
// Score: https://app.codility.com/demo/results/training7DGUYH-SS8/

int solution(int X, int Y, int D)
{
	int result;
	
	result = (Y - X) / D; // results from the formula: X + number of steps * D >= Y
	if ((Y - X) % D > 0) // If there is any remainder after division, round up
		result += 1;

	return result;
}
