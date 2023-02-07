#include <bits/stdc++.h>
using namespace std;

    int f(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i == 0 && j == 0) dp[i][j] = grid[i][j];
                else{
                int up = grid[i][j];
                if(i>0) up += dp[i-1][j];
                else up += 1e9;
                
                int left = grid[i][j];
                if(j>0) left+=dp[i][j-1];
                else left += 1e9;
                
                dp[i][j] = min(up,left);

                }
            }
        }
    }
    
    
    
    int minSumPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(n,vector<int> (m,-1));
        return f(m-1,n-1,grid,dp);
    }

int main(){

  vector<vector<int> > matrix{{1,3,1},
                            {1,5,1},
                            {4,2,1}};
  
  cout<<minSumPath(matrix) << endl;
    return 0;
}