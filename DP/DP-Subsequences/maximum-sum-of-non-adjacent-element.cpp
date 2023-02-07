#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &v){
    int n = v.size();
    vector<int> dp(n,-1);
    return sum(v,dp,n-1);
}
int sum(vector<int> &v,vector<int> &dp,int n){
    if(n<0) return 0;
    if(n==0) return v[0];
    if(dp[n] != -1) return dp[n];
    int not_pick = 0 + sum(v,dp,n-1); 
    int pick = v[n] + sum(v,dp,n-2);
    return dp[n] = max(pick,not_pick);
}

int robStreet(int n, vector<int> &v){
    vector<int> arr1;
    vector<int> arr2;
    for(int i=0;i<n;i++){
        if(i!=0) arr1.push_back(v[i]);
        if(i!=n-1) arr2.push_back(v[i]);
    }
    int ans1 = solve(arr1);
    int ans2 = solve(arr2);
    return max(ans1,ans2);
}




int main(){
  vector<int> arr{2,1,4,9};
  int n=arr.size();
  cout<<robStreet(n,arr);

    return 0;
}

// int sum(vector<int> &v,vector<int> &dp,int n, int maxi){
//     if(n<0) return 0;
//     if(n==0) return v[0];
//     if(dp[n] != -1) return dp[n];
//     int not_pick = 0 + sum(v,dp,n-1,maxi); 
//     int pick = v[n] + sum(v,dp,n-2,maxi);
//     return dp[n] = max(pick,not_pick);
// }