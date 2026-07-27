#include<iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string str : strs){
            string key = str;
            sort(key.begin(), key.end());
            mp[key].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto x : mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};
int main(){

}