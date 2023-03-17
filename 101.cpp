#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* arr_to_tree(int arr[], int len);
TreeNode* arr_to_tree(int arr[], int len, int idx);

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return isMirror(root->left, root->right);
    }
    bool isMirror(TreeNode* a, TreeNode* b) {
        if((a == nullptr) != (b == nullptr)) return false;
        if((a == nullptr) && (b == nullptr)) return true;
        if(a->val != b->val) return false;
        return isMirror(a->left, b->right) && isMirror(a->right, b->left);
    }
};

TreeNode* arr_to_tree(int arr[], int len){
    return arr_to_tree(arr, len, 0);
}
TreeNode* arr_to_tree(int arr[], int len, int idx){
    if(idx >= len || arr[idx] == -1){
        return nullptr;
    }
    TreeNode* root = new TreeNode(arr[idx]);
    root->left = arr_to_tree(arr, len, 2*idx+1);
    root->right = arr_to_tree(arr, len, 2*idx+2);
    return root;
}

int main(int argc, char** argv){
    int arr[argc - 1];
    for(int i = 1; i < argc; i++){
        arr[i - 1] = atoi(argv[i]);
    }
    Solution s = Solution();
    bool out = s.isSymmetric(arr_to_tree(arr, argc - 1));
    cout << out << endl;
    return 0;
}