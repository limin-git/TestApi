#pragma once


class TestFindWindow
{
public:

    TestFindWindow();

public:

    void test1();

    void send_input( const std::string& str );
    void send_input_ctrl( const char ch );
    void send_input_enter();
};
