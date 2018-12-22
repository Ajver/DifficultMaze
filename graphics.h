#pragma once

// Colors
#define BLACK         0
#define DARK_BLUE     1
#define DARK_GREEN    2
#define DARK_CYAN     3
#define DARK_RED      4
#define DARK_PURPLE   5
#define DARK_YELLOW   6
#define GRAY          7
#define GREY          7
#define DARK_GRAY     8
#define BLUE          9
#define GREEN         10
#define CYAN          11
#define RED           12
#define PURPLE        13
#define YELLOW        14
#define WHITE         15

#include <string>

// Initialize all systems (window width, height)
extern void init(int, int);

extern void setWindowSize(int, int);

extern int getWindowWidth();

extern int getWindowHeight();

// Set background of the console and clear all content (color)
void setBackgroundColor(int);

// Set color of next displaying text
extern void setColor(int);

// Clear screen
extern void cls();

// Draw on screen (what, x, y)
extern void draw(char, int, int);
extern void draw(std::string, int, int);

// Simply drawing
extern void draw(char);

// Fill rectangle on screen (what, x, y, w, h)
void fillRectangle(char, int, int, int, int);

// Set position of drawing cursor (x, y)
extern void setCursorPosition(int, int);

// Change number to string (number)
extern std::string toString(int);

// Is point in screen (x, y)
extern bool inScreen(int, int);

