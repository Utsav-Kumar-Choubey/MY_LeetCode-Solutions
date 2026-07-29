#include<iostream>
using namespace std;
class Solution {
public:
    static bool cmp(pair<char,int> a, pair<char,int> b){
        return a.second > b.second;
    }
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        vector<pair<char,int>> v;
        for(char ch : s){
            mp[ch]++;
        }
        for(auto x : mp){
            v.push_back(x);
        }
        sort(v.begin(), v.end(), cmp);
        string ans = "";
        for(auto x : v){
            for(int i=0;i<x.second;i++){
                ans += x.first;
            }
        }
        return ans;
    }
};
int main(){

}