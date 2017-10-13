#pragma once


class TestSuspendThread
{
public:

    TestSuspendThread();

public:

    void test1();

public:

    std::set<unsigned long> get_thread_ids();
    std::set<HANDLE> get_thread_handles(const std::set<unsigned long>& ids);
    void suspend_threads(const std::set<HANDLE>& handles);
    void resume_threads(const std::set<HANDLE>& handles);
    void suspend_thread(unsigned long thread_id);
    void resume_thrad(unsigned long thread_id);
    void suspend_other_threads();
    void resume_other_threads();
};
