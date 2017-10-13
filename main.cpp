// TestApi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TestShellExecute.h"
#include "TestSystemParametersInfo.h"
#include "TestMultiByteToWideChar.h"
#include "TestFindWindow.h"
#include "TestFindCloseChangeNotification.h"
#include "TestRegisterHotKey.h"
#include "TestSuspendThread.h"


int _tmain(int argc, _TCHAR* argv[])
{
    std::ios_base::sync_with_stdio( false );

    if ( 0 )
    {
        TestShellExecute test;
    }

    if ( 0 )
    {
        TestSystemParametersInfo test;
    }

    if ( 0 )
    {
        TestMultiByteToWideChar test;
    }

    if ( 0 )
    {
        TestFindWindow test;
    }

    if ( 0 )
    {
        TestFindCloseChangeNotification test;
    }

    if ( 0 )
    {
        TestRegisterHotKey test;
    }

    if ( 1 )
    {
        TestSuspendThread test;
    }

	return 0;
}
