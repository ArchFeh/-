class ChessChecker{
	public:
	private:
		char *capros;
};

class Parser{
	public:
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
	private:
		char Q;//ферзь
		char K;//король
		char N;//конь
		char B;//слон
		char R;//ладья
};

class figure:public Figure
{
	public:
		bool move(char *fig,char *sp,char* ep);
};

