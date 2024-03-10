/*
Task: https://app.codility.com/programmers/lessons/5-prefix_sums/min_avg_two_slice/
Score: https://app.codility.com/demo/results/trainingQ3QX2V-QB4/

Algorytm:
It's enough to find the minimum average of slices of length 2 or 3. This is because a slice 
of 4 or larger is basically the sum of slices of length 2 or 3. A composite slice will never have an 
average sum lower than its components.
*/

int solution(int A[], int N)
{
    int i, min_avg_div = 10001, min_avg_mod = 10000, avg_div, avg_mod, start_pos;

    for (i = 0; i < N - 1; i++)
    {
        avg_div = (A[i] + A[i + 1]) / 2;
        avg_mod = (A[i] + A[i + 1]) % 2;
        if (avg_div < min_avg_div)
        {
            min_avg_div = avg_div;
            min_avg_mod = avg_mod;
            start_pos = i;
        }
        else if (avg_div == min_avg_div && avg_mod < min_avg_mod)
        {
            min_avg_mod = avg_mod;
            start_pos = i;
        }

        if (i == N - 2)
            break;

        avg_div = (A[i] + A[i + 1] + A[i + 2]) / 3;
        avg_mod = (A[i] + A[i + 1] + A[i + 2]) % 3;
        if (avg_div < min_avg_div)
        {
            min_avg_div = avg_div;
            min_avg_mod = avg_mod;
            start_pos = i;
        }
        else if (avg_div == min_avg_div && avg_mod < min_avg_mod)
        {
            min_avg_mod = avg_mod;
            start_pos = i;
        }        
    }

    return start_pos;
}
