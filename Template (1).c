#include <stdio.h>
#include <stdlib.h>

int mis(int root, int parent, int** adjList, int* dp, int* dpChildren) {
    /* adjList refers to the adjacency list which is 0-indexed and has the first element of every list as the length of the list (equivalent to the degree of the vertex),
    * parent is initially passed as -1,
    * fill dp[i] (notice that the return statement already handles this) with the answer (|MIS|) for the subtree of node i,
    * fill dpChildren[i] with the answer for the immediate children of the node i,
    * result should contain the final |MIS| for the tree,
    * feel free to make additional functions as might be required be your solution.
    */
    int result = 0;

    // write your code here


    return dp[root] = result;
}

int main() {
    FILE *input, *output, *expectedOutput;
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");

    if (input == NULL || output == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    int n;
    fscanf(input, "%d", &n);

    int** adjList = (int**)malloc(n * sizeof(int*));
    int edges[2*(n-1)], degree[n], dp[n], dpChildren[n];
    for (int i = 0; i < n; i++) {
        degree[i] = 0;
        dp[i] = 0;
        dpChildren[i] = 0;
    }
    for (int i = 0; i < n-1; i++) {
        fscanf(input, "%d %d", &edges[2*i], &edges[2*i+1]);
        degree[edges[2*i]]++;
        degree[edges[2*i+1]]++;
    }
    for (int i = 0; i < n; i++) {
        adjList[i] = (int *) malloc((degree[i] + 1) * sizeof(int));
        adjList[i][0] = degree[i];
    }
    for (int i = 0; i < n-1; i++) {
        adjList[edges[2*i]][degree[edges[2*i]]] = edges[2*i+1];
        adjList[edges[2*i+1]][degree[edges[2*i+1]]] = edges[2*i];
        degree[edges[2*i]]--;
        degree[edges[2*i+1]]--;
    }
    int result = mis(0, -1, adjList, dp, dpChildren);
    for (int i = 0; i < n; i++) {
        fprintf(output, "%d ", dp[i]);
        fprintf(output, " ");
    }
    free(adjList);
    return 0;
}
