#include <iostream>
#include <cstdio>
using namespace std;

class MyString
{
private:
	char* buffer;
	int size;

	int size_(char* s)
	{
		int i = 0;
		while (s[i] != '\0')
		{
			i++;
		};
		return i;
	};

	void cmp(char* s)
	{
		buffer = new char[size + 1];
		for (int i = 0; i < size; i++)
			buffer[i] = s[i];
		buffer[size] = 0;
	}

public:
	int strlen_()
	{
		return size;
	};

	void print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << buffer[i];
		}
		cout << endl;
	}

	void strcpy_(MyString &s)
	{
		int k = s.size;
		size = k;
		delete buffer;
		cmp(s.buffer);
	};

	void strcat_(MyString &s)
	{
		int x;
		x = size + s.size;
		char* buf;
		buf = new char[x+1];
		for (int i = 0; i < size; i++)
			buf[i] = buffer[i];
		for (int i = size; i < x; i++)
			buf[i] = s.buffer[i - size];
		buf[x] = 0;
		size = x;

		delete buffer;
		cmp(buf);
		delete buf;
	};

	// return 1; строки совпадают
	// return 0; строки различаются
	int strcmp_(MyString& s)
	{
		if (size != s.size) return 0;
		bool flag = true;
		for (int i = 0; i < size; i++)
		{
			if (buffer[i] != s.buffer[i]) flag = false;
		}
		if (flag == true) return 1;
		else
		{
			return 0;
		}
	}

	MyString operator= (MyString &s)
	{
		size = s.size;
		strcpy_(s);
		return MyString(buffer);
	}
	
	MyString operator+= (MyString& s)
	{
		strcat_(s);
		return MyString(buffer);
	}

	MyString(char* s)
	{
		
		size = size_(s);
		cmp(s);
		
	};

	~MyString()
	{
		delete buffer;
	}
};

int main()
{
	char str[256];
	gets_s(str);
	MyString s(str);

	gets_s(str);
	MyString s1(str);

	cout << endl;

	//s.print();
	//s.strcpy_(s1);
	//s.strcat_(s1);
	
	s = s1;	
	s += s1;
	s.print();
	int x = s.strcmp_(s1);
	
	cout << x;
}