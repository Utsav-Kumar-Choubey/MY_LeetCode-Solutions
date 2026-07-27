#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& arr) {
        unordered_map<int,int> freq;
        for(int x : arr){
            freq[x]++;
        }
        vector<int> ans;
        for(int num=100;num<=998;num+=2){
            int hundreds = num / 100;
            int tens = (num/10) % 10;
            int ones = num % 10;

            unordered_map<int,int> need;
            need[hundreds]++;
            need[tens]++;
            need[ones]++;

            bool possible = true;
            for(auto x : need){
                if(x.second > freq[x.first]){
                    possible = false;
                    break;
                }
            }
            if(possible){
                ans.push_back(num);
            }
        }
        return ans;
    }
};
int main(){

}