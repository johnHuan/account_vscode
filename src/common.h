#pragma once 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


#define INCOME "����"
#define EXPAND "֧��"

#define FILENAME "C:\\code\\workspace\\c\\demo1\\data.txt"


using namespace std;



// ͨ�ù����Ժ�������

// ���Ʋ˵��ĺ���
void showMainMenu();
void showAccountingMenu();
void showQueryMenu();

// ��ȡ���̽��кϷ���У��
char readMenuSelection(int options);
char readQuitConfirm();
int readAmount();