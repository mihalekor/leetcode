#include <iostream>
#include <iterator>
#include <vector>

/*
Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target)

  {
    for (int i = 0; i < nums.size(); ++i) {
      for (int k = i + 1; k < nums.size(); ++k) {
        if (nums[i] + nums[k] == target) return {i, k};
      }
    }
    return {0, 0};
  }
};

main() {
  vector<int> nums = {10, 11, 15, 2, 7};
  int target = 9;
  Solution s;
  cout << target << "=" << s.twoSum(nums, target)[0]
       << s.twoSum(nums, target)[1] << endl;
}