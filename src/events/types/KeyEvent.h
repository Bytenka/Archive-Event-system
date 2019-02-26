#pragma once

#include "../system/Event.h"

class KeyEvent : public Event
{
  public:
    inline int getKeyCode() const noexcept { return m_keyCode; }
    EVENT_TO_STRING_METHOD(KeyEvent);

  protected:
    KeyEvent(EventType type, int keyCode)
        : Event(type, EventChannel::Keyboard), m_keyCode(keyCode) {}

  protected:
    int m_keyCode;
};


class KeyPressedEvent : public KeyEvent
{
  public:
    KeyPressedEvent(int keyCode)
        : KeyEvent(EventType::KeyPressed, keyCode) {}

    EVENT_TO_STRING_METHOD(KeyPressedEvent);
};


class KeyReleasedEvent : public KeyEvent
{
  public:
    KeyReleasedEvent(int keyCode)
        : KeyEvent(EventType::KeyReleased, keyCode) {}

    EVENT_TO_STRING_METHOD(KeyReleasedEvent);
};


class KeyTypedEvent : public KeyEvent
{
  public:
    KeyTypedEvent(int keyCode)
        : KeyEvent(EventType::KeyTyped, keyCode) {}

    EVENT_TO_STRING_METHOD(KeyTypedEvent);
};