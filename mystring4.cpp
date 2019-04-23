#include <cstring>
#include <cctype>
#include <mystring3.h>
#include <exception>
#include <stdexcept>
#include <new>

class my_logic_error:public std::exception
{
    public:
        const char* what(){
            return "Exception: Not nonnegative number.";
        }
}ml;

class my_out_of_range:public std::exception
{
    public:
        const char* what()
        {
            return "Exception: out of range.";
        }
}mo;


MyString::MyString()
{
    this->str = new char[1];
}

MyString::MyString(const char *str)
{
    this->str=new char[strlen(str)+1];
    strcpy(this->str,str);
}

MyString::MyString(const MyString &mystring)
{
    this->str = new char[strlen(str)+1];
    strcpy(this->str,mystring.str);
}

MyString::~MyString()
{
    delete []str;
}

MyString &MyString::operator=(const MyString &mstring)
{
    if(this == &mstring)
        return *this;
    delete[] str;
    str = new char[strlen(mstring.str)+1];
    strcpy(str,mstring.str);
    return *this;
}


MyString &MyString::operator=(const char *str1)
{
    if(strlen(str)>=strlen(str1))
        strcpy(str,str1);
    else
    {
        delete[]str;
        str=new char[strlen(str)+1];
        strcpy(str,str1);
    }
    return *this;
}
MyString const MyString::operator+(const MyString &mstring)const
{
    MyString newStr;
    if(!mstring.str)
        newStr = *this;
    else if(!str)
        newStr = mstring;
    else
    {
        newStr.str = new char[strlen(str)+strlen(mstring.str)+1];
        strcpy(newStr.str,str);
        strcat(newStr.str,mstring.str);
    }
    return newStr;
}

MyString MyString::operator*(int raz)const
{
    try{
            if(raz<0)
                throw ml;
        }
    catch(my_logic_error &e)
    {
        do {
           cout<<e.what()<<endl<<"Please input number >0:";
           cin>>raz;
        } while (raz < 0);
    }
    MyString newStr;
    newStr.str = new char[strlen(str)*raz+1];
    for(int i=0;i<raz;i++)
        strcat(newStr.str,str);
    return newStr;
}


bool MyString::operator>(const MyString &mstring)
{
    if(strcmp(this->str,mstring.str)>0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator>(const char *str,const MyString &mstring)
{
    if(strcmp(str,mstring.str)>0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool MyString::operator<(const MyString &mstring)
{
    if(strcmp(this->str,mstring.str)<0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator<(const char *str,const MyString &mstring)
{
    if(strcmp(str,mstring.str)<0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool MyString::operator>=(const MyString &mstring)
{
    if(strcmp(this->str,mstring.str)>=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool operator>=(const char *str, const MyString &mstring)
{
    if(strcmp(str,mstring.str)>=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool MyString::operator<=(const MyString &mstring)
{
    if(strcmp(this->str,mstring.str)<=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator<=(const char *str,const MyString &mstring)
{
    if(strcmp(str,mstring.str)<=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool MyString::operator==(const MyString &mstring)
{
    if(strcmp(this->str,mstring.str)==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator==(const char *str,const MyString &mstring)
{
    if(strcmp(str,mstring.str)==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


char &MyString::operator[](int position)
{
    try{
           if(position<0 || position > (strlen(str)-1))
            throw mo;
         }
             catch(my_out_of_range& e)
    {
        do {
           cout<<e.what()<<endl<<"Please input number in range:(0-"<<strlen(str)-1<<")"<<endl;
           cin>>position;
        } while (position < 0 || (position >strlen(str)-1));
    }
    return str[position];
}

const char &MyString::operator[](int position)const 
{   
    try{
           if(position<0 || position > (strlen(str)-1))
            throw mo;
         }
             catch(my_out_of_range& e)
    {
         do {
           cout<<e.what()<<endl<<"Please input number in range:(0-"<<strlen(str)-1<<")"<<endl;
           cin>>position;
        } while (position < 0 || position >(strlen(str)-1));
    }
    return str[position];
}

MyString operator+(const MyString &mstring,const char *str)
{
    MyString newStr;
    newStr.str = new char[strlen(mstring.str)+strlen(str)+1];
    strcpy(newStr.str,mstring.str);
    strcat(newStr.str,str);
    return newStr;
}

MyString operator+(const char *str,const MyString &mstring)
{
    MyString newStr;
    newStr.str = new char[strlen(mstring.str)+strlen(str)+1];
    strcpy(newStr.str,mstring.str);
    strcat(newStr.str,str);
    return newStr;
}

MyString operator*(int raz,const MyString &mstring)
{
    try{
            if(raz<0)
                throw ml;
        }
    catch(my_logic_error& e)
    {
         do {
           cout<<e.what()<<endl<<"Please input number >0:";
           cin>>raz;
        } while (raz < 0);
    }
    MyString newStr;
    newStr.str = new char[strlen(mstring.str)*raz+1];
    for(int i=0;i<raz;i++)
        strcat(newStr.str,mstring.str);
    return newStr;
}


ostream& operator<<(ostream &os,const MyString &mstring)
{
    os << mstring.str;
    return os;
}


