#include <iostream>
using namespace std;

int main()
{
	char figures[]={'K','Q','N','B','R'};
	char figure;
	char sp[2];
	char ep[2];
	bool i;
	cin>>figure>>sp>>ep;	
			if(figure==figures[0])
			{
				if((ep[1]==sp[1]) && (ep[2]-sp[2]==1))
						i=true;
				else if((ep[2]==ep[2])&& (ep[1]-sp[1]==1))
						i=true;
				else i=false;
			}
			else if(figure==figures[1])
			{	
				if((ep[1]==sp[1]) && (ep[2]-sp[2]!=0))
						i=true;
				else if((ep[2]==sp[2])&& (ep[1]-sp[1]!=0))
						i=true;
				else if((ep[1]-sp[1]!=0) &&(ep[2]-sp[2]!=0))
					i=true;
				else  i=false;
			}
			else if(figure==figures[2])
			{
				if((ep[1]-sp[1]==2)&&(ep[2]-sp[2]==1))
					i=true;
				else if((ep[2]-ep[2]==2) && (ep[1]-sp[1]==1))
					i=true;
				else i=false;
			}
			else if(figure==figures[3])
			{
				if((ep[1]-sp[1])==(ep[2]-sp[2]))
					i=true;
				else i=false;
			}
			else if(figure==figures[4])
			{
				if((ep[1]==sp[1]) && (ep[2]-sp[2]==1))
					i=true;
				else i=false;
			}
	if(i==true)
		cout<<"ok"<<endl;
	else cout<<"no"<<endl;

}

