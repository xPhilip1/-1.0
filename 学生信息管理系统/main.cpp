#include "main.h"

// 颜色常量定义
#define COLOR_CYAN    3
#define COLOR_YELLOW  6
#define COLOR_WHITE   7

// 设置文本颜色
void setTextColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// 打印彩色文本
void printColorText(const char* text, int color) {
    setTextColor(color);
    cout << text;
    setTextColor(COLOR_WHITE); // 恢复默认颜色
}

// 打印居中彩色文本
void printCenteredColor(const char* text, int width, int color) {
    int len = 0;
    const char* p = text;
    while (*p) {
        len++;
        p++;
    }
    int padding = (width - len) / 2;
    for (int i = 0; i < padding; i++) {
        cout << " ";
    }
    printColorText(text, color);
    setTextColor(COLOR_WHITE); // 恢复默认颜色
}

void displayASCIITitle() {
    cout << endl;

    printColorText("                   ,----,                           ", COLOR_CYAN); cout << endl;
    printColorText("                 ,/   .`|        ____               ", COLOR_CYAN); cout << endl;
    printColorText("  .--.--.      ,`   .'  :      ,'  , `.  .--.--.    ", COLOR_CYAN); cout << endl;
    printColorText(" /  /    '.  ;    ;     /   ,-+-,.' _ | /  /    '.  ", COLOR_CYAN); cout << endl;
    printColorText("|  :  /`. /.'___,/    ,' ,-+-. ;   , |||  :  /`. /  ", COLOR_CYAN); cout << endl;
    printColorText(";  |  |--` |    :     | ,--.'|'   |  ;|;  |  |--`   ", COLOR_CYAN); cout << endl;
    printColorText("|  :  ;_   ;    |.';  ;|   |  ,', |  ':|  :  ;_     ", COLOR_CYAN); cout << endl;
    printColorText(" \\  \\    `.`----'  |  ||   | /  | |  || \\  \\    `.  ", COLOR_CYAN); cout << endl;
    printColorText("  `----.   \\   '   :  ;'   | :  | :  |,  `----.   \\ ", COLOR_CYAN); cout << endl;
    printColorText("  __ \\  \\  |   |   |  ';   . |  ; |--'   __ \\  \\  | ", COLOR_CYAN); cout << endl;
    printColorText(" /  /`--'  /   '   :  ||   : |  | ,     /  /`--'  / ", COLOR_CYAN); cout << endl;
    printColorText("'--'.     /    ;   |.' |   : '  |/     '--'.     /  ", COLOR_CYAN); cout << endl;
    printColorText("  `--'---'     '---'   ;   | |`-'        `--'---'   ", COLOR_CYAN); cout << endl;
    printColorText("                       |   ;/                       ", COLOR_CYAN); cout << endl;
    printColorText("                       '---'                       ", COLOR_CYAN); cout << endl;

    cout << endl;
    printCenteredColor("学生信息管理系统[STMS]", 50, COLOR_YELLOW);
    cout << endl;
    printCenteredColor("欢迎使用", 45, COLOR_CYAN);
    cout << endl << endl;
}

int main()
{
    SqList L;
    L.Stu = new Student[MAXSIZE];
    L.length = 0;
    SetConsoleOutputCP(CP_UTF8); // 控制台输出用 UTF-8
    SetConsoleCP(CP_UTF8);       // 控制台输入用 UTF-8
    displayASCIITitle();
    ifstream infile("Stu_data.txt");
    if (!infile.is_open())
    {
        cout << "the Stu_data.txt subject is blank！" << endl;
    }
    else
    {
        Student temp;
        while (infile >> temp.number >> temp.name >> temp.sex >> temp.age >> temp.grade)
        {
            if (L.length >= MAXSIZE) break;
            L.Stu[L.length++] = temp;
        }
    }
    infile.close();
    Qsort(L, 0, L.length - 1);
    ifstream admfile("Adm_password.txt");
    if (!admfile.is_open())
    {
        cout << "the Adm_password.txt subject is blank！" << endl;
    }
    else
    {
        string readPass;
        if (admfile >> readPass)
        {
            readPass = Decription(readPass);
            adminPassword = readPass;
        }

    }
    admfile.close();
    setTextColor(COLOR_CYAN);
    while (1)
    {
        Log_in(L);
    }
    return 0;
}

void Log_in(SqList& L)
{
    string num;
    int choice;
    setTextColor(COLOR_WHITE);
    cout << "input： 0-exit   |   1-Log in" << endl;
    cout << "choose : ";
    setTextColor(2);
    cin >> choice;
    setTextColor(COLOR_WHITE);
    switch (choice)
    {
    case 0: setTextColor(COLOR_CYAN);
        cout << "--Looking forward your next use!--" << endl;
        setTextColor(COLOR_WHITE);
        exit(0);
        break;
    case 1: cout << "please input account" << endl;
        cout << "account : ";
        setTextColor(2);
        cin >> num;
        setTextColor(COLOR_WHITE);
        if (num == adminAccount)
            Admi_System(L);
        else
            Stu_System(L, num);
        break;
    default: cout << "error input, please input again！！" << endl;
        break;
    }
    cout << endl;
}

