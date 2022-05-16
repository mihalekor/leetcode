#include <iostream>
#include <iterator>
#include <vector>

// using namespace std;

class Solution
{
public:
  int maxSubArray(std::vector<int> &nums)
  {
    int p1 = 0, p2 = 0, pmax = 0, pmax2 = 0, m0 = 1, m1 = 0;
    int faza = 0;

    // for (auto i : nums)
    for (auto i = nums.begin(); i != nums.end(); ++i, ++m0)
    {
      //начинается с отриц
      if (faza == 0 && *i < 0)
      {
        m1 = *i;
        faza = 1;
        if (*std::next(i) > 0)
          faza = 2;
        continue;
      }
      //начинается с положительных
      else if (faza == 0 && *i > 0)
        faza = 4;

      //сравниваеи отриц
      if (faza == 1 && *i < 0)
      {
        if (*i > m1)
        {
          m1 = *i;
          if (*std::next(i) > 0)
            faza = 2;
          continue;
        }
        if (std::next(i) == nums.end())
          return m1;
        m1 += *i;
      }

      //копим полож
      if (faza == 2 && *i > 0)
      {
        p1 += *i;
        m1 = 0;
        if (*std::next(i) < 0)
        {
          faza = 3;
          continue;
        }
        if (std::next(i) == nums.end())
          faza = 4;
      }

      if (faza == 3 && *i < 0)
      {
        m1 += *i;
        if (*std::next(i) > 0)
        {
          faza = 4;
          continue;
        }
        if (std::next(i) == nums.end())
          faza = 4;
      }

      if (faza == 4 /*&& *i > 0*/)
      {
        p2 += *i;
        if (*std::next(i) < 0 || std::next(i) == nums.end())
          faza = 5;
      }

      //анализ
      if (faza == 5)
      {
        if (p1 <= p2)
          if ((p1 + m1) > 0)
          {
            pmax = p1 + p2 + m1;
            faza = 3;
            p1 = p2;
            p2 = 0;
            m1 = 0;
          }
          else
          {
            pmax = p2;
            faza = 3;
            p1 = p2;
            p2 = 0;
            m1 = 0;
          }

        else if ((p2 + m1) > 0)
        {
          pmax = p1 + p2 + m1;
          faza = 3;
          p1 = p2;
          p2 = 0;
          m1 = 0;
        }
        else
        {
          pmax = p1;
          faza = 3;
          p1 = p2;
          p2 = 0;
          m1 = 0;
        }

        if (pmax > pmax2)
          pmax2 = pmax;
      }
    }

    return pmax2;
  }
};

int main()
{
  std::cout << "Hello World!" << std::endl;

  // std::vector<int> vv = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  // std::vector<int> vv = {1};
  std::vector<int> vv = {-2, -2, -3, 10, -9, -5, 5, 5, 5, -7, 1, -3, 4, -1, 2, 1, -5, 4};
  Solution s;
  std::cout << "Hello World!" << s.maxSubArray(vv) << std::endl;

  return 0;
}
