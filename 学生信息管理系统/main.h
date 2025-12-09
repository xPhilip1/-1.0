#pragma execution_character_set("utf-8")
#include <iostream>
#include <string.h>
#include <fstream>
#include <Windows.h>
#include <iomanip>
#include <random>
using namespace std;

#define MAXSIZE 30
string adminPassword = "123456";
string adminAccount = "2423428";
string key = "secritekey";

typedef struct {
    string number;
    string name;
    string sex;
    int age;
    double grade;
}Student;

typedef struct {
    Student* Stu;
    int length;
}SqList;

void Log_in(SqList& L); //登录系统 
void menu_1(); //主菜单
void menu_2();
void menu_3();
void menu_4();
void Admi_System(SqList& L); //管理员系统
void Stu_System(SqList& L, string num); //学生系统
void Admi_change_Password(); //管理员修改密码
void Add_StuInfo(SqList& L); //添加学生信息
void Del_StuInfo(SqList& L); //删除学生信息
void Change_StuInfo(SqList& L); //改变学生信息
void Output_AllStuInfo(SqList& L); //浏览所有学生信息
void View_StuInfo(SqList& L); //查询学生信息
void View_Grade(SqList& L); //查询成绩
void View_Stu_number(SqList& L); //按学号查询学生
void View_Stu_name(SqList& L); //按姓名查询学生
void View_Stu_las_name(SqList& L); //按姓氏查找学生
void View_Stu_grade(SqList& L);//按成绩查找一档学生
void View_Gra_male(SqList& L); //查询男生合格率
void View_Gra_female(SqList& L); //查询女生合格率
void View_Gra_all(SqList& L); //查询全班合格率
void setTextColor(int color);
void printColorText(const char* text, int color);
void printCenteredColor(const char* text, int width, int color);
void displayASCIITitle();
double Partition(SqList& L, int low, int high);
void Qsort(SqList& L, int low, int high);//快速排序 
string Encription(string password);//加密
string Decription(string password);//解密

