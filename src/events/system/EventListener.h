#pragma once

#include "Event.h"

#include <functional>
#include <utility>
#include <vector>

class EventDispatcher;
class EventListener
{
  public:
    EventListener(void* parent = nullptr);
    ~EventListener();

    using CallbackFunction = std::function<void(void*, Event&)>;
    using ChannelAndCallback = std::pair<EventChannel, CallbackFunction>;

    void subscribe(EventChannel channel, CallbackFunction callback);
    void unsubscribe(EventChannel channel);

  private:
    friend class EventDispatcher;
    void catchEvent(Event& event);

  private:
    void* m_parent;
    std::vector<ChannelAndCallback> m_pair;
    EventChannel m_channels = None;

  public:
    EventListener(const EventListener&) = delete;
    void operator=(const EventListener&) = delete;
};