using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // if(nums == null || nums.size() == 0){
        //     return 0;
        // }
        int pivot = 1;
        vector<int>::iterator begin = nums.begin();
        vector<int>::iterator end = nums.end();
        for(int i = 1; i < nums.size(); i++) {
            if(nums[0] > nums[i]){
                
            }
        }
        if(pivot + 1 == k){
            return nums[pivot];
        }
        if(pivot + 1 < k){
            
        }
    }
};