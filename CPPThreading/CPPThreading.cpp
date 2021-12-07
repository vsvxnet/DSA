// CPPThreading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <mutex>
#include <iomanip>
#include <future>
#include <exception>
#include <queue>
#include <cmath>
using namespace std;
class MyCallable
{
private:
    int count;
    mutex mtx;
public:
    void operator()()
    {
        for (int i = 0; i < 1000; i++)
        {
            const lock_guard<mutex> guard(mtx);
            ++count;
        }
    }

    int GetCount()
    {
        return count;
    }

};

template<typename E> class blocking_queue
{
private:
    mutex mtx;
    condition_variable mycondition;
    int max_size;
    queue<E> q;
public:
    blocking_queue(int max_size) :max_size( max_size )
    {
        
    }
    void push(E e)
    {
        unique_lock<mutex> mylock(mtx);
        mycondition.wait(mylock, [&]() {return q.size() < max_size; });
        q.push(e);
        mylock.unlock();
        mycondition.notify_one();
    }
    void pop()
    {
        unique_lock<mutex> mylock(mtx);
        mycondition.wait(mylock, [this]() {return !q.empty(); });
        q.pop();
        mylock.unlock();
        mycondition.notify_one();
    }
    E popget()
    {
        unique_lock<mutex> lock(mtx);
        mycondition.wait(lock, [this]() {return !q.empty(); });
        E item = q.front();
        q.pop();
        lock.unlock();
        //cout << "pop " << endl;
       mycondition.notify_one();
        return item;
    }

    E front()
    {
        unique_lock<mutex> mylock(mtx);
        mycondition.wait(mylock, [this]() {return !q.empty(); });
        return q.front();
    }

    int size()
    {
        lock_guard<mutex> mylock(mtx);
        return q.size();
    }
};


void DoSimpleWork()
{
    for (int i = 0; i < 1000; i++)
    {
      //  this_thread::sleep_for(chrono::milliseconds(500));
        cout << "Loop: " << i << endl;
    }
}
int DoSimpleWorkWithID(int id)
{
    for (int i = 0; i < 5; i++)
    {
        cout << "running " << id << endl;
        this_thread::sleep_for(chrono::microseconds(1000));
    }
    return id * 7;
}
mutex g_mtx;
int DoSimpleWorkWithGlobalMutexAndUniqueLock(int id)
{
    unique_lock<mutex> mylock(g_mtx);
    cout << "Starting : " << id << endl;
    mylock.unlock();

    int seconds = int((5.0 * rand()) / RAND_MAX + 3);
    this_thread::sleep_for(chrono::seconds(seconds));
    return id;
}

void DoMutexWork(int& count, mutex& mtx)
{
    for (int i = 0; i < 25; i++)
    {
        mtx.lock();
        ++count;
        mtx.unlock();
    }
}

void DoSharedLockguardWork(int& count, mutex& mtx)
{
    for (int i = 0; i < 1000; i++)
    {
        lock_guard<mutex> guard(mtx);
        ++count;
    }
}

void DoSharedUniqueLockWork(int& count, mutex& mtx)
{
    for (int i = 0; i < 1000; i++)
    {
        unique_lock<mutex> guard(mtx);
        ++count;
    }
}


void RunBasicThread()
{
    // Basic Thread
    thread t1(DoSimpleWork);
    thread t2(DoSimpleWork);
    t1.join();
    t2.join();
}
void RunSharedNoMutexThread()
{
    atomic<int> count = 0;
    int ITERATIONS = 1000;
    thread t1([&]() {
        for (int i = 0; i < ITERATIONS; i++)
        {
            ++count;
        }
     });

    thread t2([&]() {
        for (int i = 0; i < ITERATIONS; i++)
        {
            ++count;
        }
     });
    t1.join();
    t2.join();
    cout << count << endl;
}
void RunSharedMutexThread()
{
    mutex mtx;
    int count = 0;
    const int ITERATIONS = 1000;

    auto func = [&]() {
        for (int i = 0; i < ITERATIONS; i++)
        {
            mtx.lock();
            ++count;
            mtx.unlock();
        }
    };

    thread t1(func);
    thread t2(func);
    t1.join();
    t2.join();
    cout << count << endl;
}
void RunSharedMutexThread1()
{
    mutex mtx;
    int count = 0;
    const int ITERATIONS = 1000;

    thread t1(DoMutexWork, ref(count), ref(mtx));
    thread t2(DoMutexWork, ref(count), ref(mtx));

    t1.join();
    t2.join();
    cout << count << endl;
}

