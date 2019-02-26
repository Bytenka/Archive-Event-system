/* 
 * EventListener is the main class to receive events. Usually, the listener is tied to another object
 * and you should therefore give a pointer to this object at the creation of the listener.
 * 
 * Events are categorised in "channels", which you can "subscribe" to using the so called function.
 * Subcribing requires to give a callback function, with the following signature:
 * 
 *  void callback(void *object, Event &event);
 * Where:
 *      - object:   the object concerned by the event, nullptr if none. You can safely cast this pointer
 *                  in the type of the object you've attached the EventListener to (if one)
 *      - event:    the event
 * 
 * When using an EventListener, you can force the implementation of functions related to the channels
 * you're listening to by inheriting for the corresponding interfaces.
 * 
 */

/* ---------- Example usage ----------

class ExampleClass : public IMouseListener
{
  public:
    ExampleClass()
        : m_eventListener(this)
    {
        m_eventListener.subscribe(EventChannel::Mouse, mouse_callback);
    }

    ~ExampleClass() {}

  private:
    static void mouse_callback(void* object, Event& event)
    {
        ExampleClass* obj = (ExampleClass*)object;

        switch (event.type) {
        case MouseMoved: {
            MouseMovedEvent* e = (MouseMovedEvent*)&event;
            obj->movedMouse(e->getX(), e->getY());
            break;
        }

        case MouseButtonClicked: {
            MouseButtonClickedEvent* e = (MouseButtonClickedEvent*)&event;
            obj->clickedMouse(e->getButton(), e->getX(), e->getY());
            break;
        }

        default:
            break;
        }
    }

    void movedMouse(float mouseX, float mouseY)
    {
        // Process here
    }

    void clickedMouse(int mouseButton, float mouseX, float mouseY)
    {
        // Process here
    }

  private:
    EventListener m_eventListener;
};

-------------------- */


#include "types/KeyEvent.h"
#include "types/MouseEvent.h"

#include "system/EventDispatcher.h"
#include "system/EventListener.h"

// Interfaces
#include "interfaces/IKeyListener.h"
#include "interfaces/IMouseListener.h"