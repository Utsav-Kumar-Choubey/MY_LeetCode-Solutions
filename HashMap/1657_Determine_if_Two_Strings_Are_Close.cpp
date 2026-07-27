#include<iostream>
using namespace std;
class Solution {
public:
    bool closeStrings(string str1, string str2) {

        if(str1.length()!=str2.length()) return false;

        unordered_map<char,int> mp1, mp2;
        for(int i=0;i<str1.length();i++){
            mp1[str1[i]]++;
            mp2[str2[i]]++;
        }

        // comparing map1 and map2 (only chars)
        //only to check if all the character of mp1 are present in mp2 also or not
        for(auto x : mp1){
            char ch = x.first;
            if(mp2.find(ch)==mp2.end()) return false;
        }

        // helper maps (frequencies of frequencies)
        unordered_map<int,int>h1,h2;
        for(auto x : mp1){
            int freq = x.second;
            h1[freq]++;
        }
        for(auto x : mp2){
            int freq = x.second;
            h2[freq]++;
        }

        // comparing helper1 and helper2 maps
        for(auto x : h1){
            int key = x.first;
            if(h2.find(key)==h2.end()) return false;
            if(h2[key]!=h1[key]) return false;
        }
        return true;

        //* Instead of creating helper maps, collect all frequencies into vectors
        // vector<int> freq1, freq2;
        // for (auto x : mp1)
        //     freq1.push_back(x.second);
        // for (auto x : mp2)
        //     freq2.push_back(x.second);
        // sort(freq1.begin(), freq1.end());
        // sort(freq2.begin(), freq2.end());
        // return freq1 == freq2;
    }
};
int main(){

}
