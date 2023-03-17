#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
    void quickSort(vector<int>& nums, int lo, int hi){
        if(lo < hi){
            int p = partition(nums, lo, hi);
            quickSort(nums, lo, p-1);
            quickSort(nums, p+1, hi);
        }
    }
    int partition(vector<int>& nums, int lo, int hi){
        swap(nums[rand() % (hi - lo + 1) + lo], nums[hi]);
        int p = nums[hi];
        int j = lo;
        for(int i = lo; i < hi; i++){
            if(nums[i] < p){
                swap(nums[i], nums[j]);
                j++;
            }
        }
        swap(nums[j], nums[hi]);
        return j;
    }
};

template<typename T>
void printVector(vector<T>& v){
    for(T elem : v){
        cout << elem << " ";
    }
    cout << endl;
}

int main(int argc, char** argv){
    vector<int>* nums = new vector<int>();
    for(int i = 1; i < argc; i++){
        nums->push_back(atoi(argv[i]));
    }
    Solution* s = new Solution();
    s->sortArray(*nums);
    printVector(*nums);
    return 0;
}