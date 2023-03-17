#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* vectorToListNode(vector<int>);
vector<int> listNodeToVector(ListNode*);
void printVector(vector<int>);

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // make a copy of lists
        vector<ListNode*> lists_l(lists);
        removeNullptrs(lists_l);
        // merged llist
        ListNode* merged = nullptr;
        // loop until empty
        while(!lists_l.empty()){
            // find smallest value
            int min = 0;
            for(int i = 1; i < lists_l.size(); i++){
                if(lists_l.at(i)->val < lists_l.at(min)->val){
                    min = i;
                }
            }
            // append to merged
            appendListNode(lists_l.at(min)->val, &merged);
            // remove from llist
            lists_l.at(min) = lists_l.at(min)->next;
            // delete llist from lists if empty
            if(lists_l.at(min) == nullptr){
                lists_l.erase(lists_l.begin() + min);
            }
        }
        return merged;
    }
    // append node with val x to list
    void appendListNode(int x, ListNode** list){
        if(*list == nullptr){
            *list = new ListNode(x);
            return;
        }
        ListNode* list_l = *list;
        while(list_l->next != nullptr){
            list_l = list_l->next;
        }
        list_l->next = new ListNode(x);
    }
    void removeNullptrs(vector<ListNode*>& lists){
        int i = 0;
        while(i < lists.size()){
            if(lists.at(i) == nullptr){
                lists.erase(lists.begin() + i);
            }
            else{
                i++;
            }
        }
    }
};

ListNode* vectorToListNode(vector<int> v){
    ListNode* l = new ListNode(v.at(0));
    ListNode* tail = l;
    for(int i = 1; i < v.size(); i++){
        tail->next = new ListNode(v.at(i));
        tail = tail->next;
    }
    return l;
}

vector<int> listNodeToVector(ListNode* l){
    vector<int> v;
    while(l != nullptr){
        v.push_back(l->val);
        l = l->next;
    }
    return v;
}

void printVector(vector<int> v){
    for(int i : v){
        cout << i << " ";
    }
    cout << endl;
}

int main(int argc, char** argv){
    Solution s;
    vector<ListNode*> lists;
    lists.push_back(vectorToListNode({1,2,3}));
    lists.push_back(nullptr);
    lists.push_back(vectorToListNode({2,4,5}));
    printVector(listNodeToVector(s.mergeKLists(lists)));
}