#include<bits/stdc++.h>
using namespace std;

void subString(vector<int> &arr, int n, int idx, vector<int> &ans){
    if(idx == n){
        for(int i=0;i<ans.size();i++){
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }
    // pick
    ans.push_back(arr[idx]);
    subString(arr,n,idx+1,ans);
    //not pick
    ans.pop_back();
    subString(arr,n,idx+1,ans);
}

int main(){
    vector<int> arr = {1,2,3};
    int n = arr.size();
    vector<int> ans;
    subString(arr,n,0,ans);
    return 0;
}