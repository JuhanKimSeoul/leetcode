#include <vector>
#include <iostream> // Use iostream instead of printf for consistency with C++ standard library

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        int left_product = 1;
        for (int i = 0; i < nums.size(); i++) {
            ans[i] *= left_product;
            left_product *= nums[i];
        }

        int right_product = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            ans[i] *= right_product;
            right_product *= nums[i];
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4}; 
    vector<int> result = sol.productExceptSelf(nums);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}