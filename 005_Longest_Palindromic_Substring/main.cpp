#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSize = 0;
  string out = "";
  string longestPalindrome(string str) {
    //для поиска нечётного палиндрома
    for (int indMiddle = 0; indMiddle < str.length(); ++indMiddle) {
      int leftBorder = indMiddle - 1, rightBorder = indMiddle + 1;
      while (leftBorder >= 0 && rightBorder < str.length() &&
             str[leftBorder] == str[rightBorder]) {
        if (rightBorder - leftBorder > maxSize) {
          maxSize = rightBorder - leftBorder;
          out = str.substr(leftBorder, rightBorder - leftBorder + 1);
        }
        --leftBorder;
        ++rightBorder;
      }
    }

    //для поиска чётно палиндрома
    for (int indMiddle = 0; indMiddle < str.length(); ++indMiddle) {
      int leftBorder = indMiddle, rightBorder = indMiddle + 1;
      while (leftBorder >= 0 && rightBorder < str.length() &&
             str[leftBorder] == str[rightBorder]) {
        if (rightBorder - leftBorder > maxSize) {
          maxSize = rightBorder - leftBorder;
          out = str.substr(leftBorder, rightBorder - leftBorder + 1);
        }
        --leftBorder;
        ++rightBorder;
      }
    }
    if (out == "") out = str[0];
    return out;
  }
};

int main() {
  std::cout << "Hello World!\n" << std::endl;
  Solution S;
  cout << S.longestPalindrome(
              "bkuadixhrtfehvbjjzojfyhuqyckdeilnftnklylyssbjivhvnplrzwrgcnrci"
              "ypv"
              "acbhdnglflipnlpzgivjfieunhzeaytshrintdwhbvbkhbsqbjxwhqrlneiwkm"
              "ccd"
              "nfcvapmtqihzyyoiaoqgtxkpbqqdboaxmmsdjxvdrwbhdnemqmsikoksfvjjov"
              "rbg"
              "dtfgmhgryvvpunzrsluqzibsvyubyhqevpnfnszzriljpmoevpqacbvdcsgfzm"
              "nkh"
              "nshsvynxxncqyjxqazcttkvjnkuvykgdrquybvlpwzladpetocuphzkgfuutqc"
              "bnt"
              "twjmkkwbmbidcyauopcxmsarodcqabirbawtlgsytlflsiolxjghjmqrymadpz"
              "aet"
              "cchyvkaezeavjemubbquclhcjcmbwxphllhfnzfyewpyyiirgnohylfbtfddeo"
              "hti"
              "frqiiwpdtyqjyemqjlnpcwlsylxjuxtnmcrpdznbzschmnjxnldxpkbrikpfsf"
              "whs"
              "arrfjueubvnztlwmognapvxwelyvueheqxtncpxhzwplaxqqrbmfmmqhohucxi"
              "nxi"
              "dxzhndvstideuwrisjgpwkgvsdxmlnfgqzzksflmjzckkyutrwptfvcawfbvqx"
              "lzt"
              "stpoitdepexxiqtsdtjmssqbdinalsqkjjqkgilbfxajninuclquszwbmstcdb"
              "ywf"
              "hhnierqsegafyfqzvmqockcowfqwbgfxvdxbqobditvowhtdeptljetgj")
       << endl;

  return 0;
}
