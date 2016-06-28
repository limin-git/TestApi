#include "stdafx.h"
#include "TestMultiByteToWideChar.h"


TestMultiByteToWideChar::TestMultiByteToWideChar()
{
    //test1();
    wstring_from_file_test();
}


void TestMultiByteToWideChar::test1()
{
    
}


std::wstring TestMultiByteToWideChar::wstring_from_file( const wchar_t* file_name, int code_page )
{
    std::wstring ws;
    std::ifstream is( file_name, std::ios::in | std::ios::binary );

    if ( !is )
    {
        return std::wstring();
    }

    unsigned char ch[3] = { 0 };
    std::wstring encoding = L"ANSI";

    is.unsetf( std::ios::skipws );
    is.read( (char*)ch, 3 );

    if ( ch[0] == 0xFF && ch[1] == 0xFE ) // unicode: FF FE
    {
        is.seekg( -2, std::ios::end );
        size_t size = is.tellg();
        ws.resize( size / 2 );
        is.seekg( 2, std::ios::beg );
        is.read( (char*)&ws[0], size );
    }
    else if ( ch[0] == 0xEF && ch[1] == 0xBB && ch[2] == 0xBF ) // utf-8 + BOM: EF BB BF
    {
        is.seekg( -3, std::ios::end );
        size_t size = is.tellg();
        char* buf = new char[ size ];
        is.seekg( 3, std::ios::beg );
        is.read( buf, size );
        size_t wsize = MultiByteToWideChar( CP_UTF8, 0, buf, size, 0, 0 );
        ws.resize( wsize );
        MultiByteToWideChar( CP_UTF8, 0, buf, size, &ws[0], wsize );
    }
    else // ANSI
    {
        is.seekg( 0, std::ios::end );
        size_t size = is.tellg();
        char* buf = new char[ size ];
        is.seekg( 0, std::ios::beg );
        is.read( buf, size );
        size_t wsize = MultiByteToWideChar( code_page, 0, buf, size, 0, 0 );
        ws.resize( wsize );
        MultiByteToWideChar( code_page, 0, buf, size, &ws[0], wsize );
    }

    return ws;
}


void TestMultiByteToWideChar::wstring_from_file_test()
{
    {
        std::wstring ws = wstring_from_file( L"unicode.txt" );
        WriteConsoleW( GetStdHandle(STD_OUTPUT_HANDLE), ws.c_str(), ws.size(), 0, 0 );
        std::wcout << std::endl;
    }

    {
        std::wstring ws = wstring_from_file( L"utf-8.txt" );
        WriteConsoleW( GetStdHandle(STD_OUTPUT_HANDLE), ws.c_str(), ws.size(), 0, 0 );
        std::wcout << std::endl;
    }

    {
        std::wstring ws = wstring_from_file( L"ansi.txt" );
        WriteConsoleW( GetStdHandle(STD_OUTPUT_HANDLE), ws.c_str(), ws.size(), 0, 0 );
        std::wcout << std::endl;
    }
}
