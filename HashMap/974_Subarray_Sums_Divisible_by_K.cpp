#include<iostream>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        //* M-1 Bruete Force | TC : O(n²) | SC : O(1) 
        // int count = 0;
        // for(int i=0;i<nums.size();i++){
        //     int prefixSum = 0;
        //     for(int j=i;j<nums.size();j++){
        //         prefixSum += nums[j];
        //         if(prefixSum % k == 0) count++;
        //     }
        // }
        // return count;


        //* M-2 Hash Map | TC : O(n)
        int count = 0;
        int prefixSum = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        for(int i=0;i<nums.size();i++){
            prefixSum += nums[i];
            int remainder = ((prefixSum % k) + k) % k;
            if(mp.find(remainder) != mp.end()){
                count += mp[remainder];
            }
            mp[remainder]++;
        }
        return count;
    }
};
int main(){

}