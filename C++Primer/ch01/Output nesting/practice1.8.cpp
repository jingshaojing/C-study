#include <iostream>
#include <string>
using std::cout;
using std::endl;
int main()
{
	//cout << "bagn" << endl;
	cout << "/*" << endl;
	cout << "*/" << endl;
	cout << /*"*/"*/" << endl;
	cout <</* "*/" /* "/*" */ << endl;
	return 0;
}
