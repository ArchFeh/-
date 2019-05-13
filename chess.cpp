#include <iostream>
#include <string>
using namespace std;

class ChessChecker{
	public:
		friend ostream& operator <<(ostream& os,const ChessChecker& CC)
		{
			os<<CC.capros;
			return os;
		}
	public:
		bool capros;
};

class Parser{
	public:
		friend istream& operator>>(istream& is,Parser& p)
		{
			is>>p.figure>>p.start_pos>>p.end_pos;
			return is;
		}
	public:
		char figure;
		char start_pos[2];
		char end_pos[2];
};

class Figure{
	public:
		virtual bool move(const char &figure,const char *sp,char const *ep)=0;
	protected:
		char figures[5]={'K','Q','N','B','R'};
};

class figure:public Figure
{
	public:
		bool move(const char &figure,const char *sp,const char *ep)
		{
			if(sp[1]>='a' && sp[1]<='h'&& sp[2]>=1 && sp[2]<=8 && ep[1]>='a' && ep[1]<='h'&& ep[2]>=1&&ep[2]<=8){
			if(figure==figures[0])
			{
				if((ep[0]==sp[0]) && (ep[1]-sp[1]==1))
						return true;
				else if((ep[1]==ep[1])&& (ep[2]-sp[2]==1))
						return true;
				else return false;
			}
			else if(figure==figures[1])
			{	
				if((ep[0]==sp[0]) && (ep[1]-sp[1]!=0))
						return true;
				else if((ep[1]==sp[1])&& (ep[0]-sp[0]!=0))
						return true;
				else if((ep[0]-sp[0]!=0) &&(ep[1]-sp[1]!=0))
					return true;
				else  return false;
			}
			else if(figure==figures[2])
			{
				if((ep[0]-sp[0]==2)&&(ep[1]-sp[1]==1))
					return true;
				else if((ep[1]-ep[1]==2) && (ep[0]-sp[0]==1))
					return true;
				else return false;
			}
			else if(figure==figures[3])
			{
				if((ep[0]-sp[0])==(ep[1]-sp[1]))
					return true;
				else return false;
			}
			else if(figure==figures[4])
			{
				if((ep[0]==sp[0]) && (ep[1]-sp[1]==1))
					return true;
				else return false;
			}
			else return false;
			}
			else return false;
		}

};

int main()
{
	Parser p;
	figure fi;
	ChessChecker CC;
	string s;
	cin>>s;
	while(s!="exit")
	{
	cin>>p;
	if(fi.move(p.figure,p.start_pos,p.end_pos))
		cout<<"OK"<<endl;
	else cout<<"ERROR"<<endl;
	cin>>s;
	}
}

