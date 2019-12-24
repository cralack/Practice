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
    friend ostream & operator<<(ostream&o,const MyString&s){o<<s.p;return o;}
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
            strcpy(p,str.p);
        }
        else p=NULL;
    }
    void Copy(const char *str)
    {
        if (str)
        {
            delete[]p;
            p=new char[strlen(str)+1];
            strcpy(p,str);
        }
        else
        {
            p=NULL;
        }
    }
    MyString & operator =(const char * str){
        if(str){
            delete[]p;
            p=new char[strlen(str)+1];
            strcpy(p,str);
            return *this;
        }
        else p=NULL;
    }
    MyString & operator =(const MyString& s){
        if (this == &s) {
            return *this;
        }
        if(s.p){
            delete[]p;
            p=new char[strlen(s.p)+1];
            strcpy(p,s.p);
            return *this;
        }
        else p=NULL;
    }
};
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