#include <stdio.h>
#include <stdlib.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize, FILE* output) {
    int n = obstacleGridSize;
    int m = *obstacleGridColSize;

    int** dp = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dp[i] = (int*)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            dp[i][j] = 0;
        }
    }

    //write your logic here, Fill the dp table correctly, dp[i][j] should contain the number of unique paths to reach the cell (i, j)



    // Print dp table to output file
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(output, "%d ", dp[i][j]);
        }
        fprintf(output, "\n");
    }

    int result = dp[n - 1][m - 1];
    return result;
}

int main() {
    FILE *input, *output, *expectedOutput;
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");

    if (input == NULL || output == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    int m, n;
    fscanf(input, "%d %d", &m, &n);

    int** obstacleGrid = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        obstacleGrid[i] = (int*)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            fscanf(input, "%d", &obstacleGrid[i][j]);
        }
    }

    int obstacleGridColSize = m;
    int result = uniquePathsWithObstacles(obstacleGrid, n, &obstacleGridColSize, output);

    return 0;
}
