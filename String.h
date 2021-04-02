#pragma once
class String
{
	int len;
	char* array;
public:
	
	//int len; // cache length
	//char* array;
	String();
	String(char*);
	String(const String&);
	~String();
	// subscript operator
	char& at(int index);
	char& operator[](int index);

	// relational operators
	bool operator==(const String&) const;

	//insertion method.
	String insert(int index, const char* str);

	//boolian operators
	bool operator <(const String a);
	bool operator >(const String a);
	bool operator >=(const String a);
	bool operator <=(const String a);
	bool operator !=(const String a);
	int length() { return len; }
	bool empty() { return length() == 0; }
	void print();
};



