#include<iostream>
using namespace std;
class Solution {
public:
    int rev(int n){
        int r = 0;
        while(n>0){
            r *= 10;
            r += (n % 10);
            n /= 10;
        }
        return r;
    }
    int countNicePairs(vector<int>& nums) {
        //* M-1 Bruete force O(n^2) cannot run
        // int n = nums.size();
        // int count = 0;
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])) 
        //             count++;
        //     }
        // }
        // return count;

        //* M-2 HashMap & Math
        int n = nums.size();
        int count = 0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            nums[i] -= rev(nums[i]);
        }
        for(int i=0;i<n;i++){
            if(m.find(nums[i])!=m.end()){
                count = count % 1000000007;
                count += m[nums[i]];
                m[nums[i]]++;
            }
            else m[nums[i]]++;
        }
        
        return count%1000000007;
    }
};
int main(){

}