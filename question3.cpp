/* name: ron shaull 203385125
* course: c++
* task 3 question 3
* discription: program gets 2 strings from user and manipulates them in severeal ways.
*/
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
	else if (!(a == b))
		cout << "a=b" << endl;
	else if (a > b)
		cout << "a>b" << endl;
	String c=b.insert(index,a.array);
	c.print();	
	cin >> tav;
	cin >> index;
	c[index] = tav;
	c.print();
}
/*World
Hello
5
a<b
HelloWorld
!
5
Hello!orld

C:\Users\user\Desktop\לימודים\c++סדנא ב\תרגילים להגשה\תרגיל 3\task3\Debug\question 3.exe (process 15136) exited with code 0.
Press any key to close this window . . .

hello
world
2
a<b
wohellorld
?
10
ERROR

C:\Users\user\Desktop\לימודים\c++סדנא ב\תרגילים להגשה\תרגיל 3\task3\Debug\question 3.exe (process 15356) exited with code -1.
Press any key to close this window . . .

hello
hello
2
hehellollo
H
2
heHellollo

C:\Users\user\Desktop\לימודים\c++סדנא ב\תרגילים להגשה\תרגיל 3\task3\Debug\question 3.exe (process 17144) exited with code 0.
Press any key to close this window . . .











*/