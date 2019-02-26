#include <iostream>

#include "TestObject.h"
#include "events/Events.h"

int main(int argc, char* argv[])
{
    TestObject t1;
    TestObject t2;
    TestObject t3;
    TestObject t4;
    TestObject t5;

    KeyPressedEvent ke(10);
    MouseButtonClickedEvent me(5, 10, 20);

    DISPATCH_EVENT(ke);
    DISPATCH_EVENT(me);

    std::cout << ke.toString() << std::endl;
    std::cout << me.toString() << std::endl;

    std::cout << "Oui" << std::endl;
    return 0;
}