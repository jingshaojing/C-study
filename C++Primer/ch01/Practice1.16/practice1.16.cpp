#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	int val = 0;
	int sum = 0;
	while(cin >> val)
		sum += val;
	cout << "sum = " << sum << endl;
}