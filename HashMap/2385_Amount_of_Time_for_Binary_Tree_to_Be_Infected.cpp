#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class TreeNode {
public: 
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
class Solution {
public:
    void markParent(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& parent){
        if(root==NULL) return;
        if(root->left) parent[root->left] = root;
        if(root->right) parent[root->right] = root;
        markParent(root->left, parent);
        markParent(root->right, parent);
    }
    TreeNode* find(TreeNode* root, int start){
        if(root==NULL) return NULL;
        if(root->val == start) return root;
        TreeNode* left = find(root->left, start);
        if(left) return left;
        else return find(root->right, start);
    }
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* first = find(root, start);
        unordered_map<TreeNode*,TreeNode*> parent;
        markParent(root, parent);
        unordered_set<TreeNode*> isInfected;
        isInfected.insert(first);
        queue<pair<TreeNode*,int>> q;
        q.push({first,0});
        int maxLevel = 0;
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            maxLevel = max(maxLevel, temp.second);
            if(temp.first->left && 
                isInfected.find(temp.first->left)==isInfected.end()){
                q.push({temp.first->left, temp.second+1});
                isInfected.insert(temp.first->left);
            }
            if(temp.first->right && 
                isInfected.find(temp.first->right)==isInfected.end()){
                q.push({temp.first->right, temp.second+1});
                isInfected.insert(temp.first->right);
            }
            if(parent.find(temp.first)!=parent.end() &&
                isInfected.find(parent[temp.first])==isInfected.end()){
                q.push({parent[temp.first], temp.second+1});
                isInfected.insert(parent[temp.first]);
            }
        }
        return maxLevel;
    }
};

int main(){

}