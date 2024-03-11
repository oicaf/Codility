/*
Task: https://app.codility.com/programmers/trainings/3/socks_laundering/
Score: https://app.codility.com/demo/results/trainingVDKB9M-S57/

Algorithm:
1. Creating two auxiliary tables for counting and sorting the number of clean and dirty socks according 
to color/marking.
2. The first inspection/scan of socks involves replacing clean socks with full pairs if it is possible 
to remove one piece of sock from the dirty ones of the same color, which means that such a sock replenishes 
the missing pair and takes up space in the washing machine.
3. The second inspection/scan consists in finally supplementing clean pairs with dirty pairs, and if it 
is not possible to complete full pairs of clean and dirty ones of the same color, one space in the washing 
machine is freed up for another/next occasion so that one sock without a pair does not take up unnecessary 
space. space in the washing machine, because perhaps this one space will be used when a sock appears 
without a pair of another color to complement it.
4. Finally, all completed clean and dirty socks are added up, but only full pairs are counted, after 
which the number is divided by two, which means the maximum number of pairs of socks possible.
*/

int solution(int K, int C[], int N, int D[], int M)
{
    int sock, count_clean[51] = {0}, count_dirty[51] = {0};

    for (sock = 0; sock < N; sock++)
        count_clean[C[sock]]++;

    for (sock = 0; sock < M; sock++)
        count_dirty[D[sock]]++;

    sock = 0;
    while (K !=0 && sock++ < 50)
    {
        if (count_clean[sock] % 2 != 0 && count_dirty[sock] > 0)
        {
            count_clean[sock]++;
            count_dirty[sock]--;
            K--;
        }
    }

    sock = 0;
    while (K !=0 && sock++ < 50)
    {
        if (count_dirty[sock] > 0)
        {
            if (K <= count_dirty[sock])
            {
                count_clean[sock] += K;
                K = 0;
            }
            else
            {
                count_clean[sock] += count_dirty[sock];
                K -= count_dirty[sock];                
            }
        
            if (count_clean[sock] % 2 != 0)
            {
                count_clean[sock]--;
                K++;
            }
        }
    }

    int socks = 0;
    for (sock = 1; sock <= 50; sock++)
    {
        if (count_clean[sock] % 2 == 0)
            socks += count_clean[sock];
        else
            socks += count_clean[sock] - 1;
    }

    return socks / 2;
}
