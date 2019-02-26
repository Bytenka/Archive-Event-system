#pragma once

#include "Event.h"

#include <list>

#define DISPATCH_EVENT(event) EventDispatcher::getInstance().dispatchEvent(event)

class EventListener;
class EventDispatcher
{
  public:
    inline static EventDispatcher& getInstance()
    {
        static EventDispatcher instance;
        return instance;
    }
    
    void dispatchEvent(Event& event);

  private:
    friend class EventListener;
    void registerListener(EventListener* e);
    void unregisterListener(EventListener* e) noexcept;

  private:
    EventDispatcher();
    ~EventDispatcher();

  private:
    std::list<EventListener*> m_listeners;

  public:
    EventDispatcher(const EventDispatcher&) = delete;
    void operator=(const EventDispatcher&) = delete;
};