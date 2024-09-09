#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while(l<=r)
        {
            int m = (l+r) / 2;
            if(target > nums[m]) l = m+1;
            else if(target < nums[m]) r = m-1;
            else return m;
        }
        return l;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,3,5,6};
    int target = 7;
    int result = sol.searchInsert(nums, target);
    printf("Result: %d\n", result);
    return 0;
}