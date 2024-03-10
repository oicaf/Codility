/*
Task: https://app.codility.com/programmers/lessons/5-prefix_sums/count_div/
Score: https://app.codility.com/demo/results/trainingMNDKXJ-YYT/
*/

int solution(int A, int B, int K)
{
    int inclusive = (A % K == 0) ? 1 : 0;
    return (B / K) - (A / K) + inclusive;
}
