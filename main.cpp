#include "graphics.h"

#include <conio.h>
#include <time.h>
#include <cstdlib>

using namespace std;

// Player position
int px, py;

// Treasure position
int tx, ty;

// true - can go
// false - you shall not pass!
bool tileMap[60][20] { true };

////////////////////////////////////////////////////////////////

void clearPlayer() {
    draw(' ', px, py);
}

void drawPlayer() {
    setColor(BLUE);
    draw('@', px, py);
}

void drawTreasure() {
    setColor(YELLOW);
    draw('$', tx, ty);
}

void drawMap() {
    setColor(WHITE);

    for(int y=0; y<getWindowHeight(); y++) {
        for(int x=0; x<getWindowWidth(); x++) {
            if(!tileMap[x][y]) {
                draw('#', x, y);
            }
        }
    }
}

void playerControll() {
    char moveDir = getch();

    clearPlayer();

    switch(moveDir) {
        // UP
    case 'w':
    case 'W':
        if(py > 0) {
            if(tileMap[px][py-1]) {
                py--;
            }
        }
        break;

        // DOWN
    case 's':
    case 'S':
        if(py < getWindowHeight() - 1) {
            if(tileMap[px][py+1]) {
                py++;
            }
        }
        break;

        // LEFT
    case 'a':
    case 'A':
        if(px > 0) {
            if(tileMap[px-1][py]) {
                px--;
            }
        }
        break;

        // RIGHT
    case 'd':
    case 'D':
        if(px < getWindowWidth() - 1) {
            if(tileMap[px+1][py]) {
                px++;
            }
        }
        break;
    }

    drawPlayer();
}


////////////////////////////////////////////////////////////////

int main()
{
    init(60, 20);
    setBackgroundColor(DARK_GRAY);

    srand(time(NULL));

    // Generate the map
    for(int y=0; y<getWindowHeight(); y++) {
        for(int x=0; x<getWindowWidth(); x++) {
            bool isWall = false;
            tileMap[x][y] = rand() % 100 < 70;
        }
    }

    tileMap[px][py] = true;
    tileMap[tx][ty] = true;

    // Generate the player position
    px = rand() % getWindowWidth();
    py = rand() % getWindowHeight();

    // Generate the treasure position
    tx = rand() % getWindowWidth();
    ty = rand() % getWindowHeight();

    // Display everything
    drawMap();
    drawPlayer();
    drawTreasure();

    while(true) {
        playerControll();
    }

    return 0;
}
