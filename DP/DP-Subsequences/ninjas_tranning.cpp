#include <bits/stdc++.h>
using namespace std;

int solve(int day, int last, vector<vector<int>> &points){
    if(day == 0){
        int maxi = 0;
        for(int i=0;i<3;i++){
            if(i != last)
            maxi = max(maxi,points[0][i]);
        }
        return maxi;
    }

    int maxi = 0;
    for(int task=0;task<3;task++){
        if(task != last){
            int point = points[day][task] + solve(day-1,task,points);
            maxi = max(maxi,point);
        }
    }
    return maxi;
}

int main(){
    vector<vector<int>> points = {{10,11,19},{4,13,7},{1,8,13}};
    int n = points.size();
    cout<<solve(n-1,-1,points) << endl;

    return 0;
}