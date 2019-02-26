#pragma once

class IKeyListener
{
    virtual void onKeyPressed(int keycode) = 0;
    virtual void onKeyReleased(int keycode) = 0;
    virtual void onKeyTyped(int keycode) = 0;
};