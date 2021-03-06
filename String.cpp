#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "String.h"
#include<cstring>
#include<cstdlib>
using namespace std;

String::String()
{
	len = 0;
	array = NULL;
}

String::String(char* str)
{
	len = strlen(str);
	array = new char[len+1];
	strcpy(array, str);
}

String::String(const String& str)
{
	len = str.len;
	array = new char[len+1];
	strcpy(array, str.array);
}

String::~String()
{
	if (array)
		delete[] array;
	array = NULL;
}

/*char& String::at(int index)
{
	if (index < 0 || index > len) // throw exception
	{
		cout << "ERROR" << endl;
		exit(-1);//we do not want to return the next line, and at the same time not return any value so we use exit.
	}
	return array[index];
}
*/
char& String::operator[](int index) {
	if (index < 0 || index >= len) // throw exception
	{
		cout << "ERROR" << endl;
		exit(-1);
	}
	return array[index];
}

bool String::operator==(const String& str) const
{
	return (strcmp(array, str.array) == 0);
}

String String::insert(int index, const char* str)
{
	
	if (index<0 || index>len + 1)
	{
		String empty;
		cout << "ERROR" << endl;
		return empty;
	}
	if ((unsigned)index+strlen(str)>len)
	{
		char* tmp = new char[strlen(array)+strlen(str)+1];
		strncpy(tmp, array, index);
		tmp[index] = '\0';
		strncat(tmp, str,strlen(str));
		int new_index = strlen(tmp);
		for (int i = index; i < strlen(array); i++)
		{
			tmp[new_index++] = array[i];
		}
		tmp[new_index] = '\0';
		return tmp;
	}
	else
	{
		char* tmp = new char[len];
		strncat(tmp, array, index - 1);
		strcat(tmp, str);
		int len_tmp = strlen(tmp);
		if (len_tmp < len)
		{
			while (array[len_tmp] != '\0')
			{
				len_tmp++;
				tmp[len_tmp] = array[len_tmp];
			}
			tmp[len_tmp] = '\0';
		}
		return tmp;
	}
}

bool String::operator<(const String a)
{
	if (array[0] - a.array[0] == 32 || a.array[0] - array[0] == 32)
	{
		if ((a.array[0] >= 65 && a.array[0] <= 90))
		{
			bool flag;
			char* tmp = new char[a.len+1];
			strcpy(tmp, a.array);
			tmp[0] = tmp[0] + 32;
			flag = (strcmp(tmp,array));
			delete[]tmp;
			return flag;
		}
		if ((array[0] >= 65 && array[0] <= 90))
		{
			bool flag;
			char* tmp = new char[len+1];
			strcpy(tmp,array);
			tmp[0] = tmp[0] + 32;
			flag = strcmp(a.array, tmp);
			delete[]tmp;
			return flag;

		}
	}
	return strcmp(array, a.array);	
}
bool String::operator>(const String a)
{
	if (array[0] - a.array[0] == 32 || a.array[0] - array[0] == 32)
	{
		if ((a.array[0] >= 65 && a.array[0] <= 90))
		{
			bool flag;
			char* tmp = new char[a.len+1];
			strcpy(tmp, a.array);
			tmp[0] = tmp[0] + 32;
			flag = (strcmp(array,tmp));
			delete[]tmp;
			return flag;
		}
		if ((array[0] >= 65 && array[0] <= 90))
		{
			bool flag;
			char* tmp = new char[len+1];
			strcpy(tmp, array);
			tmp[0] = tmp[0] + 32;
			flag = strcmp(tmp,a.array);
			delete[]tmp;
			return flag;

		}
	}
	return strcmp(array, a.array);
}
bool String::operator>=(const String a)
{
	if (array[0] - a.array[0] == 32 || a.array[0] - array[0] == 32)
	{
		if ((a.array[0] >= 65 && a.array[0] <= 90))
		{
			bool flag;
			char* tmp = new char[a.len+1];
			strcpy(tmp, a.array);
			tmp[0] = tmp[0] + 32;
			if (strcmp(array,tmp) == 0)
			{
				return true;
			}
			flag = (strcmp(array,tmp));
			delete[]tmp;
			return flag;
		}
		if ((array[0] >= 65 && array[0] <= 90))
		{
			bool flag;
			char* tmp = new char[len+1];
			strcpy(tmp, a.array);
			tmp[0] = tmp[0] + 32;
			if (strcmp(tmp,a.array) == 0)
			{
				return true;
			}
			flag = strcmp(tmp,a.array);
			delete[]tmp;
			return flag;

		}
	}
	return strcmp(array, a.array);
}
bool String::operator<=(const String a)
{
	if (array[0] - a.array[0] == 32 || a.array[0] - array[0] == 32)
	{
		if ((a.array[0] >= 65 && a.array[0] <= 90))
		{
			bool flag;
			char* tmp = new char[a.len+1];
			strcpy(tmp, a.array);
			tmp[0] = tmp[0] + 32;
			if (strcmp(tmp, array) == 0)
			{
				return true;
			}
			flag = (strcmp(tmp, array));
			delete[]tmp;
			return flag;
		}
		if ((array[0] >= 65 && array[0] <= 90))
		{
			bool flag;
			char* tmp = new char[len+1];
			strcpy(tmp, array);
			tmp[0] = tmp[0] + 32;
			if (strcmp(a.array, tmp) == 0)
			{
				return true;
			}
			flag = strcmp(a.array, tmp);
			delete[]tmp;
			return flag;

		}
	}
	return strcmp(array, a.array);
}
bool String::operator!=(const String a)
{
	bool flag = strcmp(array, a.array);
	if (flag == 0)
		return true;
	else
		return false;
}
void String::print()
{
	if (array)
		puts(array);
}
