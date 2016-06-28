#include "stdafx.h"
#include "TestFindCloseChangeNotification.h"


HANDLE TestFindCloseChangeNotification::s_handle = NULL;



TestFindCloseChangeNotification::TestFindCloseChangeNotification()
{
    test1();
}


void TestFindCloseChangeNotification::test1()
{
    boost::thread t( thread_function );

    Sleep(100);

    std::cout << "before" << std::endl;
    FindCloseChangeNotification( s_handle );
    Sleep(100);
    std::cout << "after" << std::endl;
    
    Sleep(100);
}


void TestFindCloseChangeNotification::thread_function()
{
    std::wstring directory = L"C:\\Temp";
    s_handle = ::FindFirstChangeNotification( directory.c_str(), FALSE, FILE_NOTIFY_CHANGE_LAST_WRITE );

    if ( s_handle == INVALID_HANDLE_VALUE )
    {
        std::cout << "FindFirstChangeNotification error: " << ::GetLastError() << std::endl;
        return;
    }

    while ( true )
    {
        DWORD status = ::WaitForSingleObject( s_handle, INFINITE );

        if ( WAIT_OBJECT_0 == status )
        {
            std::cout << "some file changed." << std::endl;

            if ( ::FindNextChangeNotification( s_handle ) == FALSE )
            {
                std::cout << "FindFirstChangeNotification error: " << ::GetLastError() << std::endl;
                return;
            }
        }
        else
        {
            std::cout << "FindFirstChangeNotification error: " << ::GetLastError() << std::endl;
            return;
        }
    }
}
