#include <cstring>
#include <cctype>
#include <mystring3.h>
#include <exception>
#include <stdexcept>
#include <new>

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
                throw "Not nonnegative number.";
        }
    catch(const char* e)
    {
        cout<<e<<endl<<"Please input number >0:";
        cin>>raz;
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
           if(position<0 || position > strlen(str))
            throw "out of range.";
         }
             catch(const char* e)
    {
        cout<<e<<endl<<"Please input number in range:";
        cin>>position;
    }
    return str[position];
}

const char &MyString::operator[](int position)const 
{   
    try{
           if(position<0 || position > strlen(str))
            throw "out of range.";
         }
             catch(const char* e)
    {
        cout<<e<<endl<<"Please input number in range:";
        cin>>position;
        
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
                throw "Not nonnegative number.";
        }
    catch(const char* e)
    {
        cout<<e<<endl<<"Please input number >0:";
        cin>>raz;
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

int main()
{
    MyString str1;
    str1="THis is a mad";
    cout << str1 <<endl;
    
    MyString str2("Hello");
        str2[1]='s';
    cout << str2 << endl;

    MyString str3=str1;
    str3=str3;
    //cout<<str2*-1<<endl;
    cout<<str2[3]<<endl;
    cout<<str3<<endl;
/*  cout << str3 <<endl;
    if(str3 == str2)
        cout << " str3 = etr2"<<endl;
    if(str2 > str1)
        cout<< "str2 >str1" << endl;
    if(str2 < "He" )
        cout<<"str2 > 'He'"<<endl;
    if("Ze" > str2)
        cout<<"'Ze' > str2"<<endl;*/



   
    MyString str4("World"); 
    cout<<(str3=-1*str2*3)<<endl;
/*  cout<<(str1="ldowahdo"+str4)<<endl;
    cout<<(str4+"lala")<<endl;
    cout<<(str3+str4)*4<<endl;
    cout<<(4*(str1+str3))<<endl;*/
    return 0;
}
