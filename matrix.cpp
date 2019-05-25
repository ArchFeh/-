#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class T_Type>
class Matrix
{
    public:
        Matrix(unsigned row,unsigned col);//умолчание
        Matrix(const Matrix&);//копирование
        template<class T>
        Matrix(const T);//преобразование
        Matrix(const char*);//файл
        Matrix transpose();
        Matrix& operator=(const Matrix<T_Type>&);
        Matrix& operator+(const Matrix<T_Type>&);
        Matrix& operator-(const Matrix<T_Type>&);
        Matrix& operator*(int);
        Matrix operator*(const Matrix<T_Type>&);
        int getFileRows(const char*);
        int getFileColumns(const char*);
        void print()const;
    private:
        unsigned rows;
        unsigned cols;
        vector<vector<T_Type> > m_matrix;
};

template <class T_Type>
void Matrix<T_Type>::print()const
{
    int count=0;
    cout<<"Matrix: "<<endl;
    for(unsigned i=0;i<rows;i++)
        for(unsigned j=0;j<cols;j++)
        {
            cout<<"["<<m_matrix[i][j] <<"]";
            count++;
            if(count==cols)
            {
                cout<<endl;
                count=0;
            }
        }
    cout<<endl;
}

template <class T_Type>
Matrix<T_Type>::Matrix(unsigned row,unsigned col)
{
    rows=row;
    cols=col;
    m_matrix.resize(rows);
    for(unsigned i=0;i<m_matrix.size();i++)
        m_matrix[i].resize(cols,1);

}

template <class T_Type>
Matrix<T_Type>::Matrix(const Matrix<T_Type>&mat2)
{
    rows=mat2.rows;
    cols=mat2.cols;
    m_matrix.resize(rows);
    for(unsigned i=0;i<m_matrix.size();i++)
        m_matrix[i].resize(cols);
    m_matrix=mat2.m_matrix;
}

template <class T_Type>
template <typename T>
Matrix<T_Type>::Matrix(const T num)
{
    rows=1;
    cols=1; 
    m_matrix.resize(rows);
    for(unsigned i=0;i<m_matrix.size();i++)
        m_matrix[i].resize(cols);

}

template<class T_Type>
Matrix<T_Type>::Matrix(const char* filename)
{
    ifstream fileStream;
    fileStream.open(filename,ios::in);
    rows=getFileRows(filename);
    cols=getFileColumns(filename);
    m_matrix.resize(rows);
    for(unsigned i=0;i<m_matrix.size();i++)
        m_matrix[i].resize(cols);
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            fileStream>>m_matrix[i][j];
        
    fileStream.close();
}

template<class T_Type>
Matrix<T_Type> Matrix<T_Type>::transpose()
{
    Matrix<T_Type> newm(this->rows,this->cols);
}


template<class T_Type>
int Matrix<T_Type>::getFileRows(const char* filename)
{
    ifstream fileStream;
    string tmp;
    int count=0;
    fileStream.open(filename,ios::in);
    if(fileStream.fail())
        return 0;
    else
    {
    while(getline(fileStream,tmp,'\n'))
    {
        if(tmp.size()>0)
            count++;
    }
    fileStream.close();
    return count;
    }
};

template<class T_Type>
int Matrix<T_Type>::getFileColumns(const char* filename)
{
    ifstream fileStream;
    fileStream.open(filename,ios::in);
    double tmp=0;
    int count=0;
    char c;
    c=fileStream.peek();
    while(('\n'!=c)&&(!fileStream.eof()))
    {
        fileStream>>tmp;
        ++count;
        c=fileStream.peek();
    }
    fileStream.close();
    return count;
}
template<class T_Type>
Matrix<T_Type>& Matrix<T_Type>::operator=(const Matrix<T_Type>&m)
{
    if((this->rows==m.rows)&&(this->cols==m.cols))
        m_matrix=m.m_matrix;
    else cout<<"Cant equal"<<endl;
}

template<class T_Type>
Matrix<T_Type>& Matrix<T_Type>::operator+(const Matrix<T_Type>&m)
{
        if((this->rows==m.rows)&&(this->cols==m.cols))
            for(int i=0;i<rows;i++)
                for(int j=0;j<cols;j++)
                    m_matrix[i][j]+=m.m_matrix[i][j];
        else 
            cout<<"Cant +"<<endl;
}

template<class T_Type>
Matrix<T_Type>& Matrix<T_Type>::operator-(const Matrix<T_Type>&m)
{
    if((this->rows==m.rows)&&(this->cols==m.cols))
            for(int i=0;i<rows;i++)
                for(int j=0;j<cols;j++)
                    m_matrix[i][j]-=m.m_matrix[i][j];
        else 
            cout<<"Cant -"<<endl;
}

template<class T_Type>
Matrix<T_Type>& Matrix<T_Type>::operator*(int n)
{
    for(int i=0;i<rows;i++)
                for(int j=0;j<cols;j++)
                    m_matrix[i][j]*=n;;
}

template<class T_Type>
Matrix<T_Type> Matrix<T_Type>::operator*(const Matrix<T_Type>&m)
{
    if(this->cols==m.rows)
        {
            Matrix<T_Type> newm(this->rows,m.cols);
            for(int i=0;i<this->rows;i++)
                for(int j=0;j<m.cols;j++)
                    newm_matrix[i][j]-=m.m_matrix[i][j];
            
            
        
}

int main()
{
    Matrix <double>a(3,3);
    a.print();
    Matrix <double>b(a);
    b.print();
    Matrix<int>c(1);
    c.print();
    Matrix<double>d("mat");
    d.print();   
    Matrix<double>e(3,3);
    a=d;
    a.print();
    a+d;
    a.print();
    a-e;
    a.print();
    a*3;
    a.print();
}

