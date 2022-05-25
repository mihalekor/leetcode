#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  int myAtoi(string s) {
    long double out = 0;
    bool start = false, min = false, pl = false, start2 = false;
    int minus = 1;

    int n10 = 10;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == ' ' && !start) continue;
      start = 1;

      if (s[i] == '+' && !pl) {
        if (min || start2) break;
        pl = 1;
        continue;
      };
      if (s[i] == '-' && !min && !min) {
        if (pl || start2) break;
        minus = -1;
        min = 1;
        continue;
      }

      if ((int)s[i] >= 48 && s[i] <= 57) {
        start2 = 1;
        out *= n10;
        out += (int)s[i] - 48;
      } else
        break;
    }
    out *= minus;
    if (out < -2147483648) return -2147483648;
    if (out > 2147483648 - 1) return 2147483648 - 1;

    return out;
  }
};

int main() {
  std::cout << "Hello World!\n" << std::endl;
  Solution S;
  cout << S.myAtoi("2000000000000000000") << std::endl;

  return 0;
}