void menu_1()
{
    setTextColor(COLOR_CYAN);
    cout << "--welcome to Administrator's menu--" << endl;
    setTextColor(COLOR_WHITE);
    cout << "------------------------------------" << endl;
    cout << "0 -exit" << endl;
    cout << "1 -change the password" << endl;
    cout << "2 -view the student's information" << endl;
    cout << "3 -add student's information" << endl;
    cout << "4 -delete student's information" << endl;
    cout << "5 -change student's information" << endl;
    cout << "6 -view the student's grade" << endl;
    cout << "-----------------------------------" << endl;
}

void menu_2()
{
    setTextColor(COLOR_CYAN);
    cout << "--Student's Information--" << endl;
    setTextColor(COLOR_WHITE);
    cout << "------------------------------------" << endl;
    cout << "0 -exit" << endl;
    cout << "1 -view all students' information" << endl;
    cout << "2 -search student by number" << endl;
    cout << "3 -search student by name" << endl;
    cout << "4 -search students with the last name" << endl;
    cout << "5 -search student in a grade range" << endl;
    cout << "------------------------------------" << endl;
}

void menu_3()
{
    setTextColor(COLOR_CYAN);
    cout << "--Students' Grade--" << endl;
    setTextColor(COLOR_WHITE);
    cout << "------------------------------------" << endl;
    cout << "0 -exit" << endl;
    cout << "1 -pass rate for male students" << endl;
    cout << "2 -pass rate for female students" << endl;
    cout << "3 -pass rate for all students" << endl;
    cout << "------------------------------------" << endl;
}

void menu_4()
{
    setTextColor(COLOR_CYAN);
    cout << "--Change Student's Information--" << endl;
    setTextColor(COLOR_WHITE);
    cout << "------------------------------------" << endl;
    cout << "0 -exit" << endl;
    cout << "1 -change student's number" << endl;
    cout << "2 -change student's name" << endl;
    cout << "3 -change student's sex" << endl;
    cout << "4 -change student's age" << endl;
    cout << "5 -change student's grade" << endl;
    cout << "------------------------------------" << endl;
}

void Stu_System(SqList& L, string num)
{
    cout << "you are a student, so you can only look for your own information" << endl;
    int choice;
    while (1)
    {
        cout << "input 0 -exit  |  1 -continue" << endl;
        cout << "choose : ";
        setTextColor(2);
        cin >> choice;
        setTextColor(COLOR_WHITE);
        if (choice == 0)
            return;
        else if (choice == 1)
        {
            for (int i = 0; i < L.length; i++)
            {
                Student& s = L.Stu[i];
                if (s.number == num)
                {
                    setTextColor(2);
                    cout << left << setw(12) << s.number.c_str() << setw(12) << s.name.c_str() << setw(8) << s.sex.c_str() << setw(8) << s.age << setw(12) << s.grade << endl;
                    setTextColor(COLOR_WHITE);
                    break;
                }
                if (i == L.length - 1)
                    cout << "error! have no information of this student" << endl;
            }
        }
        else
            cout << "error input!!" << endl;
    }
    cout << endl;
}

void Admi_System(SqList& L)
{
    string Pass;
    int time = 3;
    while (time--)
    {
        cout << "--please input the password--" << endl;
        cout << "input : ";
        setTextColor(2);
        cin >> Pass;
        setTextColor(COLOR_WHITE);
        while (Pass == adminPassword)
        {
            cout << endl;
            menu_1();
            time = 3;
            int choice;
            cout << "choose : ";
            setTextColor(2);
            cin >> choice;
            setTextColor(COLOR_WHITE);
            switch (choice)
            {
            case 0: return; break;
            case 1: Admi_change_Password(); break;
            case 2: View_StuInfo(L); break;
            case 3: Add_StuInfo(L); break;
            case 4: Del_StuInfo(L); break;
            case 5: Change_StuInfo(L); break;
            case 6: View_Grade(L); break;
            default: cout << "error input!! pleaase input again" << endl; break;
            }
        }
        cout << "you have ";
        setTextColor(4);
        cout << time;
        setTextColor(COLOR_WHITE);
        cout << " chances remain !" << endl;
    }
    cout << "you have no chance !!!" << endl;
    int choice;
    while (1)
    {
        cout << "input 0 -exit | 1 -find back password" << endl;
        cout << "choose : ";
        setTextColor(2);
        cin >> choice;
        setTextColor(COLOR_WHITE);
        if (choice == 0)
            return;
        else if (choice == 1)
        {
            int security_code, input_code;
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<>dis(100000, 999999);
            security_code = dis(gen);
            ofstream codefile("Security_code.txt", ios::out | ios::trunc);
            codefile << security_code;
            codefile.close();
            cout << "please input the security code" << endl;
            cout << "security code : ";
            setTextColor(2);
            cin >> input_code;
            setTextColor(COLOR_WHITE);
            if (input_code == security_code)
                cout << "your password is " << adminPassword << endl;
            else
                cout << "you really have no chance!!" << endl;
            break;
        }
        else
            cout << "error input!! please input again" << endl;
    }
}

