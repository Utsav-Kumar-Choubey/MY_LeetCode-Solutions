#include<iostream>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int left = 0;
        unordered_map<char,int> mp;
        for(int right=0;right<s.length();right++){
            char ch = s[right];
            if(mp.find(ch) != mp.end()){
                left = max(left, mp[ch]+1);
            }
            mp[ch] = right;
            maxLength = max(maxLength, right-left+1);
        }
        return maxLength;
    }
};
int main(){

}