#include "EventDispatcher.h"
#include "EventListener.h"

#include <algorithm>

EventDispatcher::EventDispatcher()
{
}

EventDispatcher::~EventDispatcher()
{
}

// public:

void EventDispatcher::dispatchEvent(Event& event)
{
    for (auto& listener : m_listeners) {
        if (listener->m_channels & event.channel)
            listener->catchEvent(event);
    }
}

// private:

void EventDispatcher::registerListener(EventListener* e)
{
    auto it = std::find(m_listeners.begin(), m_listeners.end(), e);
    if (it == m_listeners.end())
        m_listeners.push_back(e);
}

void EventDispatcher::unregisterListener(EventListener* e) noexcept
{
    auto it = std::find(m_listeners.begin(), m_listeners.end(), e);
    if (it != m_listeners.end())
        m_listeners.erase(it);
}