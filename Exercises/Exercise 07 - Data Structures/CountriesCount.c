/*
Task: https://app.codility.com/programmers/trainings/7/countries_count/
Score: https://app.codility.com/demo/results/trainingM29PEW-PJH/

Algorithm:
Traversing the entire array recursively using the DFS method. For each array element, checks whether it has
already been visited:
- if not, then all neighbors that meet the appropriate condition are visited using the DFS method, marked as
'visited', and after the visit is completed, the 'countries' counter is incremented by 1 (the given country
is "painted"),
- if so, then it means that it belongs to a country "painted" in the previous process, and the next array
element is taken under the consideration and etc.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void dfs(int **A, bool **visited, int r, int c, int N, int M)
{
    int row = r, col = c;

    // moving right
    if ((col + 1 <= M - 1) && A[row][col + 1] == A[row][col] && visited[row][col + 1] == 0)
    {
        col++;
        visited[row][col] = 1;
        dfs(A, visited, row, col, N, M);
        col--;
    }
    // moving down
    if ((row + 1 <= N - 1) && A[row + 1][col] == A[row][col] && visited[row + 1][col] == 0)
    {
        row++;
        visited[row][col] = 1;
        dfs(A, visited, row, col, N, M);
        row--;
    }
    // moving left
    if ((col - 1) >= 0 && A[row][col - 1] == A[row][col] && visited[row][col - 1] == 0)
    {
        col--;
        visited[row][col] = 1;
        dfs(A, visited, row, col, N, M);
        col++;
    }
    // moving up
    if ((row - 1) >= 0 && A[row - 1][col] == A[row][col] && visited[row - 1][col] == 0)
    {
        row--;
        visited[row][col] = 1;
        dfs(A, visited, row, col, N, M);
        row++;
    }

    return;
}

int solution(int **A, int N, int M)
{
    int i, j, countries = 0;

    bool **visited = malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++)
        visited[i] = malloc(M * sizeof(int));

    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            visited[i][j] = 0;

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
            if (visited[i][j] == 0)
            {
                visited[i][j] = 1;
                dfs(A, visited, i, j, N, M);
                countries++;
            }
        }
    }

    return countries;
}
