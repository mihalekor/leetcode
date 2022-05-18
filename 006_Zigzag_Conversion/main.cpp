#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

/*
Представляем входящую строку как матрицу с нормальными столбиками
и столбиками с пробелами:

s, numRows:       123456789, 4
    matrix:  1 ' ' 7
             2  6  8
             3  5  9
             4 ' '' '

*/

class Solution {
 public:
  string matrix,  //для преобразования входящей строки в матрицу
      with_spaces, out2;
  char* p;
  string convert(string s, int numRows) {
    for (int i = 0, counter = 0; i < s.size(); ++i, ++counter) {
      if (numRows == 1) return s;

      //заполняем полный столбик
      if (counter < numRows) matrix.push_back(s[i]);
      //начинаем на короткий столбик с пробелами
      else if (counter == numRows) {
        with_spaces.push_back(' ');
        --i;
        //заканчиваем короткий столбик с пробелами
      } else if (counter == numRows + numRows - 1) {
        with_spaces.push_back(' ');
        //реверс для корректонго обращения к строке как к матрице
        reverse(with_spaces.begin(), with_spaces.end());
        matrix.append(with_spaces);
        counter = -1;
        with_spaces.clear();
        --i;
      } else {
        //заполнеяем короткий столбик с пробелами
        with_spaces.push_back(s[i]);
      }
    }
    //Дописываем короткую часть, если строка закончилась на ней
    if (!with_spaces.empty()) {
      for (int i = 0; i < numRows - with_spaces.size(); ++i) matrix.append(" ");
      reverse(with_spaces.begin(), with_spaces.end());
      matrix.append(with_spaces);
    }
    //Дописываем пробелы до конца столбца матрицы, чтобы матрица была полной
    //и к ней было удобно обращаться
    int freeTail = numRows - matrix.size() % numRows;
    if (freeTail != numRows)
      for (int i = 0; i < freeTail; ++i) matrix.append(" ");

    cout << "matrix " << matrix << std::endl;

    //кол-во столбцов
    int columnCount =
        matrix.size() / numRows +
        (matrix.size() % numRows ? 1  //лишнее условие, если матрица полная
                                 : 0);
    p = &matrix[0];
    //обход матрица слева на права, сверху вниз
    for (int i = 0, m = 0, k = 0; i < matrix.size(); ++i, ++k) {
      if (k == columnCount) {
        k = 0;
        ++m;
      }

      if (m == numRows) m = 0;
      //расчёт смещения по строке, чтобы обращаться как к матрице
      int offset = k * numRows + m;
      out2.push_back(p[offset]);
    }
    out2.erase(std::remove(out2.begin(), out2.end(), ' '), out2.end());
    return out2;
  }
};

int main() {
  std::cout << "Hello World!\n" << std::endl;
  Solution S;
  cout << S.convert("PAYPALISHIRING", 3) << std::endl;

  return 0;
}
