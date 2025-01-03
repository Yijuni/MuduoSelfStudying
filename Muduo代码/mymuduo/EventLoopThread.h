#pragma once

#include "nocopyable.h"
#include <functional>
#include "Thread.h"
#include <mutex>
#include <string>
#include <condition_variable>
class EventLoop;

class EventLoopThread:nocopyable{
public:
    using ThreadInitCallback = std::function<void(EventLoop*)>;
    EventLoopThread(const ThreadInitCallback cb = ThreadInitCallback(),const std::string name = std::string());
    ~EventLoopThread();

    EventLoop* startLoop();
private:
    void threadFunc();
    EventLoop* loop_;
    bool exiting_;
    Thread thread_;
    std::mutex mutex_;
    std::condition_variable cond_;  
    ThreadInitCallback threadInitcallback_;

};