void Change_StuInfo(SqList& L)
{
    int choice;
    string old_number, new_number, new_name;
    int new_age;
    double new_grade;
    while (1)
    {
        menu_4();
        cout << "choose : ";
        setTextColor(2);
        cin >> choice;
        setTextColor(COLOR_WHITE);
        switch (choice)
        {
        case 0: {
            ofstream chaFile("Stu_data.txt", ios::out | ios::trunc);
            for (int i = 0; i < L.length; i++)
                chaFile << L.Stu[i].number << " " << L.Stu[i].name << " " << L.Stu[i].sex << " " << L.Stu[i].age << " " << L.Stu[i].grade << endl;
            chaFile.close();
            return;
            break;
        }
        case 1: {
            cout << "please input the student ID you want to change" << endl;
            cout << "old ID : ";
            setTextColor(2);
            cin >> old_number;
            setTextColor(COLOR_WHITE);
            int cha_index = -1;
            for (int i = 0; i < L.length; i++)
            {
                if (L.Stu[i].number == old_number)
                {
                    cha_index = i;
                    break;
                }
            }
            if (cha_index == -1)
            {
                cout << "have no information of the student" << endl;
                continue;
            }
            setTextColor(COLOR_CYAN);
            cout << left << setw(12) << "学号" << setw(12) << "姓名" << setw(12) << "性别" << setw(12) << "年龄" << setw(12) << "成绩" << endl;
            printColorText("---------------------------------------------------", COLOR_CYAN);
            cout << endl;
            setTextColor(COLOR_WHITE);
            setTextColor(2);
            cout << left << setw(12) << L.Stu[cha_index].number.c_str() << setw(12) << L.Stu[cha_index].name.c_str() << setw(8) << L.Stu[cha_index].sex.c_str() << setw(8) << L.Stu[cha_index].age << setw(12) << L.Stu[cha_index].grade << endl;
            setTextColor(COLOR_WHITE);
            printColorText("---------------------------------------------------", COLOR_CYAN);
            cout << endl;
            cout << "new ID : ";
            setTextColor(2);
            cin >> new_number;
            setTextColor(COLOR_WHITE);
            if (old_number == new_number)
            {
                cout << "the new ID can't be the same as old ID, changed unsuccessfully!!" << endl;
                continue;
            }
            bool dup_num = false;
            for (int i = 0; i < L.length; i++)
            {
                if (L.Stu[i].number == new_number)
                {
                    dup_num = true;
                    cout << "the new student ID already exists, changed unsuccessfully!!" << endl;
                    break;
                }
            }
            if (!dup_num)
            {
                L.Stu[cha_index].number = new_number;
                setTextColor(COLOR_CYAN);
                cout << left << setw(12) << "学号" << setw(12) << "姓名" << setw(12) << "性别" << setw(12) << "年龄" << setw(12) << "成绩" << endl;
                printColorText("---------------------------------------------------", COLOR_CYAN);
                cout << endl;
                setTextColor(COLOR_WHITE);
                setTextColor(2);
                cout << left << setw(12) << L.Stu[cha_index].number.c_str() << setw(12) << L.Stu[cha_index].name.c_str() << setw(8) << L.Stu[cha_index].sex.c_str() << setw(8) << L.Stu[cha_index].age << setw(12) << L.Stu[cha_index].grade << endl;
                setTextColor(COLOR_WHITE);
                printColorText("---------------------------------------------------", COLOR_CYAN);
                cout << endl;
                cout << "changed successfully!!" << endl;
            }
            break;
        }
        case 2: {
            cout << "please input the student ID to modify name" << endl;
            cout << "student ID : ";
            setTextColor(2);
            cin >> old_number;
            setTextColor(COLOR_WHITE);
            int cha_index = -1;
            for (int i = 0; i < L.length; i++)
            {
                if (L.Stu[i].number == old_number)
                {
                    cha_index = i;
                    break;
                }
            }
            if (cha_index == -1)
            {
                cout << "have no information of the student" << endl;
                continue;
            }
            setTextColor(COLOR_CYAN);
            cout << left << setw(12) << "学号" << setw(12) << "姓名" << setw(12) << "性别" << setw(12) << "年龄" << setw(12) << "成绩" << endl;
            printColorText("---------------------------------------------------", COLOR_CYAN);
            cout << endl;
            setTextColor(COLOR_WHITE);
            setTextColor(2);
            cout << left << setw(12) << L.Stu[cha_index].number.c_str() << setw(12) << L.Stu[cha_index].name.c_str() << setw(8) << L.Stu[cha_index].sex.c_str() << setw(8) << L.Stu[cha_index].age << setw(12) << L.Stu[cha_index].grade << endl;
            setTextColor(COLOR_WHITE);
            printColorText("---------------------------------------------------", COLOR_CYAN);
            cout << endl;
            cout << "new name : ";
            setTextColor(2);
            cin >> new_name;
            setTextColor(COLOR_WHITE);
            if (L.Stu[cha_index].name == new_name)
            {
                cout << "the new name can't be the same as old name, changed unsuccessfully!!" << endl;
                continue;
            }
            L.Stu[cha_index].name = new_name;
            setTextColor(COLOR_CYAN);
            cout << left << setw(12) << "学号" << setw(12) << "姓名" << setw(12) << "性别" << setw(12) << "年龄" << setw(12) << "成绩" << endl;
            printColorText("---------------------------------------------------", COLOR_CYAN);
            cout << endl;
            setTextColor(COLOR_WHITE);
            setTextColor(2);
            cout << left << setw(12) << L.Stu[cha_index].number.c_str() << setw(12) << L.Stu[cha_index].name.c_str() << setw(8) << L.Stu[cha_index].sex.c_str() << setw(8) << L.Stu[cha_index].age << setw(12) << L.Stu[cha_index].grade << endl;
            setTextColor(COLOR_WHITE);
            printColorText("---------------------------------------------------", COLOR_CYAN);
            cout << endl;
            cout << "changed successfully!!" << endl;
            break;
        }
        case 3: {
            cout << "please input the student ID to modify sex" << endl;
            cout << "student ID : ";
            setTextColor(2);
            cin >> old_number;
            setTextColor(COLOR_WHITE);
            int cha_index = -1;
            for (int i = 0; i < L.length; i++)
            {
                if (L.Stu[i].number == old_number)
                {
                    cha_index = i;
                    break;
                }
            }
            if (cha_index == -1)
            {
                cout << "have no information of the student" << endl;
                continue;
            }
            setTextColor(COLOR_CYAN);
            cout << left << setw(12) << "学号" << setw(12) << "姓名" << setw(12) << "性别" << setw(12) << "年龄" << setw(12) << "成绩" << endl;
            printColorText("---------------------------------------------------", COLOR_CYAN);
            cout << endl;
            setTextColor(COLOR_WHITE);
            setTextColor(2);
            cout << left << setw(12) << L.Stu[cha_index].number.c_str() << setw(12) << L.Stu[cha_index].name.c_str() << setw(8) << L.Stu[cha_index].sex.c_str() << setw(8) << L.Stu[cha_index].age << setw(12) << L.Stu[cha_index].grade << endl;
            setTextColor(COLOR_WHITE);
            printColorText("---------------------------------------------------", COLOR_CYAN);
            cout << endl;
            if (L.Stu[cha_index].sex == "male")
                L.Stu[cha_index].sex = "female";
            else
                L.Stu[cha_index].sex = "male";
            setTextColor(COLOR_CYAN);
            cout << left << setw(12) << "学号" << setw(12) << "姓名" << setw(12) << "性别" << setw(12) << "年龄" << setw(12) << "成绩" << endl;
            printColorText("---------------------------------------------------", COLOR_CYAN);
            cout << endl;
            setTextColor(COLOR_WHITE);
            setTextColor(2);
            cout << left << setw(12) << L.Stu[cha_index].number.c_str() << setw(12) << L.Stu[cha_index].name.c_str() << setw(8) << L.Stu[cha_index].sex.c_str() << setw(8) << L.Stu[cha_index].age << setw(12) << L.Stu[cha_index].grade << endl;
            setTextColor(COLOR_WHITE);
            printColorText("---------------------------------------------------", COLOR_CYAN);
            cout << endl;
            cout << "changed successfully!!" << endl;
            break;
        }
        case 4: {
            cout << "please input the student ID to modify age" << endl;
            cout << "student ID : ";
            setTextColor(2);
            cin >> old_number;
            setTextColor(COLOR_WHITE);
            int cha_index = -1;
            for (int i = 0; i < L.length; i++)
            {
                if (L.Stu[i].number == old_number)
                {
                    cha_index = i;
                    break;
                }
            }
            if (cha_index == -1)
            {
                cout << "have no information of the student" << endl;
                continue;
            }
            setTextColor(COLOR_CYAN);
            cout << left << setw(12) << "学号" << setw(12) << "姓名" << setw(12) << "性别" << setw(12) << "年龄" << setw(12) << "成绩" << endl;
            printColorText("---------------------------------------------------", COLOR_CYAN);
            cout << endl;
            setTextColor(COLOR_WHITE);
            setTextColor(2);
            cout << left << setw(12) << L.Stu[cha_index].number.c_str() << setw(12) << L.Stu[cha_index].name.c_str() << setw(8) << L.Stu[cha_index].sex.c_str() << setw(8) << L.Stu[cha_index].age << setw(12) << L.Stu[cha_index].grade << endl;
            setTextColor(COLOR_WHITE);
            printColorText("---------------------------------------------------", COLOR_CYAN);
            cout << endl;
            cout << "new age : ";
            setTextColor(2);
            cin >> new_age;
            setTextColor(COLOR_WHITE);
            if (L.Stu[cha_index].age == new_age)
            {
                cout << "the new age can't be the same as old age, changed unsuccessfully!!" << endl;
                continue;
            }
            L.Stu[cha_index].age = new_age;
            setTextColor(COLOR_CYAN);
            cout << left << setw(12) << "学号" << setw(12) << "姓名" << setw(12) << "性别" << setw(12) << "年龄" << setw(12) << "成绩" << endl;
            printColorText("---------------------------------------------------", COLOR_CYAN);
            cout << endl;
            setTextColor(COLOR_WHITE);
            setTextColor(2);
            cout << left << setw(12) << L.Stu[cha_index].number.c_str() << setw(12) << L.Stu[cha_index].name.c_str() << setw(8) << L.Stu[cha_index].sex.c_str() << setw(8) << L.Stu[cha_index].age << setw(12) << L.Stu[cha_index].grade << endl;
            setTextColor(COLOR_WHITE);
            printColorText("---------------------------------------------------", COLOR_CYAN);
            cout << endl;
            cout << "changed successfully!!" << endl;
            break;
        }
        case 5: {
            cout << "please input the student ID to modify grade" << endl;
            cout << "student ID : ";
            setTextColor(2);
            cin >> old_number;
            setTextColor(COLOR_WHITE);
            int cha_index = -1;
            for (int i = 0; i < L.length; i++)
            {
                if (L.Stu[i].number == old_number)
                {
                    cha_index = i;
                    break;
                }
            }
            if (cha_index == -1)
            {
                cout << "have no information of the student" << endl;
                continue;
            }
            setTextColor(COLOR_CYAN);
            cout << left << setw(12) << "学号" << setw(12) << "姓名" << setw(12) << "性别" << setw(12) << "年龄" << setw(12) << "成绩" << endl;
            printColorText("---------------------------------------------------", COLOR_CYAN);
            cout << endl;
            setTextColor(COLOR_WHITE);
            setTextColor(2);
            cout << left << setw(12) << L.Stu[cha_index].number.c_str() << setw(12) << L.Stu[cha_index].name.c_str() << setw(8) << L.Stu[cha_index].sex.c_str() << setw(8) << L.Stu[cha_index].age << setw(12) << L.Stu[cha_index].grade << endl;
            setTextColor(COLOR_WHITE);
            printColorText("---------------------------------------------------", COLOR_CYAN);
            cout << endl;
            cout << "new grade : ";
            setTextColor(2);
            cin >> new_grade;
            setTextColor(COLOR_WHITE);
            if (L.Stu[cha_index].grade == new_grade)
            {
                cout << "the new grade can't be the same as old grade, changed unsuccessfully!!" << endl;
                continue;
            }
            L.Stu[cha_index].grade = new_grade;
            setTextColor(COLOR_CYAN);
            cout << left << setw(12) << "学号" << setw(12) << "姓名" << setw(12) << "性别" << setw(12) << "年龄" << setw(12) << "成绩" << endl;
            printColorText("---------------------------------------------------", COLOR_CYAN);
            cout << endl;
            setTextColor(COLOR_WHITE);
            setTextColor(2);
            cout << left << setw(12) << L.Stu[cha_index].number.c_str() << setw(12) << L.Stu[cha_index].name.c_str() << setw(8) << L.Stu[cha_index].sex.c_str() << setw(8) << L.Stu[cha_index].age << setw(12) << L.Stu[cha_index].grade << endl;
            setTextColor(COLOR_WHITE);
            printColorText("---------------------------------------------------", COLOR_CYAN);
            cout << endl;
            cout << "changed successfully!!" << endl;
            break;
        }
        default: cout << "error input!! please input again" << endl; break;
        }
    }
}

