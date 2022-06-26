#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;
int main(void)
{
    string s("III");
    const pair<int, string> valueSymbols[] = {
           {1000, "M"},
           {900, "CM"},
           {500,  "D"},
           {400, "CD"},
           {100,  "C"},
           {90,  "XC"},
           {50,   "L"},
           {40,  "XL"},
           {10,   "X"},
           {9,   "IX"},
           {5,    "V"},
           {4,   "IV"},
           {1,    "I"}
    };
    int n = s.length();
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        cout << valueSymbols->first<< endl;
    }
    return 0;
}