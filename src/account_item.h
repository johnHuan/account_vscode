#pragma once
#include "common.h"



// ����ṹ��
struct Account_item
{
    /* data */
    string itemType;
    int amount;
    string detail;
};


// ����˻����ݽ��в����ĺ�������

// ������Ŀ����
void loadDataFromFile(vector<Account_item> &items);

// ����
void accounting(vector<Account_item> &items);

// ��һ����Ŀд���ļ���
void insert2File(const Account_item & item);

// ��¼һ������
void income (vector<Account_item> & items);

// ��¼һ��֧��
void expand (vector<Account_item> & items);

// ��ѯ
void query(const vector<Account_item> &items);

// ��ѯ��Ŀ���ܺ���
void queryItems(const vector<Account_item> & items);

// ��������
void queryItems(const vector<Account_item> & items, const string itemType);

// ��ӡ���һ����Ŀ��Ϣ
void printItem(const Account_item & item);