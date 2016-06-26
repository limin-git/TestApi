#include "stdafx.h"
#include "TestFindWindow.h"
#include "TestSendInput.h"


TestFindWindow::TestFindWindow()
{
    test1();
}


void TestFindWindow::test1()
{

    if ( 0 )
    {
        std::wstring class_name = L"MediaPlayerClassicW"; // MPC-HC64 主窗口
        std::wstring window_name = L"Cell 2016 720p WEB-DL x264 AC3-JYK.mkv";
        HWND hwnd = FindWindow( class_name.c_str(), window_name.c_str() );

        if ( hwnd == NULL )
        {
            std::cout << "can not find window " << std::endl;
        }
    }

    if ( 0 )
    {
        std::wstring class_name = L"#32770";
        std::wstring window_name = L"转到...";
        HWND hwnd = FindWindow( class_name.c_str(), window_name.c_str() );

        if ( hwnd == NULL )
        {
            std::cout << "can not find window " << std::endl;
            return;
        }

        ShowWindow( hwnd, SW_HIDE );

    }

    if ( 1 )
    {
        std::wstring class_name = L"#32770";
        std::wstring window_name = L"";
        HWND hwnd = FindWindow( class_name.c_str(), window_name.c_str() );

        if ( hwnd == NULL )
        {
            std::cout << "can not find window " << std::endl;
            return;
        }

        ShowWindow( hwnd, SW_HIDE );

    }
    //SetForegroundWindow( hwnd );
    //TestSendInput si;
    //si.send_input_ctrl( 'G' );
    //si.send_input( "002353");
    //si.send_input_enter();
}
