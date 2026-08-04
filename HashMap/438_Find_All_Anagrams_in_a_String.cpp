#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        
        unordered_map<char,int> target;
        unordered_map<char,int> window;
        for(char ch : p){
            target[ch]++;
        }

        int left = 0;
        for(int right=0;right<s.length();right++){

            window[s[right]]++;

            if(right-left+1 > p.length()){
                window[s[left]]--;
                if(window[s[left]] == 0)
                    window.erase(s[left]);
                left++;
            }

            if(right-left+1 == p.length()){
                if(window == target) 
                    ans.push_back(left);
            }
        }
        return ans;
    }
};
int main(){

}