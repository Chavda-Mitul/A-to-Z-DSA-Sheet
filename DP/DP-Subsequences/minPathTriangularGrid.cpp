#include <bits/stdc++.h>
using namespace std;
int solve(int i, int j, vector<vector<int>> &grid, int n){
    if(i == n-1){
        return grid[i][j];
    }
        int down = solve(i+1,j,grid,n);
        int diagonal = solve(i+1,j+1,grid,n);
        
        return min(down,diagonal); 

}

int tabulation(int i, int j, vector<vector<int>> &grid, int n){
    vector<vector<int>> dp(n,vector<int>(n,-1));
    for(int i=0;i<n;i++) dp[n-1][i] =grid[n-1][i];

    for(int i=n-2;j>=0;j--){
        for(int j=i;j>=0;j--){
            int down = grid[i][j] + dp[i-1][j];
            int diagonal = grid[i][j] + dp[i-1][j-1];
            dp[i][j] = min(down,diagonal);
        }
    }
    return dp[0][0];
}

int spaceOptimization(int i, int j, vector<vector<int>> &grid, int n){
    vector<int> front(n,-1);
    for(int i=0;i<n;i++) front[i] = grid[n-1][i];

    for(int i=n-2;j>=0;j--){
        vector<int> curr(n);
        for(int j=i;j>=0;j--){
            int down = grid[i][j] + front[j+1];
            int diagonal = grid[i][j] + front[j+1];
            curr[j] = min(down,diagonal);
        }
        front = curr;
    }
}

int main(){
    vector<vector<int>> grid ={{2},
                               {3,4},
                               {6,5,7},
                               {4,1,8,3}};
    int n = grid.size();
    cout << solve(0,0,grid,n) << endl;
    return 0;
}