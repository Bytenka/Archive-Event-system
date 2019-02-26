#pragma once

#include "../system/Event.h"

class MouseEvent : public Event
{
  public:
    EVENT_TO_STRING_METHOD(MouseEvent);

  protected:
    MouseEvent(EventType type)
        : Event(type, EventChannel::Mouse) {}
};


class MouseMovedEvent : public MouseEvent
{
  public:
    MouseMovedEvent(float mouseX, float mouseY)
        : MouseEvent(EventType::MouseMoved),
          m_mouseX(mouseX),
          m_mouseY(mouseY) {}

    inline float getX() const noexcept { return m_mouseX; }
    inline float getY() const noexcept { return m_mouseY; }

    EVENT_TO_STRING_METHOD(MouseMovedEvent);

  protected:
    float m_mouseX, m_mouseY;
};


class MouseScrolledEvent : public MouseEvent
{
  public:
    MouseScrolledEvent(float offsetX, float offsetY)
        : MouseEvent(EventType::MouseScrolled), m_offsetX(offsetX), m_offsetY(offsetY) {}

    inline float getOffsetX() const noexcept { return m_offsetX; }
    inline float getOffsetY() const noexcept { return m_offsetY; }

    EVENT_TO_STRING_METHOD(MouseScrolledEvent);

  protected:
    float m_offsetX, m_offsetY;
};


class MouseButtonEvent : public MouseEvent
{
  public:
    inline int getButton() const noexcept { return m_button; }
    inline float getX() const noexcept { return m_mouseX; }
    inline float getY() const noexcept { return m_mouseY; }
    
    EVENT_TO_STRING_METHOD(MouseButtonEvent);

  protected:
    MouseButtonEvent(EventType type, int button, float mouseX, float mouseY)
        : MouseEvent(type), m_button(button), m_mouseX(mouseX), m_mouseY(mouseY) {}

  protected:
    int m_button;
    float m_mouseX, m_mouseY;
};


class MouseButtonPressedEvent : public MouseButtonEvent
{
  public:
    MouseButtonPressedEvent(int button, float mouseX, float mouseY)
        : MouseButtonEvent(EventType::MouseButtonPressed, button, mouseX, mouseY) {}

    EVENT_TO_STRING_METHOD(MouseButtonPressedEvent);
};


class MouseButtonReleasedEvent : public MouseButtonEvent
{
  public:
    MouseButtonReleasedEvent(int button, float mouseX, float mouseY)
        : MouseButtonEvent(EventType::MouseButtonReleased, button, mouseX, mouseY) {}

    EVENT_TO_STRING_METHOD(MouseButtonReleasedEvent);
};


class MouseButtonClickedEvent : public MouseButtonEvent
{
  public:
    MouseButtonClickedEvent(int button, float mouseX, float mouseY)
        : MouseButtonEvent(EventType::MouseButtonClicked, button, mouseX, mouseY) {}

    EVENT_TO_STRING_METHOD(MouseButtonClickedEvent);
};