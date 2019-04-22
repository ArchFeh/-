#include <cstring>
#include <cctype>
#include <mystring3.h>
#include <exception>
#include <stdexcept>
#include <new>

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
    cout<<str2*-1<<endl;
    cout<<str2[-3]<<endl;
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
