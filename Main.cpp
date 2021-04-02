#include "Windows.h"
#include <jni.h>
#include "Main.h"
#include <iostream>

JNIEXPORT void JNICALL Java_circus_CFunctions_injectMouseMovement
(JNIEnv*, jobject, jint x, jint y)
{
    HWND hWnd = FindWindowA(NULL, "Overwatch");
    HWND obsHwnd = FindWindowA(NULL, "Fullscreen Projector (Source) - Game Capture");
    int size = GetWindowTextLength(obsHwnd);

    if (!hWnd) {
        printf("Couldn't find English Overwatch client.\n");
    }
    else {
        if (obsHwnd != hWnd) {
            SetForegroundWindow(hWnd);
            SetCursorPos(x, y);
            Sleep(25);
            mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
            Sleep(25);
            SetForegroundWindow(obsHwnd);
        }
    }
}

JNIEXPORT void JNICALL Java_circus_CFunctions_injectKeyboardInput
(JNIEnv*, jobject, jstring input)
{
    HWND hWnd = FindWindowA(NULL, "Overwatch");
    if (!hWnd)
        return;

    SendMessage(hWnd, WM_SETTEXT, NULL, (LPARAM)input);
}
