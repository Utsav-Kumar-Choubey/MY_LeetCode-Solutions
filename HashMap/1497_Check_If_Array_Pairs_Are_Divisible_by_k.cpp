#include<iostream>
using namespace std;
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        // Count frequency of remainders
        for(int num : arr){
            int rem = ((num%k)+k) % k;
            mp[rem]++;
        }
        for(auto x : mp){
            int rem = x.first;
            if(rem==0){
                if(mp[0]%2 != 0) return false;
            }
            else if(2*rem == k){
                if(mp[rem]%2 != 0) return false;
            }
            else {
                if(mp[rem] != mp[k-rem]) return false;
            }
        }
        return true;
    }
};
int main(){

}