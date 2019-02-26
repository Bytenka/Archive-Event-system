#pragma once

#include <string>

#define BIT(x) (1 << x)
#define EVENT_TO_STRING_METHOD(x) \
    virtual inline std::string toString() const noexcept { return #x; }

enum EventType {
    Undefined = 0,
    KeyPressed,
    KeyReleased,
    KeyTyped,
    MouseButtonPressed,
    MouseButtonReleased,
    MouseButtonClicked,
    MouseMoved,
    MouseScrolled
};

enum EventChannel {
    None = 0,
    Keyboard = BIT(0),
    Mouse = BIT(1)
};

class Event
{
  public:
    EventType type;
    EventChannel channel;
    bool handeled = false;

    EVENT_TO_STRING_METHOD(Event);

  protected:
    Event(EventType type, EventChannel channel)
        : type(type), channel(channel) {}

  public:
    Event(const Event&) = delete;
    void operator=(const Event&) = delete;
};

#undef BIT