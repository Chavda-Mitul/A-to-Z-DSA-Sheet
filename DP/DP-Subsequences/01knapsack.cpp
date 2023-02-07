#include<bits/stdc++.h>
using namespace std;

 int solve(int idx, int wt[], int val[], int weight, vector<vector<int>> dp){
        if(idx == 0){
            if(weight <= wt[idx]) return 0;
            else return val[idx];
        }
        if(dp[idx][weight] != -1) return dp[idx][weight];
        
        int pick = INT_MIN;
        if(weight >= wt[idx])
        pick = val[idx] + solve(idx-1,wt,val,weight-wt[idx],dp);
        int notPick = 0 + solve(idx-1,wt,val,weight,dp);
        return dp[idx][weight] = max(pick,notPick);
    }
    
int knapSack(int W, int wt[], int val[], int n)
{ 
    vector<vector<int>> dp(n,vector<int>(W+1,-1));
    return solve(n-1,wt,val,W,dp);
}

int tabulation(int n, int wt[], int val[], int weight){
    //analise base case
    vector<vector<int>> dp(n,vector<int>(weight+1,0));
    for(int i=wt[0];i<=weight;i++){
        dp[0][i] = val[0];
    } 

    for(int i=1;i<n;i++){
        for(int j=0;j<=weight;j++){

            int pick = INT_MIN;
            
            if(j >= wt[i])
            pick = val[i] + dp[i-1][j-wt[i]];
            
            int notPick = 0 + dp[i-1][j];
            
            dp[i][j] = max(pick,notPick);
        }
    }

    return dp[n-1][weight];
}


int Space_optimization(int n, int wt[], int val[], int weight){
    //analise base case
    vector<int> priv(weight+1,0), curr(weight,0);
    for(int i=wt[0];i<=weight;i++){
        priv[i] = val[0];
    } 

    for(int i=1;i<n;i++){
        for(int j=0;j<=weight;j++){

            int pick = INT_MIN;
            
            if(j >= wt[i])
                pick = val[i] + priv[j-wt[i]];  
            
            int notPick = 0 + priv[j];
            
            curr[j] = max(pick,notPick);    
        }   
        priv = curr;
    }

    return priv[weight];
}


int main(){
    int wt[] = {4,5,1};
    int val[] = {1,2,3};
    int W = 4;
    int n = 3;
    int ans = knapSack(W,wt,val,n);
    cout << ans << endl;
    cout << Space_optimization(n,wt,val,W) << endl;
    return 0;
}