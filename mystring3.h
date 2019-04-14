#include <iostream>
using namespace std;
class MyString
{
	public:
		MyString();
		MyString(const char*);
		MyString(const MyString&);
		~MyString();
	public:
		MyString const operator+(const MyString&)const;
		MyString operator*(int)const;
		MyString &operator=(const MyString &mystring);
		MyString &operator=(const char *str1);
		bool operator>(const MyString&);
		bool operator<(const MyString&);
		bool operator>=(const MyString&);
		bool operator<=(const MyString&);
		bool operator==(const MyString&);
//		friend bool operator >(const MyString&,const char *str);
//		friend bool operator <(const MyString&,const char *str);
//		friend bool operator >=(const MyString&,const char *str);
//		friend bool operator <=(const MyString&,const char *str);
//		friend bool operator ==(const MyString&,const char *str);
		friend bool operator >(const char *str,const MyString&);
		friend bool operator <(const char *str,const MyString&);
		friend bool operator >=(const char *str,const MyString&);
		friend bool operator <=(const char *str,const MyString&);
		friend bool operator ==(const char *str,const MyString&);
		char &operator[](int);
		const char &operator[](int)const;
		friend ostream& operator<<(ostream&, const MyString&);
		friend MyString operator+(const MyString&, const char*);
		friend MyString operator+(const char*,const MyString&);
		friend MyString operator*(int,const MyString&);
	private:
		char *str;
};
