#pragma once

#include "events/Events.h"

#include <iostream>

class TestObject : public IKeyListener
{
  public:
    TestObject()
        : m_listener(this)
    {
        m_listener.subscribe(EventChannel::Keyboard, key_event_callback);
    }
    ~TestObject() {}

  private:
    void onKeyPressed(int keyCode) override
    {
        std::cout << "Registered key press, keycode = " << keyCode << std::endl;
    }

    void onKeyReleased(int keyCode) override {}
    void onKeyTyped(int keyCode) override {}

    static void key_event_callback(void* object, Event& event)
    {
        TestObject* parentObject = (TestObject*)object;
        switch (event.type) {
        case KeyPressed:
            parentObject->onKeyPressed(((KeyPressedEvent*)&event)->getKeyCode());
            break;

        case KeyReleased:
            parentObject->onKeyReleased(((KeyReleasedEvent*)&event)->getKeyCode());
            break;

        case KeyTyped:
            parentObject->onKeyTyped(((KeyTypedEvent*)&event)->getKeyCode());
            break;

        default:
            break;
        }
    }

  private:
    EventListener m_listener;
};