#pragma once


class TestMultiByteToWideChar
{
public:

    TestMultiByteToWideChar();

public:

    void test1();
    std::wstring wstring_from_file( const wchar_t* file_name, int code_page = CP_ACP );
    void wstring_from_file_test();

};
