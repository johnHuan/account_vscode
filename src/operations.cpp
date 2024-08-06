#include "common.h"
#include "account_item.h"

// ��ȡ�ļ��е���Ŀ����
void loadDataFromFile(vector<Account_item> &items){
    ifstream input(FILENAME);
    // ���ж�ȡÿһ����Ŀ���ڰ�װ��accountItem����
    Account_item item;
    while (input >> item.itemType >> item.amount >> item.detail) {
        items.push_back(item);
    }
    input.close();
}

// **************************************************1. ����*************************
// ����
void accounting(vector<Account_item> & items){
    // ��ȡ����ѡ�񣬲����Ϸ���У��
    char key = readMenuSelection(3);
    switch (key) {
        case '1':
            // 1 - ����
            income(items);
            break;
        case '2':  
            // 2 - ֧��
            expand(items);
            break;
        default:
            break;
    }
}

// ��¼һ������
void income (vector<Account_item> & items){
    // �¹���һ��Account_item����
    Account_item item;
    // �����Ѿ����壬��������
    item.itemType = INCOME;
    // ���û�����������������ͱ�ע��Ϣ
    cout<<"\n ��������� ";
    item.amount = readAmount();
    cout<< "\n ��ע��";
    getline(cin, item.detail);
    // ��ӵ�vector��
    items.push_back(item);
    // д�뵽�ļ��У����־û�����
    insert2File(item);
    // ��ʾ�ɹ���Ϣ
    cout<< "\n------------------------���˳ɹ�---------------------\n" <<endl;
    cout<<"\n�밲�س����������˵�..."<<endl;
    string line;
    getline(cin, line);
}

// ��¼һ��֧��
void expand (vector<Account_item> & items){
    // �¹���һ��Account_item����
    Account_item item;
    // �����Ѿ����壬����֧��
    item.itemType = EXPAND;
    // ���û�����������������ͱ�ע��Ϣ
    cout<<"\n ����֧���� ";
    item.amount = - readAmount();
    cout<< "\n ��ע��";
    getline(cin, item.detail);
    // ��ӵ�vector��
    items.push_back(item);
    // д�뵽�ļ��У����־û�����
    insert2File(item);
    // ��ʾ�ɹ���Ϣ
    cout<< "\n------------------------���˳ɹ�---------------------\n" <<endl;
    cout<<"\n�밲�س����������˵�..."<<endl;
    string line;
    getline(cin, line);
}


// ��һ����Ŀд���ļ���
void insert2File(const Account_item & item) {
    // ����һ��ofstream�� ��׷�ӵķ�ʽ����д��
    ofstream output(FILENAME, ios::out | ios::app);
    output<<item.itemType << "\t" << item.amount <<"\t"<<item.detail<<endl;
    output.close();
}


// **************************************************1. ��ѯ*************************
// ��ѯ����
void query(const vector<Account_item> & items){
    // ��ȡ����ѡ�񣬲����Ϸ���У��
    char key = readMenuSelection(4);
    cout<<"�����ˣ�"<<key<<endl;
    switch (key)
    {
    case '1':
        // 1 - ��ѯ������Ŀ����ͳ��������
        queryItems(items);
        break;
    case '2':  
        // 2 - ��ѯ�������룬ͳ��������
        queryItems(items, INCOME);
        break;
    case '3':  
        // 3- ��ѯ֧����ͳ����֧��
        queryItems(items, EXPAND);
        break;
    default:
        break;
    }
}


// ��ѯ��Ŀ���ܺ���
void queryItems(const vector<Account_item> & items){
    cout<<"------------------��ѯ���-----------------------"<<endl;
    cout<< "\n ���� \t\t ��� \t\t ��ע \n"<<endl;
    // ����������Ŀ
    int total = 0;
    for (auto item: items){
        printItem(item);
        total += item.amount;
    }

    // �����Ϣ
    cout<< "====================================="<<endl;
    cout<<"����֧��"<<total<<endl;
    cout<<"\n �밴�س����������˵�.... " <<endl;
    string line;
    getline(cin, line);
}


// ��������
void queryItems(const vector<Account_item> & items, const string itemType){
    cout<<"------------------��ѯ���-----------------------"<<endl;
    cout<< "\n ����\t\t���\t\t��ע\n"<<endl;
    // ����������Ŀ,ͳ�����������֧��
    int total = 0;
    for (auto item: items){
        if (item.itemType != itemType) 
            continue;
        printItem(item);
        total += item.amount;   
    }
    // �����Ϣ
    cout<< "====================================="<<endl;
    cout<<((itemType==INCOME) ? "������" : "��֧����") << total <<endl;
    cout<<"\n  �밴�س����������˵�....  " <<endl;
    string line;
    getline(cin, line);
}

// ��ӡ���һ����Ŀ��Ϣ
void printItem(const Account_item & item){
    cout << item.itemType << "\t\t" << item.amount << "\t\t" << item.detail << endl;   
}