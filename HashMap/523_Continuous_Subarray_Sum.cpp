#include<iostream>
using namespace std;
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        long long prefixSum = 0;
        unordered_map<int,int> mp;
        mp[0] = -1;
        for(int i=0;i<nums.size();i++){
            prefixSum += nums[i];
            int rem = ((prefixSum % k) + k) % k;
            if(mp.find(rem) != mp.end()){
                if(i - mp[rem] >= 2) return true;
            }
            else {
                mp[rem] = i;
            }
        }
        return false;
    }
};
int main(){

}