#include<iostream>
using namespace std;
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long totalPairs = 1LL * n * (n-1) / 2;
        long long goodPairs = 0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            int value = nums[i] - i;
            if(mp.find(value) != mp.end()){
                goodPairs += mp[value];
            }
            mp[value]++;
        }
        return totalPairs - goodPairs;
    }
};
int main(){

}