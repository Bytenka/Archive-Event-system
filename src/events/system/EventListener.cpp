#include "EventListener.h"
#include "EventDispatcher.h"

#include <algorithm>
#include <iostream>

EventListener::EventListener(void* parent)
    : m_parent(parent)
{
}

EventListener::~EventListener()
{
    EventDispatcher::getInstance().unregisterListener(this);
}

// public:

void EventListener::subscribe(EventChannel channel, CallbackFunction callback)
{
    EventDispatcher::getInstance().registerListener(this);
    m_channels = (EventChannel)(m_channels | channel);
    m_pair.push_back({channel, callback});
}

void EventListener::unsubscribe(EventChannel channel)
{
    auto it = std::find_if(m_pair.begin(), m_pair.end(), [&](const ChannelAndCallback& e) {
        return e.first == channel;
    });
    if (it != m_pair.end())
        m_pair.erase(it);

    m_channels = (EventChannel)(m_channels ^ channel);

    if (m_channels == None)
        EventDispatcher::getInstance().unregisterListener(this);
}

// private:

void EventListener::catchEvent(Event& event)
{
    for (auto& p : m_pair) {
        if (event.channel & p.first) {
            p.second(m_parent, event);
            event.handeled = true;
        }
    }
}