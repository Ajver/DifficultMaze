#include <windows.h>
#include <cstdio>
#include <iostream>
#include <conio.h>
#include <string>

#include "graphics.h"

// Background color
int bgColor = BLACK;

// Window width and height
int WW = 80, WH = 25;

// Cursor position
int cx = 0, cy = 0;

void init(int w, int h) {
    std::ios_base::sync_with_stdio(false);

    // Hiding cursor
    CONSOLE_CURSOR_INFO cursor;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
    cursor.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);

    setWindowSize(w, h);
}

void setCursorPosition(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void setBackgroundColor(int color) {
    bgColor = color;
    setColor(color);
    fillRectangle(' ', 0, 0, getWindowWidth(), getWindowHeight());
}

void setColor(int color) {
    color += bgColor * 16;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void draw(char c) {
    if(inScreen(cx, cy)) {
        putchar(c);
    }
}

void draw(char c, int x, int y) {
    setCursorPosition(x, y);
    draw(c);
}

void draw(std::string s, int x, int y) {
    setCursorPosition(x, y);
    for(int i=0; i<s.size(); i++) {
        draw(s[i]);
    }
}

std::string toString(int a) {
    std::string str;
    bool isNegative = false;

    if(a < 0) {
        isNegative = true;
        a *= -1;
    }

    do {
        int single = a%10;
        char singleChar = (char)(single + 48);

        a /= 10;

        str = singleChar + str;
    }while(a != 0);

    if(isNegative) {
        str = '-' + str;
    }

    return str;
}

void setWindowSize(int nw, int nh) {
    WW = nw;
    WH = nh;

    system(("mode "+toString(WW)+','+toString(WH)).c_str());
}

int getWindowWidth() {
    return WW;
}

int getWindowHeight() {
    return WH;
}

void fillRectangle(char c, int x, int y, int w, int h) {
    std::string line(w, c);

    for(int i=0; i<h; i++) {
        draw(line, x, y+i);
    }
}

void cls() {
    system("cls");
}

bool inScreen(int x, int y) {
    return
        x >= 0   &&
        x < WW   &&
        y >= 0   &&
        y < WH;
}
