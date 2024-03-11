/*
Task: https://app.codility.com/programmers/trainings/5/parking_bill/
Score: https://app.codility.com/demo/results/trainingXJ456B-AR4/

Algorithm:
1. First, calculate the full hours, if the parking duration was zero full hours, it means that the 
parking lasted a maximum of 1 hour.
2. If parking lasted at least 1 hour, then recalculate the minutes and if the result is more than zero 
minutes, increase the parking time another hour.
3. The final result (bill) always includes 2 (fee) + 3 (for <= the first hour of parking) + 4 times 
depending on the length of parking lasting longer than the first hour.
*/

int solution(char *E, char *L)
{
    int hours, minutes;

    hours = (L[0] - E[0]) * 10 + (L[1] - E[1]);
    if (hours == 0)
        hours = 1;
    else
    {
        minutes = (L[3] - E[3]) * 10 + (L[4] - E[4]);
        if (minutes > 0)
            hours++;
    }

    return 2 + 3 + (hours - 1) * 4;
}
