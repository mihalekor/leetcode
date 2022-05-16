#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isPoli(string s) {
    int size = s.size();
    for (int i = 0; i < size / 2; ++i) {
      if (s[i] != s[size - i - 1]) return false;
    }

    return true;
  };

  int maxSize = 0;
  string out = "";
  string longestPalindrome(string s) {
    for (int i = 0; i < s.size(); ++i) {
      char symbol = s[i];
      if (s.size() - i <= maxSize) break;

      int endstr = s.rfind(symbol);
      while (endstr != i) {
        if (endstr - i + 1 <= maxSize) break;
        string subs = s.substr(i, endstr - i + 1);
        if (isPoli(subs)) {
          if (subs.size() > maxSize) {
            maxSize = subs.size();
            out = subs;
          }
          break;
        } else
          endstr = s.rfind(symbol, endstr - 1);
      }
    }
    if (out == "") out = s[0];
    return out;
  }
};

int main() {
  std::cout << "Hello World!\n" << std::endl;
  Solution S;
  cout
      << S.longestPalindrome(
             "bkuadixhrtfehvbjjzojfyhuqyckdeilnftnklylyssbjivhvnplrzwrgcnrciypv"
             "acbhdnglflipnlpzgivjfieunhzeaytshrintdwhbvbkhbsqbjxwhqrlneiwkmccd"
             "nfcvapmtqihzyyoiaoqgtxkpbqqdboaxmmsdjxvdrwbhdnemqmsikoksfvjjovrbg"
             "dtfgmhgryvvpunzrsluqzibsvyubyhqevpnfnszzriljpmoevpqacbvdcsgfzmnkh"
             "nshsvynxxncqyjxqazcttkvjnkuvykgdrquybvlpwzladpetocuphzkgfuutqcbnt"
             "twjmkkwbmbidcyauopcxmsarodcqabirbawtlgsytlflsiolxjghjmqrymadpzaet"
             "cchyvkaezeavjemubbquclhcjcmbwxphllhfnzfyewpyyiirgnohylfbtfddeohti"
             "frqiiwpdtyqjyemqjlnpcwlsylxjuxtnmcrpdznbzschmnjxnldxpkbrikpfsfwhs"
             "arrfjueubvnztlwmognapvxwelyvueheqxtncpxhzwplaxqqrbmfmmqhohucxinxi"
             "dxzhndvstideuwrisjgpwkgvsdxmlnfgqzzksflmjzckkyutrwptfvcawfbvqxlzt"
             "stpoitdepexxiqtsdtjmssqbdinalsqkjjqkgilbfxajninuclquszwbmstcdbywf"
             "hhnierqsegafyfqzvmqockcowfqwbgfxvdxbqobditvowhtdeptljetgj")
      << endl;

  return 0;
}
