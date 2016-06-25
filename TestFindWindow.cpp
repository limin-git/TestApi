#include "stdafx.h"
#include "TestFindWindow.h"


TestFindWindow::TestFindWindow()
{
    test1();
}


void TestFindWindow::test1()
{
    const std::wstring class_name = L"MediaPlayerClassicW";
    const std::wstring window_name = L"Cell 2016 720p WEB-DL x264 AC3-JYK.mkv";

    HWND hwnd = FindWindow( class_name.c_str(), window_name.c_str() );

    if ( hwnd == NULL )
    {
        std::cout << "can not find window " << std::endl;
    }

    SetForegroundWindow( hwnd );

    send_input_ctrl( 'G' );
    send_input( "002353");
    send_input_enter();
}


void TestFindWindow::send_input( const std::string& str )
{
    INPUT i;
    i.type = INPUT_KEYBOARD;
    i.ki.wVk = 0;
    i.ki.dwFlags = 0;
    i.ki.dwExtraInfo = NULL;
    i.ki.wScan = 0;
    i.ki.time = 0;

    for ( size_t x = 0; x < str.size(); ++x )
    {
        i.ki.wVk = str[x];
        i.ki.dwFlags = 0;
        SendInput( 1, &i, sizeof(INPUT) );

        i.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput( 1, &i, sizeof(INPUT) );
    }
}


void TestFindWindow::send_input_ctrl( const char ch )
{
    INPUT i;
    i.type = INPUT_KEYBOARD;
    i.ki.wVk = 0;
    i.ki.dwFlags = 0;
    i.ki.dwExtraInfo = NULL;
    i.ki.wScan = 0;
    i.ki.time = 0;

    i.ki.wVk = VK_CONTROL;
    SendInput( 1, &i, sizeof(INPUT) );
    i.ki.wVk = ch;
    SendInput( 1, &i, sizeof(INPUT) );

    i.ki.dwFlags = KEYEVENTF_KEYUP;

    i.ki.wVk = ch;
    SendInput( 1, &i, sizeof(INPUT) );
    i.ki.wVk = VK_CONTROL;
    SendInput( 1, &i, sizeof(INPUT) );
}


void TestFindWindow::send_input_enter()
{
    INPUT i;
    i.type = INPUT_KEYBOARD;
    i.ki.wVk = VK_RETURN;
    i.ki.dwFlags = 0;
    i.ki.dwExtraInfo = NULL;
    i.ki.wScan = 0;
    i.ki.time = 0;

    SendInput( 1, &i, sizeof(INPUT) );
    i.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput( 1, &i, sizeof(INPUT) );
}
