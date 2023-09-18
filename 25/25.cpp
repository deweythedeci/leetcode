#include <vector>
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printLList(ListNode* head);

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* a = head;
        ListNode* b;
        if(isLengthEqualOrAboveK(a, k)){
            head = reverseKGroupHelper(a, k);
            b = a;
            a = a->next;
        }
        while(isLengthEqualOrAboveK(a, k)){
            b->next = reverseKGroupHelper(a, k);
            b = a;
            a = a->next;
        }
        return head;
    }
    ListNode* reverseKGroupHelper(ListNode* head, int k){
        ListNode* a = head;
        ListNode* b = a->next;
        ListNode* c = b;
        for(int i = 0; i < k-1; i++){
            c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        head->next = c;
        return a;
    }
    bool isLengthEqualOrAboveK(ListNode* head, int k){
        for(int i = 0; i < k; i++){
            if(head == nullptr){
                return false;
            }
            head = head->next;
        }
        return true;
    }
};

ListNode* vectorToLList(vector<int> v){
    ListNode* l = new ListNode(v.at(0));
    ListNode* tail = l;
    for(int i = 1; i < v.size(); i++){
        tail->next = new ListNode(v.at(i));
        tail = tail->next;
    }
    return l;
}

void printLList(ListNode* head){
    while(head != nullptr){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(int argc, char** argv){
    Solution s = Solution();
    printLList(s.reverseKGroup(vectorToLList({1,2,3,4,5,6,7,8}), 3));
    return 0;
}