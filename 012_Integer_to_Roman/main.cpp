#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

/*class Solution {
 public:
  int maxArea(vector<int>& height) {
    int a;
    long max = 0;

    if (height.size() < 2 || height.size() > 10000) return 0;

    for (int i = 0; i < height.size() - 1; ++i)
      for (int m = i + 1; m < height.size(); ++m) {
        if (height[i] < 0 || height[i] > 10000 || height[m] < 0 ||
            height[m] > 10000)
          return 0;

        if (height[i] < height[m])
          a = height[i];
        else
          a = height[m];
        int temp = a * (m - i);

        if (temp > max) max = temp;
      }
    return max;
  }
};*/

class Solution {
 public:
  int maxArea(vector<int>& height) {
    int a, iMax;
    long max = 0, maxSum = 0;
    map<int, int> mp;

    if (height.size() < 2 || height.size() > 10000) return 0;

    for (int i = 0; i < height.size(); ++i) {
      if (height[i] > max) max = height[i], iMax = i;

      if (height[i] < 0 || height[i] > 10000) return 0;
    }

    for (int i = 0; i < height.size(); ++i) {
      int temp = height[i] * (iMax - i);

      if (temp < 0) temp *= -1;

      if (temp > maxSum) maxSum = temp;
    }
    return maxSum;
  }
};

int main() {
  std::cout << "Hello World!\n" << std::endl;
  vector<int> v{1, 2, 1};

  Solution S;
  cout << S.maxArea(v) << std::endl;

  return 0;
}
