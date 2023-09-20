#include <iostream>
#include <vector>
#include <climits>

#define DEBUG 0

using namespace std;

// Code works but is poorly optimized. Backtracking is likely solution to avoid copying iterators. Dynamic programming is a possibility but doesn't seem relevant. 

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int ret = minOperationsHelper(nums, x, nums.begin(), nums.end(), 0);
        return ret == INT_MAX ? -1 : ret;
    }
    int minOperationsHelper(vector<int>& nums, int x, vector<int>::iterator begin, vector<int>::iterator end, int c) {
        #if DEBUG
            cout << "x: " << x << ", b: " << begin - nums.begin() << ", e: " << nums.end() - end << endl;
        #endif
        if (x == 0) { return c; }
        if (begin == end || x < 0) { return INT_MAX; }
        int a, b;
        // TODO replace prev() and end() with backtracking
        if(*begin > *prev(end)){
            a = minOperationsHelper(nums, x - *begin, next(begin), end, c+1);
            b = minOperationsHelper(nums, x - *prev(end), begin, prev(end), c+1);
        }
        else{
            b = minOperationsHelper(nums, x - *prev(end), begin, prev(end), c+1);
            a = minOperationsHelper(nums, x - *begin, next(begin), end, c+1);
        }
        return  a < b ? a : b;
    }
};

int main(int argc, char **argv){
    if(argc < 3){
        cout << "usage: " << argv[0] << " x vector" << endl;
        return 1;
    }
    int x = stoi(argv[1]);
    vector<int> nums = vector<int>();
    for(int i = 2; i < argc; i++){
        nums.push_back(stoi(argv[i]));
    }
    Solution s = Solution();
    cout << s.minOperations(nums, x) << endl;
    return 0;
}