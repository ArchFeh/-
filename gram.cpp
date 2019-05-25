#include <iostream>
#include <exception>

using namespace std;

class error: public std::exception
{
	public:
		const char* what()
		{
			return "Error";
		}
}a;

class Parser
{
	private:
   		 char c;
	public:
    		Parser(){}
    		void gc()
    		{
        		c = getchar();
    		}
    		bool analyze()
    		{
        		cout << "Please input the phrase:";
        		gc();
        		try{
            			S();       			
        		   }
			catch(error& e)
			{
            			cout << e.what()<<endl;
            			return false;
        		}
        		cout << endl;
        		return true;
    		}
    		void S()
		{
        		cout << "S->";
        		if (c == 'a')
			{
            			cout << "aAB "<<endl;
            			gc();
            			A();
            			B();
        		}
			else if (c == 'b')
			{
            			cout << "bB "<<endl;
            			gc();
            			B();
        		}
			else throw a;
    		}
    		void A()
		{
        		cout << "A->";
        		if (c == 'a')
			{
            			cout << "aA"<<endl;
            			gc();
            			A();
        		}
			else if (c == 'b')
			{	
        		    cout << "b"<<endl;
           		    gc();
            		 }
        		else throw a;
    		}
    		void B()
		{
        		cout << "B->";
        		if (c == 'b')
			{
            			cout << "bB"<<endl;
            			gc();
            			B();
        		}
			else if(c == '\n')
			{
            			cout << "ε";
        		}else 
				throw a;
    		}
};


int main()
{
    Parser p;
    p.analyze();
}
