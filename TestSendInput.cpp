#include "stdafx.h"
#include "TestSendInput.h"


TestSendInput::TestSendInput()
{
    test1();
}


void TestSendInput::test1()
{
}


void TestSendInput::send_input( const std::string& str )
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


void TestSendInput::send_input_ctrl( const char ch )
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


void TestSendInput::send_input_enter()
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
