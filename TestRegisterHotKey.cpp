#include "stdafx.h"
#include "TestRegisterHotKey.h"


TestRegisterHotKey::TestRegisterHotKey()
{
    //test1();

    boost::thread t( boost::bind( &TestRegisterHotKey::test1, this ) );
    while ( true )
    {
        std::cout << _getch() << std::endl;
    }

}


void TestRegisterHotKey::test1()
{
    MSG msg = {0};
    HWND hConsole = GetActiveWindow(); // ��ȡ��ǰ��ʾ���ڵľ����������̨������ڵľ����

    RegisterHotKey(
        hConsole,   // ע���ݼ��Ĵ��ھ��
        1,          // �ȼ���ʶ��
        MOD_CONTROL,// | MOD_NOREPEAT, // Ctrl ��  No Repeat ���ظ�����
        'A'         // A
        );  // Ctrl + A

    RegisterHotKey(hConsole, 2, 0/* | MOD_NOREPEAT*/,VK_BROWSER_BACK);// Ctrl + B
    RegisterHotKey(hConsole, 3, 0 /*| MOD_NOREPEAT*/,VK_BROWSER_FORWARD);    // Alt + A
    //RegisterHotKey(hConsole, 4, MOD_ALT /*| MOD_NOREPEAT*/,'B');    // Alt + B
    //RegisterHotKey(hConsole, 5, MOD_NOREPEAT,'S');              // ֱ�Ӱ� S


    // ѭ����ȡ����ϵͳ��������Ϣ
    while (GetMessage(&msg, NULL, 0, 0) != 0)
    {
        // ���յ���ݼ���Ϣʱ
        if (msg.message == WM_HOTKEY)
        {
            switch(msg.wParam)
            {
            case 1:
                printf("Ctrl + A �����£� \n\n");
                break;

            case 2:
                printf("Ctrl + B �����£� \n\n");
                break;

            case 3:
                printf("Alt + A �����£� \n\n");
                break;

            case 4:
                printf("Alt + B �����£� \n\n");
                break;

            case 5:
                printf("S �����£� \n\n");
                break;
            }
        }
    }
}
