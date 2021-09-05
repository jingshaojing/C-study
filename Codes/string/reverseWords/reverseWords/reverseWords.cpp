// ��ת�ַ����еĵ���
// ��ֻ�ǵ�����ת������Ҫȥ����β����Ŀո�
// ˼·�ȷ�ת�����ַ�����Ȼ��ȥ����β�Ŀո�֮ǰ���������ո�ͷ�ת�����ڣ��͵õ�����
#include <iostream>
#include <string>
using namespace std;
class solution
{
public:
    // ʵ��һ����ת����ұյ�reverse
    void reverse(string& s, int start, int end)
    {
        for ( int i = start, j =end; i < j; i++, j--)
        {
            swap(s[i], s[j]);
        }
    }
    void removeExtraSpace(string& s)
    {
        int slow = 0, fast = 0;
        // �Ƴ���ͷ��
        while (s.size() > 0 && fast < s.size() && s[fast] == ' ')
        {
            fast++;
        }
        // �Ƴ��м�ģ��൱�ڰ����еĶ����е�s[slow],�����м����ո񣬵�Ȼ�м��һ���ո�Ҳ�����Ƶ�s[slow]
        for (; fast < s.size(); fast++)
        {
            if (fast - 1 > 0 && s[fast - 1] == s[fast] && s[fast] == ' ')
            {
                continue;
            }
            else
            {
                s[slow++] = s[fast];
            }
        }
        // �Ƴ�ĩβ��
        if (slow - 1 > 0 && s[slow - 1] == ' ')
        {
            s.resize(slow - 1);
        }
        else
        {
            s.resize(slow);
        }
    }
    string reverseWords(string& s)
    {
        removeExtraSpace(s);
        reverse(s, 0, s.size() - 1);
        for (int i = 0; i < s.size(); i++)
        {
            int j = i;
            while (j < s.size() && s[j] != ' ')
            {
                j++;
            }
            reverse(s, i, j - 1);
            i = j;
        }
        return s;

    }
};
int main()
{
    string s;
    getline(cin, s);
    string result;
    result = solution().reverseWords(s);
    cout << result << endl;
}