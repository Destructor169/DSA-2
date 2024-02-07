#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

// Taking the matrix as globally

// Check if possible subset with 
// given sum is possible or not
int subsetSum(int a[], int n, int sum)
{ 
    // If the sum is zero it means 
    // we got our expected sum
    if (sum == 0)
        return 1;
        
    if (n <= 0)
        return 0;

    // If the value is not -1 it means it 
    // already call the function 
    // with the same value.
    // it will save our from the repetition.

    // If the value of a[n-1] is
    // greater than the sum.
    // we call for the next value
    if (a[n - 1] > sum)
        return subsetSum(a, n - 1, sum);
    else
    {     
        // Here we do two calls because we 
        // don't know which value is 
        // full-fill our criteria
        // that's why we doing two calls
        return subsetSum(a, n - 1, sum) || 
                    subsetSum(a, n - 1, sum - a[n - 1]);
    }
}

// Driver Code
int main()
{
    // Storing the value -1 to the matrix
    int n = 5;
    int a[] = {1, 5, 3, 7, 4};
    int sum = 12;

    auto start = high_resolution_clock::now(); // Start the timer

    if (subsetSum(a, n, sum))
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;

    auto stop = high_resolution_clock::now(); // Stop the timer
    auto duration = duration_cast<microseconds>(stop - start); // Calculate the duration

    cout << "Runtime: " << duration.count() << " microseconds" << endl;

    /* This Code is Contributed by Ankit Kumar*/
}