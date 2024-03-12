/*
Task: https://app.codility.com/programmers/task/prefix_suffix_set/
Score: https://app.codility.com/demo/results/training86RMAG-N4P/
*/

int solution(int A[], int N)
{
    int i, j, to, from, occur = 0, set = 0;

    for (to = 0; to < N; to++)
    {
        for (from = 0; from < N; from++)
        {
            for (i = 0; i <= to; i++)
            {
                occur = 0;
                for (j = from; j < N; j++)
                {
                    if (A[i] == A[j])
                    {
                        occur = 1;
                        break;
                    }
                }
                if (occur == 0)
                    break;
            }
            if (occur == 0)
                break;
            
            for (i = from; i < N; i++)
            {
                occur = 0;
                for (j = 0; j <= to; j++)
                {
                    if (A[i] == A[j])
                    {
                        occur = 1;
                        break;
                    }
                }
                if (occur == 0)
                    break;                
            }
            if (occur == 1)
                set++;  
        }
    }

    return (set > 1000000000) ? 1000000000 : set;
}
