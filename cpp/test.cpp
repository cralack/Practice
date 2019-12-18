#include<iostream>
#include<cstring>
#include<string>
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include<memory>
using namespace std;
const char*  CodeAuthor = "Honduras Iron Egg";
const int    N = 30;
const double EPS = 1e-6;

class Sample {
public:
	int v;
    Sample(){}
    Sample(int n){v=n;}
    Sample(const Sample&s){v=s.v+2;}
};
void PrintAndDouble(Sample o)
{
	cout << o.v;
	cout << endl;
}
int main()
{
	Sample a(5);
	Sample b = a;
	PrintAndDouble(b);
	Sample c = 20;
	PrintAndDouble(c);
	Sample d;
	d = a;
	cout << d.v;
	return 0;
}