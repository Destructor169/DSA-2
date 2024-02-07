#include <iostream>
using namespace std;

int maxSubarraySum(int arr[], int n){
    int maxi = INT_MIN;
    int curr = 0;
    for(int i = 0; i<n; i++){
        if(curr < 0){
            curr = 0;
        }
        curr += arr[i];
        maxi = max(maxi, curr);
    }
    return maxi;
}

int main(){
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n =sizeof(arr)/sizeof(arr[0]);
    int maxSum = maxSubarraySum(arr, n);
    cout <<"The maximum Subarray sum is:"<< maxSum<< endl;
    return 0;
}