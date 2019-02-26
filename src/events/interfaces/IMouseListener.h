#pragma once

class IMouseListener
{
    virtual void onMouseMove(float mouseX, float mouseY) = 0;
    virtual void onMouseScrolled(float offsetX, float offsetY) = 0;
    virtual void onMouseButtonPress(int button) = 0;
    virtual void onMouseButtonReleased(int button) = 0;
    virtual void onMouseButtonClicked(int button) = 0;
};