void Del_StuInfo(SqList& L)
{
    setTextColor(COLOR_CYAN);
    cout << "--Delete Student Information--" << endl;
    setTextColor(COLOR_WHITE);
    int choice;
    string de_num;
    while (1)
    {
        cout << "input 0 -exit  |  1 -continue" << endl;
        cout << "choose : ";
        setTextColor(2);
        cin >> choice;
        setTextColor(COLOR_WHITE);
        if (choice == 0)
        {
            Qsort(L, 0, L.length - 1);
            return;
        }
        else if (choice == 1)
        {
            cout << "please input the ID of the student you want to delete" << endl;
            cout << "student ID : ";
            setTextColor(2);
            cin >> de_num;
            setTextColor(COLOR_WHITE);
            int de_index = -1;
            for (int i = 0; i < L.length; i++)
            {
                if (L.Stu[i].number == de_num)
                {
                    de_index = i;
                    break;
                }
            }
            if (de_index == -1)
            {
                cout << "have no information of the student" << endl;
                continue;
            }
            for (int i = de_index; i < L.length - 1; i++)
                L.Stu[i] = L.Stu[i + 1];
            L.length--;
            cout << "the student information deleted successfully!" << endl;
            ofstream delFile("Stu_data.txt", ios::out | ios::trunc);
            for (int i = 0; i < L.length; i++)
                delFile << L.Stu[i].number << " " << L.Stu[i].name << " " << L.Stu[i].sex << " " << L.Stu[i].age << " " << L.Stu[i].grade << endl;
            delFile.close();
        }
        else
            cout << "error input!! please input again" << endl;
    }
}

