#include <iostream>
#include <iomanip>
using namespace std;
#define maxn 50


int n;
double a [maxn];
double b [maxn];
double c [maxn];
double f [maxn];
double m [5][5]={0};

double Beta [maxn];
double y [maxn];
double x [maxn];

/* 读取矩阵 */
void read() {
  cout << "Please input the scale of matrix n:";
  cin >> n;
  cout << "|--------------------\n";
  cout << "|Please input the [a] diagonal:" << endl;

  for (int i = 2; i <= n; i++) {
    cin >> a [i];
	m[i-1][i-2]=a[i];
  }

  cout << "|--------------------\n";
  cout << "|Please input the [b] diagonal:" << endl;
  for (int i = 1; i <= n; i++) {
    cin >> b [i];
	m[i-1][i-1]=b[i];
  }

  cout << "|--------------------\n";
  cout << "|Please input the [c] diagonal:" << endl;
  for (int i = 1; i <= n - 1; i++) {
    cin >> c [i];
	m[i-1][i]=c[i];
  }

  cout << "|--------------------\n";
  cout << "|Please input the [f]:" << endl;
  for (int i = 1; i <= n; i++) {
    cin >> f [i];
  }
}

/* 显示结果 */
void print() {
  cout << "|--------------------\n";
  for(int i=0;i<n;i++)
	  for(int j=0;j<n;j++)
	  {
		  cout<<setw(5)<<m[i][j];
		  if((j+1)%5==0)
			  cout<<endl;
	  }
	  
  cout << "|-------------------" << endl;
  for (int i = 1; i <= n; i++) {
    cout << "x [" << i << "] =" << x [i] << endl;
  }
}

void Chasing() {
  Beta [1] = c [1] /b [1];
  for (int i = 2; i <= n - 1; i++) {
    Beta [i] = c [i] / (b [i] - a [i] * Beta [i - 1]);
  }

  y [1] = f [1] /b [1];
  for (int i = 2; i <= n; i++) {
    y [i] = (f [i] - a [i] * y [i - 1]) / (b [i] - a [i] * Beta [i - 1]);
  }

  x [n] = y [n];
  for (int i = n - 1; i >= 1; i--) {
    x [i] = y [i] - Beta [i] * x [i + 1];
  }

  print ();
}

int main() {
  read ();
  Chasing ();
  return 0;
}