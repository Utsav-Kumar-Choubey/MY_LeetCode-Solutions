// LeetCode 219 - Contains Duplicate II
// Topic: Hash Map
// Link: https://leetcode.com/problems/contains-duplicate-ii/
#include<iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //* M-1 Bruete-Force TC = O(n^2)
        // int n = nums.size();
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i] == nums[j] && (j-i) <= k) return true;
        //     }
        // }
        // return false;

        //* M-2 HashMap  TC = O(n)
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]) != mp.end()){
                if(i - mp[nums[i]] <= k) return true;
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};
int main(){

}