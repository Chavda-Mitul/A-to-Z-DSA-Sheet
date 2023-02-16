#include<iostream>
#include<vector>
using namespace std;

int lcs(string s1, string s2 ,int i1, int i2){
    //base case
    if(i1 < 0 || i2 < 0){
        return 0;
    }

    //it matched 
    if(s1[i1] == s2[i2]){
        return 1 + lcs(s1,s2,i1-1,i2-1);
    }

    // it does not matched 
    return max(lcs(s1,s2,i1-1,i2),lcs(s1,s2,i1,i2-1));
}

int lcsMemoised(string s1, string s2 ,int i1, int i2, vector<vector<int>> &dp){
     //base case
    if(i1 < 0 || i2 < 0){
        return 0;
    }
    if(dp[i1][i2] != -1){
        return dp[i1][i2];
    }
    //it matched 
    if(s1[i1] == s2[i2]){
        return dp[i1][i2] =  1 + lcs(s1,s2,i1-1,i2-1);
    }

    // it does not matched 
    return dp[i1][i2] = max(lcs(s1,s2,i1-1,i2),lcs(s1,s2,i1,i2-1));
}

int lcsTabulation(string s1, string s2){
    int n1 = s1.length() , n2 = s2.length(); 
    vector<vector<int>> dp(n1,vector<int>(n2,0));

    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++){
              //it matched 
            if(s1[i] == s2[j]){
                return dp[i][j] =  1 + dp[i-1][j-1];
            }
            // it does not matched 
            return dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n1][n2-1];
}



int main(){

    string s1 = "acd", s2 = "ced";
    int n1 = s1.length() , n2 = s2.length(); 
    // cout << lcs(s1,s2,n1-1,n2-1) << endl;    
    vector<vector<int>> dp(n1,vector<int>(n2,-1));
    // cout << lcsMemoised(s1,s2,n1-1,n2-1,dp) << endl;
    cout << lcsTabulation(s1,s2) << endl;
    return 0;
}