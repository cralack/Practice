#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;
const char*  CodeAuthor = "Honduras Iron Egg";
const int       N = 30;
const double EPS = 1e-6;

class MyString {
    char * p;
public:
    friend ostream & operator<<(ostream&o,const MyString&s);
    MyString(const char * s) {
        if( s) {
            p = new char[strlen(s) + 1];
            strcpy(p,s);
        }
        else
            p = NULL;

    }
    ~MyString() { if(p) delete [] p; }
    MyString(const MyString & str)
    {
        if(str.p){
            p=new char[strlen(str.p)+1];
            memcpy(p,str.p,strlen(str.p));
        }
        else p=NULL;
    }
    MyString& Copy(const char *str_)
    {
        memcpy(p,str_,strlen(str_));
    }
};
ostream & operator<<(ostream&o,const MyString&s){o<<s.p;return o;}
int main()
{
    char w1[200],w2[100];
    while( cin >> w1 >> w2) {
        MyString s1(w1),s2 = s1;
        MyString s3(NULL);
        s3.Copy(w1);
        cout << s1 << "," << s2 << "," << s3 << endl;

        s2 = w2;
        s3 = s2;
        s1 = s3;
        cout << s1 << "," << s2 << "," << s3 << endl;

    }
}