void View_Grade(SqList& L)
{
    int choice;
    while (1)
    {
        menu_3();
        cout << "choose : ";
        setTextColor(2);
        cin >> choice;
        setTextColor(COLOR_WHITE);
        switch (choice)
        {
        case 0: return; break;
        case 1: View_Gra_male(L); break;
        case 2: View_Gra_female(L); break;
        case 3: View_Gra_all(L); break;
        default: cout << "error input!! please inpuit again" << endl; break;
        }
    }
}

void View_Gra_all(SqList& L)
{
    int pass_num = 0;
    double pass_rate;
    for (int i = 0; i < L.length; i++)
    {
        Student& s = L.Stu[i];
        if (s.grade >= 60)
            pass_num++;
    }
    pass_rate = (double)pass_num / L.length;
    int choice;
    while (1)
    {
        cout << "input 0 -exit  |  1 -continue" << endl;
        cout << "choose : ";
        setTextColor(2);
        cin >> choice;
        setTextColor(COLOR_WHITE);
        if (choice == 0)
            return;
        else if (choice == 1)
        {
            cout << "pass rate of all students : ";
            setTextColor(2);
            cout << pass_rate * 100 << "%" << endl;
            setTextColor(COLOR_WHITE);
        }
        else
            cout << "error input!! please input again" << endl;
    }
}

