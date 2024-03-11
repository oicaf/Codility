/*
Task: https://app.codility.com/programmers/trainings/7/count_bounded_slices/
Score: https://app.codility.com/demo/results/trainingH2MVWT-BQW/

Algorithm:
Using the caterpillar method to isolate sections (slices) that meet the task conditions. The front of 
the track increases by 1 until the task condition is met. When the condition is no longer met, the rear 
of the caterpillar increases by 1, following the front of the caterpillar. During each iteration, the 
min and max of the current interval between the front and rear of the track are determined and the task 
condition is checked. When the front of the track increases by 1 and does not meet the task condition, 
the difference between the current index of the front and rear is calculated and this difference is 
added to the current sum of the segments counted so far. The front starts at index 1 because the first 
element of the array ([0]) is assumed to result in 1 (slice (0,0)). The back ends at the penultimate 
element as the last element by default also gives a result of 1 (slice (N - 1, N - 1)).
*/

int solution(int K, int A[], int N)
{
    int back, front = 1, min, max, minmax, result = 1;

    for(back = 0; back < N - 1; back++)
    {
        min = 1000000000;
        max = -1000000000;
        for(minmax = back; minmax <= front; minmax++)
        {
            min = A[minmax] < min ? A[minmax] : min;
            max = A[minmax] > max ? A[minmax] : max;
        }

        while(front < N)
        {
            if(max - min <= K)
                front++;
            else
                break;

            min = A[front] < min ? A[front] : min;
            max = A[front] > max ? A[front] : max;     
        }

        result += (front - back);
        if(result > 1000000000)
            return 1000000000;
    }

    return result;
}
