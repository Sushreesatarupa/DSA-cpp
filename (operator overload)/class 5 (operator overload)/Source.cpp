#include <iostream>
#include<cstring>
using namespace std;


class myString
{
private:
	char* str;

public:
	myString()
	{
		str = NULL;
	}

	myString(const char * input)
	{
		int len = strlen(input);
		str = new char[len + 1];
		strcpy(str, input);
	}

	myString(const myString & obj)
	{
		str = new char[strlen(obj.str) + 1];
		strcpy(str, obj.str);
	}

	int getlength() const
	{
		return strlen(str);
	}

	const myString & operator = (const myString & obj)
	{
		if (str != NULL)
			delete[] str;
		str = new char[strlen(obj.str) + 1];
		strcpy(str, obj.str);
		return *this;
	}

	myString operator + (const myString & obj)
	{
		myString ans;
		ans.str = new char[getlength() + obj.getlength() + 1];
		strcpy(ans.str, str);
		strcpy(ans.str + getlength(), obj.str);
		return ans;
	}
	bool operator == (const myString & obj)
	{
		if (strcmp(str, obj.str) == 0)
			return true;
		return false;
	}

	const myString & operator += (const myString & obj)
	{
		return *this = *this + obj;
	}

	char& operator [](int index)
	{
		return this->str[index];
	}

	void operator << (ostream & out)
	{
		out << str;
	}
};



int main()
{
	myString s("hello");
	s[0] = 'H';
	s << cout;
	system("pause");
}