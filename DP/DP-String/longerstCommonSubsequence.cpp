#include<iostream>
#include<vector>
using namespace std;
int lcs(string s1, string s2){
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=m;i++) dp[0][i] = 0;
    for(int j=0;j<=n;j++) dp[j][0] = 0;

    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans,dp[i][j]);
            }else{
                dp[i][j] = 0;   
            }
        }
    } 
    return ans;
    
}
int main()
{
    string s1 = "abcd";
    string s2 = "poos";
    cout << lcs(s1,s2) << endl; 
    return 0;
}