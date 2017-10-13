#include "stdafx.h"
#include "TestSuspendThread.h"
#include "tlhelp32.h"

TestSuspendThread::TestSuspendThread()
{
    test1();
}

void TestSuspendThread::test1()
{
    struct TestThread
    {
        void operator()()
        {
            while (true)
            {
                size_t x;
                std::stringstream strm;
                strm << std::hex << boost::this_thread::get_id();
                strm >> x;
                std::cout << "[" << x << "] hello, world" << std::endl;
                boost::this_thread::sleep_for(boost::chrono::milliseconds(500));
            }
        }
    };

    struct ControlThread
    {
        void operator()()
        {
            std::string cmd;
            TestSuspendThread* dumy = NULL;

            while (std::getline(std::cin, cmd))
            {
                if (cmd == "s")
                {
                    dumy->suspend_other_threads();
                }
                else if (cmd == "r")
                {
                    dumy->resume_other_threads();
                }
                else if (cmd == "exit")
                {
                    dumy->resume_other_threads();
                    break;
                }
            }
        }
    };

    TestThread x1, x2;
    boost::thread t1(x1);
    boost::thread t2(x2);
    boost::thread(ControlThread()).join();
}

std::set<unsigned long> TestSuspendThread::get_thread_ids()
{
    std::set<unsigned long> ids;
    DWORD dwOwnerPID = ::GetCurrentProcessId();
    HANDLE        hThreadSnap = NULL;
    THREADENTRY32 te32        = {0};

    hThreadSnap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);

    if (hThreadSnap == INVALID_HANDLE_VALUE)
    {
        return ids;
    }

    te32.dwSize = sizeof(THREADENTRY32);

    if (Thread32First(hThreadSnap, &te32))
    {
        do
        {
            if (te32.th32OwnerProcessID == dwOwnerPID)
            {
                ids.insert(te32.th32ThreadID);
            }
        }
        while (Thread32Next(hThreadSnap, &te32));
    }

    CloseHandle(hThreadSnap);

    return ids;
}

std::set<HANDLE> TestSuspendThread::get_thread_handles(const std::set<unsigned long>& ids)
{
    std::set<HANDLE> handles;

    BOOST_FOREACH(unsigned long id, ids)
    {
        HANDLE handle = ::OpenThread(THREAD_ALL_ACCESS, true, id);

        if (handle != 0)
        {
            handles.insert(handle);
        }
    }

    return handles;
}

void TestSuspendThread::suspend_threads(const std::set<HANDLE>& handles)
{
    BOOST_FOREACH(HANDLE h, handles)
    {
        ::SuspendThread(h);
    }
}

void TestSuspendThread::resume_threads(const std::set<HANDLE>& handles)
{
    BOOST_FOREACH(HANDLE h, handles)
    {
        ::ResumeThread(h);
    }
}

void TestSuspendThread::suspend_thread(unsigned long thread_id)
{
    HANDLE handle = ::OpenThread(THREAD_ALL_ACCESS, true, thread_id);

    if (handle != 0)
    {
        ::SuspendThread(handle);
    }
}

void TestSuspendThread::resume_thrad(unsigned long thread_id)
{
    HANDLE handle = ::OpenThread(THREAD_ALL_ACCESS, true, thread_id);

    if (handle != 0)
    {
        ::ResumeThread(handle);
    }
}

void TestSuspendThread::suspend_other_threads()
{
    std::set<unsigned long> tids = get_thread_ids();
    tids.erase(::GetCurrentThreadId());
    std::set<HANDLE> handles = get_thread_handles(tids);
    suspend_threads(handles);
}

void TestSuspendThread::resume_other_threads()
{
    std::set<unsigned long> tids = get_thread_ids();
    tids.erase(::GetCurrentThreadId());
    std::set<HANDLE> handles = get_thread_handles(tids);
    resume_threads(handles);
}
