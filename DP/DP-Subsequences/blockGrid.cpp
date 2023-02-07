#include <bits/stdc++.h>
using namespace std;

int mazeObstaclesUtil(int i, int j, vector<vector<int >> &maze, vector<vector<int>> &dp){
    if(i == 0 && j == 0){
        return 1;
    }
    if(i < 0 || j < 0){
        return 0;
    }

    int up = 0, left = 0;
    if(maze[i][j] != 1){
        up = mazeObstaclesUtil(i-1,j,maze,dp);
    }
    if(maze[i][j] != 1){
        left = mazeObstaclesUtil(i,j-1,maze,dp);
    }

    return dp[i][j] = up + left;
}

int mazeObstacles(int n, int m, vector<vector<int> > &maze){
    vector<vector<int> > dp(n,vector<int>(m,-1));
    return mazeObstaclesUtil(n-1,m-1,maze,dp);
    
}

int main(){
  vector<vector<int> > maze{{0,0,0},
                            {0,1,0},
                            {0,0,0}};
                            
  int n = maze.size();
  int m = maze[0].size();
  
  cout<<mazeObstacles(n,m,maze) << endl;

    return 0;
}