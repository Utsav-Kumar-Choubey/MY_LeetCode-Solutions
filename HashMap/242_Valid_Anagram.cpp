#include<iostream>
#include <unordered_map>
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
        ==================================================
        LeetCode 242 - Valid Anagram

        Problem:
        https://leetcode.com/problems/valid-anagram/

        Topic:
        Hash Map

        Difficulty:
        Easy

        Approach:
        1. Count the frequency of each character in the first string.
        2. Decrease the frequency using the second string.
        3. If every character's frequency becomes 0, both strings are anagrams.

        Time Complexity: O(n)
        Space Complexity: O(n)

        Date Solved: 27-07-2026
        ==================================================
        */

        if(s.size()!=t.size()) return false;
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