#pragma once
#include "common.h"



// 定义结构体
struct Account_item
{
    /* data */
    string itemType;
    int amount;
    string detail;
};


// 针对账户数据进行操作的函数申明

// 加载账目数据
void loadDataFromFile(vector<Account_item> &items);

// 记账
void accounting(vector<Account_item> &items);

// 将一条账目写入文件中
void insert2File(const Account_item & item);

// 记录一笔收入
void income (vector<Account_item> & items);

// 记录一笔支出
void expand (vector<Account_item> & items);

// 查询
void query(const vector<Account_item> &items);

// 查询账目功能函数
void queryItems(const vector<Account_item> & items);

// 函数重载
void queryItems(const vector<Account_item> & items, const string itemType);

// 打印输出一条账目信息
void printItem(const Account_item & item);