#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;
const char*  CodeAuthor = "Honduras Iron Egg";
const int       N = 30;
const double EPS = 1e-6;
class MyInt
{
	int nVal;
	public:
	MyInt( int n) { nVal = n ;}
// 在此处补充你的代码
    friend MyInt& Inc(MyInt& n) {
        n.nVal++;
        return *this;
    }
    friend ostream & operator<<(ostream &o,const MyInt& n){
        cout<<n.nVal;
        return o;
    }
    MyInt& operator-(int n){
    nVal-=n;
    return *this;
    }
};
int Inc(int n) {
	return n + 1;
}
int main () {
	int n;
	while(cin >>n) {
		MyInt objInt(n);
		objInt-2-1-3;
		cout << Inc(objInt);
		cout <<",";
		objInt-2-1;
		cout << Inc(objInt) << endl;
	}
	return 0;
}