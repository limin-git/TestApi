#include "stdafx.h"
#include "TestSystemParametersInfo.h"


TestSystemParametersInfo::TestSystemParametersInfo()
{
    test1();
    //test2();
}


void TestSystemParametersInfo::test1()
{
    char* wall_paper_path = "c:\\temp\\img7.jpg"; 
    SystemParametersInfoA( SPI_SETDESKWALLPAPER, 0, wall_paper_path, 0 ); //SPIF_UPDATEINIFILE
}


void TestSystemParametersInfo::test2()
{
    //C:\Users\Limin\AppData\Roaming\Microsoft\Windows\Themes\CachedFiles

    char wall_paper_path[MAX_PATH] = { 0 };

    if ( 0 == SystemParametersInfoA( SPI_GETDESKWALLPAPER, MAX_PATH, wall_paper_path, 0 ) )
    {
        std::cout << "SystemParametersInfo failed: " << GetLastError() << std::endl;
    }
    else
    {
        std::cout << wall_paper_path << std::endl;    
    }
}
