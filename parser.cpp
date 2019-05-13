#include<iostream>

using namespace std;

class Parser{
	static list<char> gram;
	static char c;
	static void gc() {cin>>c;}
	struct S{
		S(){
			if(c=='a')
			{
				gc();
				A();
				B();
			}
			
			   if(c=='b')
			{
				gc();
				B();
		
			}
			else throw c;
		};
		~S(){}

	struct A{
		A()
		{
			if(c=='a')
			{
				gc();
				A();
			}
			if(c=='b')
			gc();
			throw c;
		}
	}
		~A(){}

	struct B{
		B()
		{
			if(c=='b')
			{
				gc();
				B();}
		}
	        }
	        ~B(){}

public: void analyze()
	{
		try
		{
			gc();
			S();
			if(c!='#') throw c;
			list<char>::iterator p;
			for(p = gram.begin(); p!= gram.end(); p++)
				cout<<*p;
			cout<<endl;
		}
		catch(char c)
		{
			cout<<"error"<<endl;
		}
	}
	}
