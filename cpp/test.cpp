#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;
const char*  CodeAuthor = "Honduras Iron Egg";
const int       N = 30;
const double EPS = 1e-6;

class Array2 {
// 在此处补充你的代码
    int col;
    int row;
    int *p=NULL;
    public:
    Array2():col(0),row(0){p=NULL;}//默认构造
    Array2(int i,int j):col(i),row(j){p=new int[i*j];}//带参数构造
    Array2 & operator=(int n){
        *p=n;
        return *this;
    }
    Array2 & operator=(const Array2 &a){
        if(this==&a){
            return *this;
        }
        if(!a.p){
            p=NULL;
            col=row=0;
            return *this;
        }
        delete[] p;
        p=new int[a.col*a.row];
        row=a.row;
        col=a.col;
        memcpy(p,a.p,sizeof(int)*row*col);
        return *this;
    }
    int* operator [](int i){return p+i*row;}//指向a数组第i行首地址
    int & operator()(int i,int j){return p[i*row+j];}
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;
    b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}