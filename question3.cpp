#include <iostream>
#include "String.h"
#include<cstring>
using namespace std;
int main()
{
	int index;
	char tav;
	char* tmp = new char[80];
	cin >> tmp;
	String a(tmp);
	cin >> tmp;
	String b(tmp);
	cin >> index;
	if (a < b)
		cout << "a<b"<<endl;
	else if (a == b)
		cout << "a=b" << endl;
	else if (a > b)
		cout << "a>b" << endl;
	String c=b.insert(index,a.array);
	c.print();	
	cin >> tav;
	cin >> index;
	c.array[index] = tav;
	c.print();
}
