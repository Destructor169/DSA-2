#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int tab[2000][2000];

// Returns true if there is a subset
// of set[] with sum equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{
    // Base Cases
    if (sum == 0)
        return true;
    if (n == 0)
        return false;

    if(tab[n-1][sum] != -1)
        return tab[n-1][sum];

    // If last element is greater than sum,
    // then ignore it
    if (set[n - 1] > sum)
        return tab[n-1][sum] = isSubsetSum(set, n - 1, sum);

    // Else, check if sum can be obtained by any
    // of the following:
    // (a) including the last element
    // (b) excluding the last element
    return tab[n-1][sum] = isSubsetSum(set, n - 1, sum)
        || isSubsetSum(set, n - 1, sum - set[n - 1]);
}

// Driver code
int main()
{
    memset(tab, -1, sizeof(tab));
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);

    // Start the timer
    auto start = high_resolution_clock::now();

    if (isSubsetSum(set, n, sum) == true)
        cout << "Found a subset with given sum";
    else
        cout << "No subset with given sum";

    // Stop the timer and calculate the runtime
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Runtime: " << duration.count() << " microseconds" << endl;

    return 0;
}