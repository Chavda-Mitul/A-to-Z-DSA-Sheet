#include<bits/stdc++.h>
using namespace std;

int railFence(int n, int key, string pt){
    vector<vector<int>> matrix(n,vector<int>(key,-1));
    int j = 0;
    while(j<n){
        for(int i=0;i<key;i++){
            if(i%2==0){
                if(i == 0){
                matrix[0][j] = pt[j];
                j++;
                }else{
                    matrix[2][j] = pt[j];
                    j++;
                }
            }else{
                matrix[1][j] = pt[j];
                j++;
            }
        }
    }
}
int main(){
    return 0;
}