void RunSharedLockguardThread()
{
    mutex mtx;
    int count = 0;
    const int ITERATIONS = 1000;
    thread t1(DoSharedLockguardWork, ref(count), ref(mtx));
    thread t2(DoSharedLockguardWork, ref(count), ref(mtx));
    
    t1.join();
    t2.join();
    cout << count << endl;

}

void RunSharedUniqueLockThread()
{
    mutex mtx;
    int count = 0;
    const int ITERATIONS = 1000;
    thread t1(DoSharedUniqueLockWork, ref(count), ref(mtx));
    thread t2(DoSharedUniqueLockWork, ref(count), ref(mtx));
    t1.join();
    t2.join();
    cout << count << endl;
}

void RunCallableObject()
{
    MyCallable myCallable;
    thread t1(ref(myCallable));
    thread t2(ref(myCallable));

    t1.join();
    t2.join();

    cout << myCallable.GetCount() << endl;
}

double CalculatePI(int terms)
{
    double sum = 0.0;
    for (int i = 0; i < terms; i++)
    {
        int sign = pow(-1, i);
        double term = 1.0 / (i * 2 + 1);
        sum += sign * term;
    }
    return sum * 4;
}
double CalculatePIWithException(int terms)
{
    double sum = 0.0;
    if (terms < 1)
    {
        throw runtime_error("Terms cannot be less than 1.");
    }
    for (int i = 0; i < terms; i++)
    {
        int sign = pow(-1, i);
        double term = 1.0 / (i * 2 + 1);
        sum += sign * term;
    }
    return sum * 4;
}
double CalculatePIWithCores(int terms, int start, int skip)
{
    double sum = 0.0;
    for (int i = start; i < terms; i+=skip)
    {
        int sign = pow(-1, i);
        double term = 1.0 / (i * 2 + 1);
        sum += sign * term;
    }
    return sum * 4;
}
void RunBasicComputePI()
{
    cout << setprecision(10) << CalculatePI(5000) << endl;
}
void RunBasicPromiseWithFuture()
{
    promise<double> promise;

    auto do_calcuation = [&](int terms)
    {
        auto result = CalculatePI(terms);
        promise.set_value(result);
    };

    thread t1(do_calcuation, 1000);
    future<double> future = promise.get_future();
    cout << setprecision(10) << future.get() << endl;
    t1.join();
}
void RunPromiseFutureWithException()
{
    promise<double> promise;
    auto do_calculation= [&](int terms)
    {
        try
        {
            auto result = CalculatePIWithException(terms);
            promise.set_value(result);
        }
        catch (...)
        {
            promise.set_exception(current_exception());
        }
    };
    thread t1(do_calculation, 0);
    future<double> future = promise.get_future();

    try
    {
        cout << setprecision(15) << future.get() << endl;
    }
    catch (const std::exception& e)
    {
        cout << "Error: " << e.what() << endl;
    }
    t1.join();
}

void RunPackagedTask()
{
    packaged_task<double(int)> task1(CalculatePIWithException);
    future<double> future1 = task1.get_future();
    thread t1(ref(task1), 0);
    try
    {
        double result = future1.get();
        cout << setprecision(10) << result << endl;
    }
    catch (exception& e)
    {
        cout << "Error: " << e.what() << endl;
    }
    t1.join();
}

