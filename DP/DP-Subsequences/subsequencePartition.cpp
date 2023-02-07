#include<bits/stdc++.h>
using namespace std;

 bool solve(int idx, int n, int k, vector<int> &nums){
        if(k == 0) return true;
        if(idx == 0) {
            return nums[0] == k;
        }

        bool notTaken = solve(idx-1,n,k,nums);
        bool taken = false;
        if(nums[idx] < k){
            taken = solve(idx-1,n,k-nums[idx],nums);
        }
        return notTaken || taken;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i=0;i<n;i++){
            totalSum += nums[i];
        }
        int k = totalSum/2;
        if(totalSum % 2 != 0){
            return false;
        }
        cout << totalSum << endl;
        vector<vector<int>> dp(n+1,vector<int> (n,-1));             
        return solve(n-1,n,k,nums);
    }

int main(){
    vector<int> nums = {3,3,3,4,5};
    cout << canPartition(nums) << endl;

    return 0;
}