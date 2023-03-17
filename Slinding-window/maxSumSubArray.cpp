#include <bits/stdc++.h>
using namespace std;

long maximumSumSubarray(int k, vector<int> &arr, int N)
{
    long int j, i = 0, sum = 0, maxi = INT_MIN;
    for (j = 0; j < k; j++)
    {
        sum += arr[j];
    }

    while (j < N)
    {
        maxi = max(maxi, sum);
        i++;
        j++;
        sum = sum - arr[i] + arr[j];
    }
    return maxi;
}

int main()
{
    vector<int> arr = {100, 200, 300, 400};
    int n = arr.size();
    int k = 2;
    cout << maximumSumSubarray(k, arr, n) << endl;
    return 0;
}