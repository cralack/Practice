#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
const char* CodeAuthor = "Honduras Iron Egg";
const double EPS = 1e-6;
const int N = 100;
const char* weapon[3] = { "sword", "bomb", "arrow" };
const char* name[5] = { "dragon", "ninja", "icemen" , "lion" , "wolf" };

class Warrior {
protected:
    int hp = 0;
    int type;
public:
    Warrior(int type_) :type(type_) { }
    Warrior(const Warrior& w) {
        type = w.type;
        hp = w.hp;
    }
    virtual ~Warrior() { }
};

class Red_Warrior :public Warrior {
private:
    const char* camp = "red";
    char w_name[10];
    char o_weapon[10];
public:
    static int no;
    static int mp;
    static int count[5];
    Red_Warrior(int n, int arr[]) :Warrior(n) {
        int list[5] = { 2,3,4,1,0 };
        //红方 iceman、lion、wolf、ninja、dragon的顺序
        type = list[type];
        hp = arr[type];
        count[type]++;
        mp -= hp;
        no++;
        strcpy(w_name, name[type]);
        strcpy(o_weapon, weapon[no % 3]);
        printf("%s %s %d born with strength %d,%d %s in %s headquarter\n", camp, w_name, no, hp, count[type], w_name, camp);
        switch (type)
        {
        case 0://Dragon
            float tmp; tmp = mp * 1.0 / hp;
            printf("It has a %s,and it's morale is %.2f\n", o_weapon, tmp);
            break;
        case 1://Ninja
            printf("It has a %s and a %s\n", o_weapon, weapon[(no + 1) % 3]);
            break;
        case 2://Icemen
            printf("It has a %s\n", o_weapon);
            break;
        case 3://Lion
            printf("It's loyalty is %d\n", mp);
            break;
        case 4://Wolf
            break;
        default:
            break;
        }
    }
    static int End(int arr[]) {
        int count = 0;
        for (int i = 0; i < 5; i++)
            if (mp < arr[i]) count++;
        if (count == 5) return 0;
        else return 1;
    }
};
int Red_Warrior::no = 0;
int Red_Warrior::mp = 0;
int Red_Warrior::count[] = { 0 };

class Blue_Warrior :public Warrior {
private:
    const char* camp = "blue";
    char w_name[10];
    char o_weapon[10];
public:
    static int no;
    static int mp;
    static int count[5];
    Blue_Warrior(int n, int arr[]) :Warrior(n) {
        int list[5] = { 3,0,1,2,4 };
        //蓝方 lion、dragon、ninja、iceman、wolf的顺序
        type = list[type];
        hp = arr[type];
        count[type]++;
        mp -= hp;
        no++;
        strcpy(w_name, name[type]);
        strcpy(o_weapon, weapon[no % 3]);
        printf("%s %s %d born with strength %d,%d %s in %s headquarter\n", camp, w_name, no, hp, count[type], w_name, camp);
        switch (type)
        {
        case 0://Dragon
            double tmp; tmp = mp * 1.0 / hp;
            printf("It has a %s,and it's morale is %2f\n", o_weapon, tmp);
            break;
        case 1://Ninja
            printf("It has a %s and a %s\n", o_weapon, weapon[(no + 1) % 3]);
            break;
        case 2://Icemen
            printf("It has a %s\n", o_weapon);
            break;
        case 3://Lion
            printf("It's loyalty is %d\n", mp);
            break;
        case 4://Wolf
            break;
        default:
            break;
        }
    }
    static int End(int arr[]) {
        int count = 0;
        for (int i = 0; i < 5; i++)
            if (mp < arr[i]) count++;
        if (count == 5) return 0;
        else return 1;
    }
};
int Blue_Warrior::no = 0;
int Blue_Warrior::mp = 0;
int Blue_Warrior::count[] = { 0 };

int main(void) {
    int mp = 0, time = 0, group = 0, hp[5] = { 0 }, ret;
    //计数回合，测试组数，勇士初始生命dragon 、ninja、iceman、lion、wolf
    ret = scanf("%d", &group);
    for (int i = 0; i < group; i++)
    {
        ret = scanf("%d", &mp);
        Red_Warrior::mp = mp;
        Blue_Warrior::mp = mp;
        for (int j = 0; j < 5; j++)
            ret = scanf("%d", &hp[j]);
        bool red_switch = 0, blue_switch = 0;
        printf("Case:%d\n", i + 1);
        do
        {
            int type = time % 5;
            //Red
            if (!Red_Warrior::End(hp) && !red_switch) {
                printf("%03d ", time);
                printf("red headquarter stops making warriors\n");
                red_switch = 1;
            }
            if (!red_switch) {
                printf("%03d ", time);
                Red_Warrior red(type, hp);
            }
            //Blue
            if (!Blue_Warrior::End(hp) && !blue_switch) {
                printf("%03d ", time);
                printf("blue headquarter stops making warriors\n");
                blue_switch = 1;
            }
            if (!blue_switch) {
                printf("%03d ", time);
                Blue_Warrior red(type, hp);
            }
            time++;
        } while (Blue_Warrior::End(hp) || Red_Warrior::End(hp));
    }

    return 0;
}