#include<iostream>
#include <unordered_map>
#include <sstream>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        //* Classe Hash Map interview Question | TC: O(n) | SC: O(n)
        stringstream ss(s);
        vector<string> words;
        string word;
        while(ss >> word){
            words.push_back(word);
        }
        //* words = [[dog], [cat], [cat], [dot]]
        
        if(pattern.length() != words.size()) return false;

        unordered_map<char,string> mp1;
        unordered_map<string,char> mp2;
        for(int i=0;i<pattern.length();i++){
            if(mp1.find(pattern[i]) != mp1.end()){
                if(mp1[pattern[i]] != words[i]) 
                    return false;
            }
            if(mp2.find(words[i]) != mp2.end()){
                if(mp2[words[i]] != pattern[i]) 
                    return false;
            }
            mp1[pattern[i]] = words[i];
            mp2[words[i]] = pattern[i];
            
        }
        return true;
    }
};
int main(){

}