#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED

#endif // GRAPHICS_H_INCLUDED

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>

#include "slVariables.h"
#include "slVec2D.h"


using namespace std;

//==============================================================================
//                     x       y
void setCursorPosition(int,     int);
void hideCursor();
void cleanScreen();
//==============================================================================
//                      color
void setColor(          int);
void setBackgroundColor(int);

enum slCOLOR {
    slBLACK         = 0,
    slDARK_BLUE     = 1,
    slDARK_GREEN    = 2,
    slDARK_CYAN     = 3,
    slDARK_RED      = 4,
    slDARK_PURPLE   = 5,
    slDARK_YELLOW   = 6,
    slGRAY          = 7,
    slGREY          = 7,
    slDARK_GRAY     = 8,
    slBLUE          = 9,
    slGREEN         = 10,
    slCYAN          = 11,
    slRED           = 12,
    slPURPLE        = 13,
    slYELLOW        = 14,
    slWHITE         = 15,
};

//==============================================================================
//          what?   x       y      color
void draw(  char);
void draw(  char,   int,    int);
void draw(  int,    int,    int,    int);
void draw(  char,   int,    int,    int);
void draw(  float,   int,    int,    int);
void draw(  float,   string,    int,    int);
void draw(  string, int,    int);
void draw(  string, int,    int,    int);
void draw(  int, string,    int,    int);
void draw(  string, string, int,    int);

//==============================================================================
//          what?   x       y       color   delay (ms)
void write( char,   int,    int,    int,    int);
void write( string, int,    int,    int,    int);
void write( string, string, int,    int,    int);

//==============================================================================
//             x    y
void translate(int, int);
void translateTo(int, int);

//==============================================================================
//                  what?   x       y       w       h       color
void fillRectangle( char,   int,    int,    int,    int,    int);

//                  what?   centerX centerY r       color
void fillCircle(    char,   int,    int,    int,    int);
void drawCircle(    char,   int,    int,    int,    int);



/*~~~~~~~~~~~~~~~~~~~~ DELETED FOR THE MOMENT ~~~~~~~~~~~~~~~~~~~~~~~~

//            what?     x1      y1      x2      y2      color
//void drawLine(char,     int,    int,    int,    int,    int);

//~~~~~~~~~~~~~~~~~~~~ DELETED FOR THE MOMENT ~~~~~~~~~~~~~~~~~~~~~~~~ */



//==============================================================================
void setWindowSize(int, int);
int getWindowWidth();
int getWindowHeight();

void pause();

bool inScreen(int, int);
