#include <iostream>
#include <cstring>

using namespace std;

class Parser{
    public:
	Parser()
	{
		figure=new char[5];
		start_pos=new char[3];
		end_pos=new char[3];
	}
	Parser(Parser &P)
	{
		start_pos=new char[5];
		end_pos=new char[3];
		figure=P.figure;
		start_pos=P.start_pos;
		end_pos=P.end_pos;
	}
	char *Get_Fi(void)
	{
		return figure;
	}
	char *Get_sp(void)
	{
		return start_pos;
	}
	char *Get_ep(void)
	{
		return end_pos;
	} 
 	friend istream& operator>>(istream& is,Parser& p)
        {
            is>>p.figure>>p.start_pos>>p.end_pos;
            return is;
        }
    private:
        char *figure;
        char *start_pos;
        char *end_pos;
};

class Figure{
    public:
        virtual bool move(const char *figure,const char *sp,char const *ep)=0;
    protected:
        char figures[5]={'K','Q','N','B','R'};
};

class figure:public Figure
{
    public:
        bool move(const char *figure,const char *sp,const char *ep)
        {
            if(sp[0]>='a' && sp[0]<='h' && sp[1]>='1' && sp[1]<='8' && ep[0]>='a' && ep[0]<='h'&& ep[1]>='1' && ep[1]<='8')
            {
            if(*figure==figures[0])
            {
                if(((ep[0]-sp[0]<=1)&&(ep[0]-sp[0]>=-1)) && ((ep[1]-sp[1]<=1)&&(ep[1]-sp[1]>=-1)))
                        return true;
                else  return false;
            }
            else if(*figure==figures[1])
            {   
                if((ep[0]==sp[0]) && (ep[1]-sp[1]!=0))
                        return true;
                else if((ep[1]==sp[1])&& (ep[0]-sp[0]!=0))
                        return true;
                else if((ep[0]-sp[0]!=0) &&(ep[1]-sp[1]!=0)&&(abs(ep[0]-sp[0])==abs(ep[1]-sp[1])))
                    return true;
                else  return false;
            }
            else if(*figure==figures[2])
            {
                if(((ep[0]-sp[0]==2)||(ep[0]-sp[0]==-2))&&((ep[1]-sp[1]==1)||(ep[1]-sp[1]==-1)))
                    return true;
                else if(((ep[1]-sp[1]==2)||(ep[1]-sp[1]==-2)) && ((ep[0]-sp[0]==1)||(ep[0]-sp[0]==-1)))
                    return true;
                else return false;
            }
            else if(*figure==figures[3])
            {
                if(abs(ep[0]-sp[0])==abs(ep[1]-sp[1]))
                    return true;
                else return false;
            }
            else if(*figure==figures[4])
            {
                if((ep[0]==sp[0]) && (ep[1]-sp[1]!=0))
                    return true;
                else if((ep[1]==sp[1]) &&(ep[0]-sp[0]!=0))
                    return true;
                else return false;
            }
            else return false;
            }
            else return false;
        }
        

};

class ChessChecker{
    public:
        ChessChecker(Parser p,figure fi):par(p)
	{
		capros=fi.move(par.Get_Fi(),par.Get_sp(),par.Get_ep());
	}
	friend ostream& operator <<(ostream& os,const ChessChecker& CC)
        {
            if(CC.capros)
            os<<"OK";
            else os<<"ERROR";
            return os;
        }
    private:
        bool capros;
	Parser par;
	figure fi;
};



int main()
{
    Parser P;
    figure fi;
    string s;
    do{
	cin>>P;
	ChessChecker CC(P,fi);
        cout<<CC<<endl;
	cin>>s;
       }while(s!="exit");
}

