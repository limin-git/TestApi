#include "stdafx.h"
#include "TestSystemParametersInfo.h"


TestSystemParametersInfo::TestSystemParametersInfo()
{
    test1();
}


void TestSystemParametersInfo::test1()
{
    char* pathp = "c:\\temp\\img7.jpg"; 
    SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, pathp, SPIF_UPDATEINIFILE);
}
