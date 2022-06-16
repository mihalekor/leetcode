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
    if (height.size() < 2 || height.size() > 100000) return 0;
    int area = 0;
    int len = height.size();
    for (int i = 0; i < len; i++) {
      for (int j = i + 1; j < len; j++) {
        if (height[i] < 0 || height[i] > 10000 || height[j] < 0 ||
            height[j] > 10000)
          return 0;
        // Calculating the max area
        area = max(area, min(height[j], height[i]) * (j - i));
      }
    }
    return area;
  }
};

int main() {
  std::cout << "Hello World!\n" << std::endl;
  vector<int> v{1, 2, 1};

  Solution S;
  cout << S.maxArea(v) << std::endl;

  return 0;
}
