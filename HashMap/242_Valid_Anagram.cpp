#include<iostream>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        // * M-1 TC = O(nlogn)
        // if(s.length()!=t.length()) return false;
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // if(s==t) return true;
        // else return false;

        
        // * M-2 TC = O(n) using Hash Map

        /*
        LeetCode 242 - Valid Anagram

        Approach:
        1. Count frequency of characters in first string.
        2. Decrease frequency using second string.
        3. If every frequency becomes zero,
        both strings are anagrams.

        Time Complexity : O(n)

        Space Complexity : O(n)
        */

        if(s.length()!=t.length()) return false;
        unordered_map<char,int> freq;
        // count freqency in first string
        for(char ch : s){
            freq[ch]++;
        }
        // decrease freqency using second string
        for(char ch : t){
            freq[ch]--;
        }
        // check if every freqency becomes 0
        for(auto x : freq){
            if(x.second != 0) return false;
        }
        return true;
    }
};
int main(){

}