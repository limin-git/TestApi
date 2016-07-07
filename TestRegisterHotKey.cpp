#include "stdafx.h"
#include "TestRegisterHotKey.h"
#include "TestSendInput.h"


TestRegisterHotKey::TestRegisterHotKey()
{
    boost::thread t( boost::bind( &TestRegisterHotKey::test1, this ) );
    while ( 'q' !=  _getch() )
    {
        //PostMessage( 0, WM_USER + 1, 0, 0 );
        TestSendInput s;
        s.send_input( "Z" );
    }
}


void TestRegisterHotKey::test1()
{
    MSG msg = { 0 };

    HWND hwnd = GetConsoleWindow();

    //MOD_CONTROL, MOD_ALT, MOD_SHIFT
    RegisterHotKey( NULL, 1, 0, 'A' );
    RegisterHotKey( NULL, 2, 0, 'B' );
    RegisterHotKey( NULL, 3, 0, 'Z' );

    while ( GetMessage( &msg, NULL, 0, 0 ) != 0 )
    {
        if ( msg.message == WM_HOTKEY )
        {
            switch( msg.wParam )
            {
            case 1:
                std::cout << "HotKey: A" << std::endl;
                break;

            case 2:
                std::cout << "HotKey: B" << std::endl;
                break;

            default:
                std::cout << "hello, world!" << std::endl;
            }
        }
    }
}
