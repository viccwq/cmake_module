#include <iostream>
#include <mutex>
#include <thread>

#include "vxlLog.h"

#define MULTI_THREAD  1
#define LOOP          1

using namespace std;

int FunTest(int threadIdx)
{

#if 0
    string ss, ss1, ss2, ss3;
    VCA_EXECUTION_STATUS status = GetCurPath(ss);
    printf("ss=%s\n",ss.c_str());
    getchar();

    status = GetConfigFilePath("../../a.txt", ss);
    printf("ss=%s\n",ss.c_str());
    getchar();

    status = SplitFilePath(ss, ss1, ss2, ss3);
#endif

#ifdef _WIN32
    SetLogFileDirectory("C:/DebugLog/Director");
#else if defined __linux__
    SetLogFileDirectory("./DebugLog/Director");
#endif
    SetLogFileName("testLog");
    SetLogLevel(VXL_LOG_TRACE);
    EnableLogFile(true);

#if LOOP
    for (int loop = 0; ; ++loop)
    {
        printf("thread idx=%d loop = %d\n", threadIdx, loop);
#endif

        LogTrace("thread idx=%d loop = %d\n", threadIdx, loop);
        LogTrace("LogTrace%d\n", threadIdx);
        LogInfo("LogInfo%d\n", threadIdx);
        LogWarning("LogWarning%d\n", threadIdx);
        LogError("LogError%d\n", threadIdx);
        LogFatal("LogFatal%d\n", threadIdx);

#if LOOP
    }
#endif

    return 0;
}

void ThreadFunc0()
{
    unsigned int status = 1;
    status = FunTest(0);
}

void ThreadFunc1()
{
    unsigned int status = 1;
    status = FunTest(1);
}

int main()
{
    int status = 0;

#if !MULTI_THREAD
    const int THREAD_NUM = 1;
    thread threads[THREAD_NUM];

    threads[0] = thread(ThreadFunc0);
#else
    const int THREAD_NUM = 2;
    thread threads[THREAD_NUM];

    threads[0] = thread(ThreadFunc0);
    threads[1] = thread(ThreadFunc1);
#endif

    for (auto & th : threads)
    {
        th.join();
    }

    return status;
}