#include "common.h"
#include "account_item.h"
int main(void) {
    vector<Account_item> items;
    loadDataFromFile(items);
	bool quit = false;
	while (!quit)
	{
		// �������˵�
		showMainMenu();
		
		// ��ȡ�������벢����У��
		char key = readMenuSelection(3);
        switch (key)
        {
        case '1':
            // 1 - ����
            showAccountingMenu();
            accounting(items);
            break;
        case '2':
            // 2 - ��ѯ
            showQueryMenu();
            query(items);
            break;
        case '3':
            // 3 - �˳�
            cout << "\n ȷ��Ҫ�˳��� ? (Y/N): ";
            if (readQuitConfirm() == 'Y')
                quit = true;
            break;
        default:
            break;
        }
        cout << endl;
	}
	return 0;
}