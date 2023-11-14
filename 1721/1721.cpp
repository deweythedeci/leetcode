#include <iostream>
#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ~ListNode() { delete next; }
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* node_a = head;
        ListNode* node_b = head;
        // increment node_a to kth node
        for(int i = 1; i < k; i++){
            node_a = node_a->next;
        }
        // increment node_b to size-kth node
        for(ListNode* node_i = node_a->next; node_i != nullptr; node_i = node_i->next){
            node_b = node_b->next;
        }
        // swap node values
        int tmp = node_a->val;
        node_a->val = node_b->val;
        node_b->val = tmp;
        return head;
    }
};

void printLList(ListNode* head){
    if(head == nullptr) std::cout << "empty list" << std::endl;
    for(ListNode* node = head; node != nullptr; node = node->next){
        std::cout << node->val << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char** argv){
    // read input params
    if(argc < 3){
        std::cout << "usage: " << argv[0] << " size k" << std::endl;
        return 1;
    }
    int size = atoi(argv[1]);
    int k = atoi(argv[2]);
    // generate linked list
    ListNode* head = new ListNode(size);
    for(int i = size-1; i > 0; i--){
        head = new ListNode(i, head);
    }
    // print list
    printLList(head);
    // perform swap
    Solution s = Solution();
    s.swapNodes(head, k);
    // reprint list
    printLList(head);
    // clean up memory
    delete head;
    return 0;
}