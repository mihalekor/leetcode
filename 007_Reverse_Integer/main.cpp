#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int reverse(int x) {
    vector<int> masCifr;
    int left, right, ci, count_n = 0;
    long n10 = 10, out = 0;
    do {
      left = x / n10;
      right = x % n10;
      ci = right / (n10 / 10);
      masCifr.push_back(ci);

      n10 *= 10;
      ++count_n;
    } while (left != 0);

    n10 /= 10;
    for (int i = 0; i < masCifr.size(); ++i) {
      n10 /= 10;
      out += masCifr[i] * n10;
    }
    if (out < -2147483648 || out > 2147483648 - 1) return 0;
    return out;
  }
};

//а вот как можно было
/*
class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while(x) {
            res = res*10 + x%10;
            x /= 10;
        }
        return (res<INT_MIN || res>INT_MAX) ? 0 : res;
    }
};
*/

int main() {
  std::cout << "Hello World!\n" << std::endl;
  Solution S;
  cout << S.reverse(1056389759) << std::endl;

  return 0;
}
