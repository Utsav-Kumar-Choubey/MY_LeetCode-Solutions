#include<iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //* M-1: Brute Force | TC: O(n²) | SC: O(1)
        // int n = nums.size();
        // // 2,2,1,1,1,2,2    7 4 baar
        // for(int i=0;i<n;i++){
        //     int count = 1;
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i]==nums[j]) count++;
        //     }
        //     if(count>(n/2)) return nums[i];
        // }
        // return -1;

        //* M-2: Sorting | TC: O(n log n) | SC: O(1)
        // sort(nums.begin(),nums.end());
        // return nums[((nums.size())/2)];

        //* M-3: Hash Map | TC: O(n) | SC: O(n)
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int x : nums){
            mp[x]++;
            if(mp[x] > (n/2)) return x;
        }
        return -1;
     }
};
int main(){

}