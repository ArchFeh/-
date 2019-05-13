#include <stdio>
#include <cstring>
using namespace std;

class ChessChecker{
	public:
		friend ostream& operator <<(ostream&,const ChessChecker&);
	private:
		bool capros;
};

class Parser{
	public:
		friend istream& operator>>(istream&,Parser&);
	private:
		char *figure;
		char *start_pos;
		char *end_pos;
};

class Figure{
	public:
		char hod[8][8];
		int i=0;int j=0;
		for(i=0;i<8;i++)
			for(j=0;j<8;j++)
			{
				hod[i]='a'+i;
				hod[i][j]=j+1;
			}
		virtual bool move()=0;
	protected:
		char figures[5]={"K","Q","N","B","R"};
};

class figure:public Figure
{
	public:
		bool move(char figures,char *sp,char* ep)
		{
			if(figures==figures[0])
			{
				if(ep[1]==sp[1] && ep[2]-sp[2]==1)
						return true;
				else if(ep[2]==ep[2]&& ep[1]-sp[1]==1))
						return true;
				else return false;
			}
			if(figures==figures[1])
			
				if(ep[1]==sp[1] && ep[2]-sp[2]!=0)
						return true;
				else if(ep[2]==sp[2]&& ep[1]-sp[1]!=0)
						return true;
				else if(ep[1]-sp[1]!=0 &&ep[2]-sp[2]!=0)
					return true;
				else return false;
			}
			if(figures==figures[2])
			{
				if(ep[1]-sp[1]==2&&ep[2]-sp[2]==1)
					return true;
				else if(ep[2]-ep[2]==2 && ep[1]-sp[1]==1)
					return true;
				else return false;
			}
			if(figures==figures[3])
			{
				if(ep[1]-sp[1]==ep[2]-sp[2])
					return true;
				else return false;
			}
			if(figures==figures[4])
			{
				if(ep[1]==sp[1] && ep[2]-sp[2]==1)
					return true;
				else return false;
			}
		}


};

