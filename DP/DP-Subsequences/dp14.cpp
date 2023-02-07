#include <bits/stdc++.h>
using namespace std;

int  f(int pat[], int i, int sum, vector<vector<int>> &dp)
{
    if(sum == 0) return 1;

    if(i == 0) return pat[i] == sum;

    if(dp[i][sum] != -1) return dp[i][sum];
    
    int pick = 0;
    if(pat[i] <= sum)
    pick = f(pat, i-1, sum - pat[i],dp);
    int notPick = f(pat, i-1, sum, dp);
    return dp[i][sum] = pick + notPick;	
}


int tabulation(int arr[],int sum, int n){
    vector<vector<int >> dp (n,vector<int>(sum+1));
    for(int i=0;i<n;i++) dp[i][0] = 1;
    dp[0][arr[0]] = 1;

    for(int i=1;i<n;i++){
        for(int s=0;s<=sum;s++){
            int pick = 0;
            if(arr[i] <= s)
                pick = dp[i-1][s - arr[i]];

            int notPick = dp[i-1][s];

            dp[i][s] = pick + notPick;	
        }
    }
    return dp[n-1][sum];
}


int main()
{
	int n = 3;
	int sum = 1;
	int pat[] = {1,0,0};

    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
	int ans = f(pat,n-1         ,sum,dp);        
	cout << ans << endl;
	return 0;
}


// class Solution{
//     int mod = 1e9 + 7;
//     int dfs(int i, int t, int arr[], vector<vector<int>> &dp) {
//         if(!i){
//             if(!t && !arr[0]) return 2;
//             if(!t) return 1;
//             return arr[0] == t;
//         }
//         if(dp[i][t] != -1) return dp[i][t];
        
//         int notPick = dfs(i - 1, t, arr, dp);
//         int pick = arr[i] <= t ? dfs(i - 1, t - arr[i], arr, dp) : 0;
        
//         return dp[i][t] = (pick + notPick) % mod;
//     }

// 	public:
// 	int perfectSum(int arr[], int n, int sum) {
//         vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
//         return dfs(n - 1, sum, arr, dp);
// 	}
// };
