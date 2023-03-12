#include<bits/stdc++.h>
using namespace std;
    int helper(int i1, int i2,string word1, string word2,vector<vector<int>> &dp){
        if(i1 < 0 || i2 < 0){
            return 0;
        }
        if(dp[i1][i2] != -1){
            return dp[i1][i2];
        } 

        if(word1[i1] == word2[i2]){
            return dp[i1][i2] =  1 + helper(i1-1,i2-1,word1,word2,dp);
        }

        return dp[i1][i2] = max(helper(i1-1,i2,word1,word2,dp),helper(i1,i2-1,word1,word2,dp));
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int k =  helper(word1.size()-1,word2.size()-1,word1,word2,dp);
        return abs((n-k)+(m-k));
    }
int main(){
    string s1 = "abcd";
    string s2 = "acn";
    cout << minDistance(s1,s2) << endl;    
    return 0;
}