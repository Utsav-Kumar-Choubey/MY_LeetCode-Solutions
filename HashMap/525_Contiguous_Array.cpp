#include<iostream>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLen = 0;
        int prefixSum = 0;
        unordered_map<int,int> mp;
        mp[0] = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0) 
                prefixSum--;
            else 
                prefixSum++;
            if(mp.find(prefixSum) != mp.end()){
                int length = i - mp[prefixSum];
                maxLen = max(length, maxLen);
            }
            else {
                mp[prefixSum] = i;
            }
        }
        return maxLen;
    }
};
int main(){

}