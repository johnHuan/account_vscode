#include "common.h"

// 读取键盘输入菜单选项，进行合法性校验
char readMenuSelection(int options){
    string str;    
    while (true) {
        getline(cin, str);
        if (str.size() != 1 ||  0 >= str[0] -'0' || str[0] - '0' > 3) {
            cout<<"输入错误，请重新选择：";
        } else {
            break;
        }
    }
    // 输入合法
    return str[0];
}

// 读取确认退出
char readQuitConfirm(){
    string str;    
    while (true) {
        getline(cin, str);
        // cout << "输入的字符为：" << str << " \t size: " <<str.size() << endl;
        if (str.size() != 1 || toupper(str[0]) != 'Y' && toupper(str[0]) != 'N') {
            cout<<"输入错误, 请重新输入(Y/N): ";
        } else {
            break;
        }
    }
    // 输入合法
    return toupper(str[0]);
}

// 读取键盘输入的金额数，并做合法性校验
int readAmount(){
    int amount;
    string str;
    while (true) {
        getline(cin, str);
        try{
            amount = stoi(str);
            break;
        } catch (invalid_argument e) {
            cout<<"输入错误，请输入正确的数字！！"<<endl;
        }
    }
    return amount;
}