void RunWaitForThread()
{
    atomic<bool> ready = false;
    thread t1([&]() {
        this_thread::sleep_for(chrono::milliseconds(2000));
        ready = true;
        });

    t1.join();
    while (!ready)
    {
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    cout << "ready " << ready << endl;
}

void RunWithConditionVariableThread()
{
    condition_variable condition1;
    mutex mtx;
    bool ready = false;

    thread t1([&]() {
        this_thread::sleep_for(chrono::milliseconds(2000));
        unique_lock<mutex> lock(mtx);
        ready = true;
        lock.unlock();
        condition1.notify_one();
        });

    unique_lock<mutex> lock(mtx);
    while (!ready)
    {
        condition1.wait(lock);
    }
    cout << "ready " << ready << endl;
    t1.join();
}

void RunSharedWithConditionVariableThread()
{
    condition_variable condition1;
    mutex mtx;
    bool ready = false;

    thread t1([&]() 
        {
            this_thread::sleep_for(chrono::milliseconds(2000));
            cout << "T1 is acquiring lock " << endl;
            unique_lock<mutex> lock(mtx);
            cout << "T1 acquired lock" << endl;
            ready = true;
            lock.unlock();
            cout << "T1 released lock; notifying" << endl;
            condition1.notify_one();
        });

    cout << "MainT is acquiring lock" << endl;
    unique_lock<mutex> lock(mtx);
    cout << "MainT acquired lock; waiting" << endl;
    condition1.wait(lock, [&]() {return ready; });
    cout << "MainT finished waiting" << endl;
    cout << "ready " << ready << endl;
    t1.join();
}

void RunBasicBlockingQueue()
{
    blocking_queue<int> bq(5);
    thread t1([&]() 
        {//Producer
            for (int i = 0; i < 1000; i++)
            {
                bq.push(i);
                cout << "BQ Size = " << bq.size() << endl;
            }
        });
    thread t2([&]() 
        {//Consumer
            for (int i = 0; i < 1000; i++)
            {
                auto item = bq.front();
                bq.pop();
                cout << "consumed: " << item << endl;
            }
        });
    t1.join();
    t2.join();
}

void RunAsyncFuture()
{
    future<int> f1 = async(launch::async, DoSimpleWorkWithID, 0);
    future<int> f2 = async(launch::async, DoSimpleWorkWithID, 0);
    cout << f1.get() << endl;
    cout << f2.get() << endl;
}

void TestHardwareConcurrency()
{
    cout <<"Max SystemThread(s) : " << thread::hardware_concurrency() << endl;
}

void RunAlotOfThreads()
{
    vector<shared_future<int>> futures;
    for (int i = 0; i < thread::hardware_concurrency(); i++)
    {
        shared_future<int> fut = async(launch::async, DoSimpleWorkWithGlobalMutexAndUniqueLock, i);
        futures.push_back(fut);
    }
    for (auto f : futures)
    {
        cout << "Returned : " << f.get() << endl;
    }
}

void RunThreadPool()
{
    blocking_queue<shared_future<int>> futures(4);
    thread t1([&]() {
        for (int i = 0; i < 1000; i++)
        {
            shared_future<int> f = async(launch::async, DoSimpleWorkWithGlobalMutexAndUniqueLock, i);
            futures.push(f);
        }
        });
        
    for (int i = 0; i < 1000; i++)
    {
        shared_future<int> f = futures.front();
        int value = f.get();
        futures.pop();
        cout << "Returned : " << value << endl;
    }
    t1.join();
}

void RunDistributedWorkBetweenCores()
{
    vector<shared_future<double>> futures;
    const int CONCURRENT = thread::hardware_concurrency();

    for (int i = 0; i < CONCURRENT; i++)
    {
        shared_future<double> f = async(launch::async, CalculatePIWithCores, 1000, i, CONCURRENT);
        futures.push_back(f);
    }
    double sum = 0.0;;
    for (auto f : futures)
    {
        sum += f.get();
    }
    cout << setprecision(10) << "Sum/PI: " << sum << endl;
}

void RunDistributedWorkBetweenCoresWithDuration()
{
    vector<shared_future<double>> futures;
    const int CONCURRENT = thread::hardware_concurrency();
    auto start = chrono::steady_clock::now();

    for (int i = 0; i < CONCURRENT; i++)
    {
        shared_future<double> f = async(launch::async, CalculatePIWithCores,1000, i, CONCURRENT);
        futures.push_back(f);
    }
    double sum = 0.0;

    for (auto f : futures)
    {
        sum += f.get();
    }

    auto end = chrono::steady_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "Duration: " << duration << endl;
    cout << setprecision(15) << "Sum/PI: " << sum << endl;
}
int main()
{
    //std::cout << "Hello World!\n";
    // RunBasicThread();
    // RunSharedNoMutexThread();
    // RunSharedMutexThread();
    // RunSharedMutexThread1();
    // RunSharedLockguardThread();
    // RunSharedUniqueLockThread();
    // RunCallableObject();
    // RunBasicComputePI();
    // RunBasicPromiseWithFuture();
    // RunPromiseFutureWithException();
    // RunPackagedTask();
    // RunWaitForThread();
    // RunWithConditionVariableThread();
    // RunSharedWithConditionVariableThread();
    // RunBasicBlockingQueue();
    // RunAsyncFuture();
    // TestHardwareConcurrency();
    // RunAlotOfThreads();
    // RunThreadPool();
    // RunDistributedWorkBetweenCores();
     RunDistributedWorkBetweenCoresWiithDuration();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
