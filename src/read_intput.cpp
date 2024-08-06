#include "common.h"

// ��ȡ��������˵�ѡ����кϷ���У��
char readMenuSelection(int options){
    string str;    
    while (true) {
        getline(cin, str);
        if (str.size() != 1 ||  0 >= str[0] -'0' || str[0] - '0' > 3) {
            cout<<"�������������ѡ��";
        } else {
            break;
        }
    }
    // ����Ϸ�
    return str[0];
}

// ��ȡȷ���˳�
char readQuitConfirm(){
    string str;    
    while (true) {
        getline(cin, str);
        // cout << "������ַ�Ϊ��" << str << " \t size: " <<str.size() << endl;
        if (str.size() != 1 || toupper(str[0]) != 'Y' && toupper(str[0]) != 'N') {
            cout<<"�������, ����������(Y/N): ";
        } else {
            break;
        }
    }
    // ����Ϸ�
    return toupper(str[0]);
}

// ��ȡ��������Ľ�����������Ϸ���У��
int readAmount(){
    int amount;
    string str;
    while (true) {
        getline(cin, str);
        try{
            amount = stoi(str);
            break;
        } catch (invalid_argument e) {
            cout<<"���������������ȷ�����֣���"<<endl;
        }
    }
    return amount;
}