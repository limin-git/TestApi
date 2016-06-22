#include "stdafx.h"
#include "TestShellExecute.h"


TestShellExecute::TestShellExecute()
{
    test1();
}


void TestShellExecute::test1()
{
    ShellExecuteA(
        NULL,
        "open",
        "C:\\Temp\\img1.jpg",
        0,
        0,
        SW_SHOWNOACTIVATE );

    //ShellExecuteA(
    //    NULL,
    //    "open",
    //    "C:\\Temp\\img2.jpg",
    //    0,
    //    0,
    //    SW_SHOWDEFAULT );
}
