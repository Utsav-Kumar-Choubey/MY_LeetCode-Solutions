#include<iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //* TC - O(n) SC - O(n)
        // Step - 1 -> create the deep copy without random pointer
        Node* dummy = new Node(0);
        Node* tempD = dummy;
        Node* tempO = head;
        while(tempO){
            Node* a = new Node(tempO->val);
            tempD->next = a;
            tempD = tempD->next;
            tempO = tempO->next;
        }
        Node* b = dummy->next;
        Node* a = head;
        
        // Step 2 : Make a map of <original, duplicate>
        unordered_map<Node*,Node*> m;
        Node* tempA = a;
        Node* tempB = b;
        while(tempA){
            m[tempA] = tempB;
            tempA = tempA->next;
            tempB = tempB->next;
        }
        for(auto x : m){
            if(x.first->random != NULL){
                x.second->random = m[x.first->random];
            }
        }
        return b;
    }
};
int main(){

}