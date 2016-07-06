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
    HWND hConsole = GetActiveWindow(); // 获取当前显示窗口的句柄（即控制台这个窗口的句柄）

    RegisterHotKey(
        hConsole,   // 注册快捷键的窗口句柄
        1,          // 热键标识符
        MOD_CONTROL,// | MOD_NOREPEAT, // Ctrl 键  No Repeat 不重复发送
        'A'         // A
        );  // Ctrl + A

    RegisterHotKey(hConsole, 2, 0/* | MOD_NOREPEAT*/,VK_BROWSER_BACK);// Ctrl + B
    RegisterHotKey(hConsole, 3, 0 /*| MOD_NOREPEAT*/,VK_BROWSER_FORWARD);    // Alt + A
    //RegisterHotKey(hConsole, 4, MOD_ALT /*| MOD_NOREPEAT*/,'B');    // Alt + B
    //RegisterHotKey(hConsole, 5, MOD_NOREPEAT,'S');              // 直接按 S


    // 循环获取操作系统发来的消息
    while (GetMessage(&msg, NULL, 0, 0) != 0)
    {
        // 当收到快捷键消息时
        if (msg.message == WM_HOTKEY)
        {
            switch(msg.wParam)
            {
            case 1:
                printf("Ctrl + A 被按下！ \n\n");
                break;

            case 2:
                printf("Ctrl + B 被按下！ \n\n");
                break;

            case 3:
                printf("Alt + A 被按下！ \n\n");
                break;

            case 4:
                printf("Alt + B 被按下！ \n\n");
                break;

            case 5:
                printf("S 被按下！ \n\n");
                break;
            }
        }
    }
}
