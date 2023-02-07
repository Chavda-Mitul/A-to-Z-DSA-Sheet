#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j,vector<vector<int>>& matrix,vector<vector<int>> &dp){
    if(i == 0) return matrix[i][j];

    if(j<0 || j>=matrix[0].size()) return 0;

    int one = solve(i-1,j,matrix,dp) + matrix[i][j];
    int two = solve(i-1,j+1,matrix,dp)+ matrix[i][j];
    int three = solve(i-1,j-1,matrix,dp) + matrix[i][j];
    
    return max(max(one,two),three); 
}

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(matrix.size(),vector<int>(matrix.size(),-1));
    int mini = 0;

    for(int j=0;j<m;j++)
    mini = max(mini,solve(n-1,j,matrix,dp)); 
    return mini;  
}

int main()
{
    vector<vector<int> > matrix{{1,2,10,4},
                              {100,3,2,1},
                              {1,1,20,2},
                              {1,2,2,1}};
    cout << minFallingPathSum(matrix) << endl;

    return 0;
}