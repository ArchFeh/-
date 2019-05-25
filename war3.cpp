#include <iostream>
#include <cstring>
using namespace std;
class word1:public std::exception
{
	public:
		const char*what()
		{
			return "exption:error";
		}
		}error;


class word2:public std::exception
{
	public:
		const char*what()
		{
			return"exption:wrong";
		}
		}wrong;


class mString
{
	public:
		mString();
		mString(const mString&);
		mString(const char*);
		~mString();
	public:
		mString const operator*(int n)const;
		mString& operator=(const mString& s);
		mString& operator=(const char *str);
		char &operator[](int);
		const char &operator[](int)const;
		friend ostream& operator<<(ostream& os,const mString& s);
		friend const mString operator*(int n,const mString& s);
		int delet(int,int);
		void insert(const char*,int);
	private:
		char *str;
};

	void mString::insert(const char *substr, int k)
	{   
    		int n = strlen(str);
    		int m = strlen(substr);
    		try{
				if(k>n||k<0)
					throw wrong;
			}
			catch(word2 &e)
			{
				do{
					cout<<e.what()<<endl;
					cout<<"Please input correct range"<<endl;
					cin>>k;}while(k<0 || k>n);
			}


   		 mString newStr;
    		newStr.str = new char[m + n + 1];   
    		strcpy(newStr.str, this->str);
    		for(int i = n-1;i>=k;--i)
        		*(newStr.str+i+m)= *(newStr.str +i);
    		for(int i=0;i<m;i++)
        		*(newStr.str+k+i)= *substr++;
   		 *(newStr.str+n+m+1)='\0';
    		this->str = new char[m + n + 1];
    		strcpy(this->str,newStr.str);

}

			int mString::delet(int n,int m)//指定位置删除字符串
		{
			try{
				if(n<0 || m>strlen(str)||n>m)
					throw wrong;
			}
			catch(word2 &e)
			{
				do{
				cout<<e.what()<<endl;
				cout<<"Please input correct range"<<endl;
				cin>>n>>m;}while(n<0 || m>strlen(str)|| n>m);
			}
			int len=strlen(str);
			for(int i=0;i<len;i++)
				this->str[n+i]=this->str[m+i+1];
		}

	
		mString::mString()
		{
			this->str=0;
		}
		mString::mString(const mString& c)//复制构造函数
		{
			this->str=new char[strlen(c.str)+1];
			strcpy(this->str,c.str);
		}
		mString::mString(const char* s)//将c转为c++
		{
			this->str=new char[strlen(s)+1];
			strcpy(this->str,s);
		}
		mString:: ~mString()
		{
			delete []str;
		}
	
			mString const mString::operator*(int n)const//2将字符串相乘多次
		{	
			try{
				if(n<0)	
				throw wrong;
				}
			catch(word2& a)
			{
				do{
					cout<<a.what()<<endl<<"please input number >0:";
					cin>>n;
				}while(n<0);
			}
			mString ns;
			int len=strlen(this->str);
			ns.str=new char[len+1];
			strcpy(ns.str,this->str);
			mString ns1;
			ns1.str=new char[len*n+1];
			strcpy(ns1.str,ns.str);
			for(int j=1;j<n;j++)
				for(int i=0;i<strlen(ns.str);i++)
					ns1.str[len*j+i]=ns.str[i];
			return ns1;
		}
		mString const operator*(int n,const mString& s)//前乘
		{		
			try{
				if(n<0)	
				throw wrong;
				}
			catch(word2& a)
			{
				do{
					cout<<a.what()<<endl<<"please input number >0:";
					cin>>n;
				}while(n<0);
			}

			mString ns;
			int len=strlen(s.str);
			ns.str=new char[len+1];
			strcpy(ns.str,s.str);
			mString ns1;
			ns1.str=new char[len*n+1];
			strcpy(ns1.str,ns.str);
			for(int j=1;j<n;j++)
				for(int i=0;i<strlen(ns.str);i++)
					ns1.str[len*j+i]=ns.str[i];
			return ns1;
		}

		mString& mString::operator=(const mString& s)//3将第二个字符串值赋给第一个
		{
			if(this==&s)
				return *this;
			this->str=new char[strlen(s.str)+1];
			strcpy(this->str,s.str);
			return *this;
		}

		mString& mString::operator=(const char *str)//3将第二个字符串值赋给第一个
		{
			if(this->str==str)
				return *this;
			this->str=new char[strlen(str)+1];
			strcpy(this->str,str);
			return *this;
		}

	
		char& mString::operator[](int n)//9输出指定位置字符
		{
			try
			{
				if(n<0||n>(strlen(str)))
					throw error;
			}
				catch(word1& a)
				
			{
				do{
					cout<<a.what()<<endl<<"please input true number"<<endl;
					cin>>n;
				}
				while(n<0||(n>strlen(str)));
			}

			return this->str[n-1];
		}
		
		const char &mString::operator[](int n)const
		{
			try
			{
				if(n<0||n>(strlen(str)))
					throw error;
			}
				catch(word1& a)
				
			{
				do{
					cout<<a.what()<<endl<<"please input true number"<<endl;
					cin>>n;
				}
				while(n<0||(n>strlen(str)));
			}	
			return this->str[n-1];
		}

		ostream& operator<<(ostream& os,const mString& s)//10输出
		{
			os<<s.str;
			return os;
		}


int main()
{
	mString str("whats");
	mString s("up");
	mString s1;

	cout<<(str=(-2)*s)<<endl;
	cout<<str[-1]<<endl;
	//cout<<str<<endl;	
	int m,n;
	cin>>n>>m;
	str.delet(n,m);
	cout<<str<<endl;
	int i;
	cin>>i;
	s.insert("Lets",i);
	cout<<s<<endl;
}



