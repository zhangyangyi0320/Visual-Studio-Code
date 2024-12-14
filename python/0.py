#  -*- coding: UTF-8 -*-

# MindPlus
# Python
import pyautogui


if (pyautogui.confirm(title="C++", text="是否打印？", buttons=["Ok", "Cancel"]) == (str("Ok"))):
    pyautogui.write(message="#include<bits/stdc++.h>", interval=0.1)
    pyautogui.press(keys="Delete", presses=1)
    pyautogui.press(keys="Enter", presses=1)
    pyautogui.write(message="using namespace std;", interval=0.1)
    pyautogui.press(keys="Enter", presses=1)
    pyautogui.write(message="int main(){", interval=0.1)
    pyautogui.press(keys="Delete", presses=1)
    pyautogui.press(keys="Enter", presses=1)
    pyautogui.press(keys="Tab", presses=1)
    pyautogui.press(keys="Enter", presses=1)
    pyautogui.write(message="return 0;", interval=0.1)
    pyautogui.press(keys="Enter", presses=1)
    pyautogui.press(keys="Backspace", presses=1)
    print(pyautogui.alert(title="C++", text="打印完成！", button="Ok"))
