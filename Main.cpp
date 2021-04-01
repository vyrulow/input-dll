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
        // All reading is now done from OBS' Fullscreen Projector to bypass screenlock (nj blizzard!)
        // Since that's the path I took, all this does is bring Overwatch to the foreground if it isn't,
        // execute mouse events, then immediately swap OBS' Fullscreen Projection to the foreground to continue reading.
        if (obsHwnd != hWnd) {
            SetForegroundWindow(hWnd);
            SetCursorPos(x, y);
            Sleep(10);
            mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
            Sleep(10);
            SetForegroundWindow(obsHwnd);
        }
    }
}