void View_Gra_female(SqList& L)
{
    int total = 0;
    int pass_num = 0;
    double pass_rate;
    for (int i = 0; i < L.length; i++)
    {
        Student& s = L.Stu[i];
        if (s.sex == "female")
        {
            total++;
            if (s.grade >= 60)
                pass_num++;
        }
    }
    pass_rate = (double)pass_num / total;
    int choice;
    while (1)
    {
        cout << "input 0 -exit  |  1 -continue" << endl;
        cout << "choose : ";
        setTextColor(2);
        cin >> choice;
        setTextColor(COLOR_WHITE);
        if (choice == 0)
            return;
        else if (choice == 1)
        {
            cout << "pass rate of female students : ";
            setTextColor(2);
            cout << pass_rate * 100 << "%" << endl;
            setTextColor(COLOR_WHITE);
        }
        else
            cout << "error input!! please input again" << endl;
    }
}

void View_Gra_male(SqList& L)
{
    int total = 0;
    int pass_num = 0;
    double pass_rate;
    for (int i = 0; i < L.length; i++)
    {
        Student& s = L.Stu[i];
        if (s.sex == "male")
        {
            total++;
            if (s.grade >= 60)
                pass_num++;
        }
    }
    pass_rate = (double)pass_num / total;
    int choice;
    while (1)
    {
        cout << "input 0 -exit  |  1 -continue" << endl;
        cout << "choose : ";
        setTextColor(2);
        cin >> choice;
        setTextColor(COLOR_WHITE);
        if (choice == 0)
            return;
        else if (choice == 1)
        {
            cout << "pass rate of male students : ";
            setTextColor(2);
            cout << pass_rate * 100 << "%" << endl;
            setTextColor(COLOR_WHITE);
        }
        else
            cout << "error input!! please input again" << endl;
    }
}

void View_StuInfo(SqList& L)
{
    int choice;
    while (1)
    {
        menu_2();
        cout << "choose : ";
        setTextColor(2);
        cin >> choice;
        setTextColor(COLOR_WHITE);
        switch (choice)
        {
        case 0: return; break;
        case 1: Output_AllStuInfo(L); break;
        case 2: View_Stu_number(L); break;
        case 3: View_Stu_name(L); break;
        case 4: View_Stu_las_name(L); break;
        case 5: View_Stu_grade(L); break;
        default: cout << "error input!! please inpuit again" << endl; break;
        }
    }
}

void View_Stu_grade(SqList& L)
{
    int choice;
    double min_grade, max_grade;
    while (1)
    {
        cout << "input 0 -exit  |  1 -continue " << endl;
        cout << "choose : ";
        setTextColor(2);
        cin >> choice;
        setTextColor(COLOR_WHITE);
        if (choice == 0)
            return;
        else if (choice == 1)
        {
            cout << "please input the students' grade range" << endl;
            cout << "min grade : ";
            setTextColor(2);
            cin >> min_grade;
            setTextColor(COLOR_WHITE);
            cout << "max grade : ";
            setTextColor(2);
            cin >> max_grade;
            setTextColor(COLOR_WHITE);
            if (min_grade > max_grade || min_grade < 0 || max_grade > 100)
            {
                cout << "error input!! please input again" << endl;
                continue;
            }
            setTextColor(COLOR_CYAN);
            cout << left << setw(12) << "学号" << setw(12) << "姓名" << setw(12) << "性别" << setw(12) << "年龄" << setw(12) << "成绩" << endl;
            printColorText("---------------------------------------------------", COLOR_CYAN);
            cout << endl;
            setTextColor(COLOR_WHITE);
            bool sum = false;
            for (int i = 0; i < L.length; i++)
            {
                Student& s = L.Stu[i];
                if (s.grade >= min_grade && s.grade <= max_grade)
                {
                    sum = true;
                    setTextColor(2);
                    cout << left << setw(12) << s.number.c_str() << setw(12) << s.name.c_str() << setw(8) << s.sex.c_str() << setw(8) << s.age << setw(12) << s.grade << endl;
                    setTextColor(COLOR_WHITE);
                }
                if (sum == false && i == L.length - 1)
                    cout << "error! have no information of this student" << endl;
            }
            printColorText("---------------------------------------------------", COLOR_CYAN);
            cout << endl;
        }
        else
            cout << "error input!! please input again" << endl;
    }
}

