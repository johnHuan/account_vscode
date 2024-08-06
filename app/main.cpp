#include "common.h"
#include "account_item.h"
int main(void) {
    vector<Account_item> items;
    loadDataFromFile(items);
	bool quit = false;
	while (!quit)
	{
		// 加载主菜单
		showMainMenu();
		
		// 获取键盘输入并进行校验
		char key = readMenuSelection(3);
        switch (key)
        {
        case '1':
            // 1 - 记账
            showAccountingMenu();
            accounting(items);
            break;
        case '2':
            // 2 - 查询
            showQueryMenu();
            query(items);
            break;
        case '3':
            // 3 - 退出
            cout << "\n 确定要退出吗 ? (Y/N): ";
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