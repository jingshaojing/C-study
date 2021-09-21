#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
class solution
{
public:
    string valide_ipaddress(string s)
    {
        if (isIpv4(s)) return "IPV4";
        else if (isIpv6(s)) return "IPV6";
        return "Neither";
    }
    bool isIpv4(string s)
    {
        vector<string> ip;
        split(s, ip, '.');
        if (ip.size()  != 4) return false;
        for (string s : ip)
        {
            if (s.size() == 0 || (s.size() > 1 && s[0] == '0') || s.size() > 3) return false;
            for (auto c : s)
            {
                if (!isdigit(c)) return false;
                // 把字符串转换成十进制
                int digit = stoi(s);
                if (digit < 0 || digit > 255) return false;

            }
        }
        return true;
    }
    bool isIpv6(string s)
    {
        vector<string> ip;
        split(s, ip, ':');
        if (ip.size() != 8) return false;
        for (auto s : ip)
        {
            if (s.size() == 0 || s.size() > 4) return false;
            for (char c : s)
            {
                if (c < '0' || c > '9' && c < 'A' || c > 'Z' && c < 'a' || c > 'z') return false;
            }
        }
        return true;
    }
    // 要实现的split的作用 通过指定分隔符对字符串进行分割

    void split(string s, vector<string>& ip, char c)
    {
        // 共有istringstream,ostringstream,stringstream三种,后者包括输入输出操作
        stringstream ss(s);
        string temp;
        // getline中ss是输入流，temp是输入的变量的名字，c表示遇到字符就停止，默认是回车
        while (getline(ss,temp,c))
        {
            ip.push_back(temp);
        }
        if (s.size() > 0 && s.back() == c) ip.push_back({ temp });
        return;
    }
};
int main()
{
    string s;
    cin >> s;
    string result = solution().valide_ipaddress(s);
    cout << result << endl;
    return 0;
}