void View_Stu_las_name(SqList& L)
{
    int choice;
    string lastname;
    while (1)
    {
        cout << "input 0 -exit  |  1 -continue" << endl;
        cout << "choose : ";
        setTextColor(2);
        cin >> choice;
        setTextColor(COLOR_WHITE);
        if (choice == 0)
            return;
        else if (choice == 1)
        {
            cout << "please input the students' lastname" << endl;
            cout << "lastname : ";
            setTextColor(2);
            cin >> lastname;
            setTextColor(COLOR_WHITE);
            setTextColor(COLOR_CYAN);
            cout << left << setw(12) << "学号" << setw(12) << "姓名" << setw(12) << "性别" << setw(12) << "年龄" << setw(12) << "成绩" << endl;
            printColorText("---------------------------------------------------", COLOR_CYAN);
            cout << endl;
            setTextColor(COLOR_WHITE);
            bool sum = false;
            for (int i = 0; i < L.length; i++)
            {
                Student& s = L.Stu[i];
                if (s.name.substr(0, 3) == lastname)
                {
                    sum = true;
                    setTextColor(2);
                    cout << left << setw(12) << s.number.c_str() << setw(12) << s.name.c_str() << setw(8) << s.sex.c_str() << setw(8) << s.age << setw(12) << s.grade << endl;
                    setTextColor(COLOR_WHITE);
                }
                if (sum == false && i == L.length - 1)
                    cout << "error! have no information of this student" << endl;
            }
            printColorText("---------------------------------------------------", COLOR_CYAN);
            cout << endl;
        }
        else
            cout << "error input!! please input again" << endl;
    }
}

void View_Stu_name(SqList& L)
{
    int choice;
    string name;
    while (1)
    {
        cout << "input 0 -exit  |  1 -continue" << endl;
        cout << "choose : ";
        setTextColor(2);
        cin >> choice;
        setTextColor(COLOR_WHITE);
        if (choice == 0)
            return;
        else if (choice == 1)
        {
            cout << "please input the student's name" << endl;
            cout << "name : ";
            setTextColor(2);
            cin >> name;
            setTextColor(COLOR_WHITE);
            for (int i = 0; i < L.length; i++)
            {
                Student& s = L.Stu[i];
                if (s.name == name)
                {
                    setTextColor(COLOR_CYAN);
                    cout << left << setw(12) << "学号" << setw(12) << "姓名" << setw(12) << "性别" << setw(12) << "年龄" << setw(12) << "成绩" << endl;
                    printColorText("---------------------------------------------------", COLOR_CYAN);
                    cout << endl;
                    setTextColor(COLOR_WHITE);
                    setTextColor(2);
                    cout << left << setw(12) << s.number.c_str() << setw(12) << s.name.c_str() << setw(8) << s.sex.c_str() << setw(8) << s.age << setw(12) << s.grade << endl;
                    setTextColor(COLOR_WHITE);
                    printColorText("---------------------------------------------------", COLOR_CYAN);
                    cout << endl;
                    break;
                }
                if (i == L.length - 1)
                    cout << "error! have no information of this student" << endl;
            }
        }
        else
            cout << "error input!! please input again" << endl;
    }
}

void View_Stu_number(SqList& L)
{
    int choice;
    string num;
    while (1)
    {
        cout << "input 0 -exit  |  1 -continue" << endl;
        cout << "choose : ";
        setTextColor(2);
        cin >> choice;
        setTextColor(COLOR_WHITE);
        if (choice == 0)
            return;
        else if (choice == 1)
        {
            cout << "please input the student's number" << endl;
            cout << "number : ";
            setTextColor(2);
            cin >> num;
            setTextColor(COLOR_WHITE);
            for (int i = 0; i < L.length; i++)
            {
                Student& s = L.Stu[i];
                if (s.number == num)
                {
                    setTextColor(COLOR_CYAN);
                    cout << left << setw(12) << "学号" << setw(12) << "姓名" << setw(12) << "性别" << setw(12) << "年龄" << setw(12) << "成绩" << endl;
                    printColorText("---------------------------------------------------", COLOR_CYAN);
                    cout << endl;
                    setTextColor(COLOR_WHITE);
                    setTextColor(2);
                    cout << left << setw(12) << s.number.c_str() << setw(12) << s.name.c_str() << setw(8) << s.sex.c_str() << setw(8) << s.age << setw(12) << s.grade << endl;
                    setTextColor(COLOR_WHITE);
                    printColorText("---------------------------------------------------", COLOR_CYAN);
                    cout << endl;
                    break;
                }
                if (i == L.length - 1)
                    cout << "error! have no information of this student" << endl;
            }
        }
        else
            cout << "error input!! please input again" << endl;
    }
}

void Add_StuInfo(SqList& L)
{
    setTextColor(COLOR_CYAN);
    cout << "--Add Student's Information--" << endl;
    setTextColor(COLOR_WHITE);
    int choice;
    Student s;
    while (1)
    {
        cout << "input 0 -exit  |  1 -continue" << endl;
        cout << "choose : ";
        setTextColor(2);
        cin >> choice;
        setTextColor(COLOR_WHITE);
        if (choice == 0)
        {
            Qsort(L, 0, L.length - 1);
            return;
        }
        else if (choice == 1)
        {
            cout << "please input the student's information" << endl;
            cout << "student ID : ";
            setTextColor(2);
            cin >> s.number;
            setTextColor(COLOR_WHITE);
            cout << "name : ";
            setTextColor(2);
            cin >> s.name;
            setTextColor(COLOR_WHITE);
            cout << "sex : ";
            setTextColor(2);
            cin >> s.sex;
            setTextColor(COLOR_WHITE);
            cout << "age : ";
            setTextColor(2);
            cin >> s.age;
            setTextColor(COLOR_WHITE);
            cout << "grade : ";
            setTextColor(2);
            cin >> s.grade;
            setTextColor(COLOR_WHITE);
            if (s.grade > 100 || s.grade < 0)
            {
                cout << "grade must from 0 to 100!!" << endl;
                continue;
            }
            if (L.length >= MAXSIZE)
            {
                cout << "Student list is full, added unsuccessfully!!" << endl;
                return;
            }
            L.Stu[L.length] = s;
            L.length++;
            ofstream addfile("Stu_data.txt", ios::out | ios::app);
            if (!addfile.is_open())
                cout << "txt opend unsuccessfully!! can't save the new student" << endl;
            addfile << s.number << " " << s.name << " " << s.sex << " " << s.age << " " << s.grade << endl;
            addfile.close();
            cout << "added successfully!!" << endl;
        }
        else
            cout << "error input!! please input again" << endl;
    }
}

void Admi_change_Password()
{
    string new_password, old_password, confirm_password;
    int choice;
    setTextColor(COLOR_CYAN);
    cout << "--Change The Administrator's Password--" << endl;
    setTextColor(COLOR_WHITE);
    cout << "input 0 -exit | 1 -continue" << endl;
    cout << "choose : ";
    setTextColor(2);
    cin >> choice;
    setTextColor(COLOR_WHITE);
    switch (choice)
    {
    case 0: return; break;
    case 1: cout << "please input the old password" << endl;
        cout << "input : ";
        setTextColor(2);
        cin >> old_password;
        setTextColor(COLOR_WHITE);
        while (old_password == adminPassword)
        {
            string save_password;
            cout << "please input the new password" << endl;
            cout << "input : ";
            setTextColor(2);
            cin >> new_password;
            setTextColor(COLOR_WHITE);
            cout << "please confirm the new password" << endl;
            cout << "input : ";
            setTextColor(2);
            cin >> confirm_password;
            setTextColor(COLOR_WHITE);
            if (new_password == confirm_password)
            {
                save_password = Encription(new_password);
                ofstream outfile("Adm_password.txt");
                if (!outfile.is_open())
                    cout << "txt opend unsuccessfully!! can't save the new password" << endl;
                outfile << save_password;
                outfile.close();
                adminPassword = new_password;
                cout << "password changed successfully!!" << endl;
                return;
            }
            else
                cout << "the two inputs don't match!! please input again" << endl;
        }
        cout << "old password is wrong, you can't change the password" << endl;
        break;
    default:cout << "error input!! please input again" << endl; break;
    }
}

void Output_AllStuInfo(SqList& L)
{
    setTextColor(COLOR_CYAN);
    cout << left << setw(12) << "学号" << setw(12) << "姓名" << setw(12) << "性别" << setw(12) << "年龄" << setw(12) << "成绩" << endl;
    printColorText("---------------------------------------------------", COLOR_CYAN);
    cout << endl;
    setTextColor(COLOR_WHITE);
    for (int i = 0; i < L.length; i++)
    {
        Student& s = L.Stu[i];
        if (s.grade >= 60)
            setTextColor(2);
        else
            setTextColor(4);
        cout << left << setw(12) << s.number.c_str() << setw(12) << s.name.c_str() << setw(8) << s.sex.c_str() << setw(8) << s.age << setw(12) << s.grade << endl;
        setTextColor(COLOR_WHITE);
    }
    printColorText("---------------------------------------------------", COLOR_CYAN);
    cout << endl;
}

string Encription(string password)
{
    string result = password;
    for (size_t i = 0; i < password.size(); i++)
    {
        result[i] = password[i] ^ key[i % key.length()];
    }
    return result;
}

string Decription(string password)
{
    string result = password;
    for (size_t i = 0; i < password.size(); i++)
    {
        result[i] = password[i] ^ key[i % key.length()];
    }
    return result;
}

double Partition(SqList& L, int low, int high)
{
    Student temp = L.Stu[low];
    double pivotkey = L.Stu[low].grade;
    while (low < high)
    {
        while (low < high && L.Stu[high].grade <= pivotkey) --high;
        if (low < high) L.Stu[low] = L.Stu[high];
        while (low < high && L.Stu[low].grade >= pivotkey) ++low;
        if (low < high) L.Stu[high] = L.Stu[low];
    }
    L.Stu[low] = temp;
    return low;
}

void Qsort(SqList& L, int low, int high)
{
    int pivotloc;
    if (low < high)
    {
        pivotloc = Partition(L, low, high);
        Qsort(L, low, pivotloc - 1);
        Qsort(L, pivotloc + 1, high);
    }
}
