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
    setColor(WHITE);
    draw('@', px, py);
}

void drawTreasure() {
    setColor(YELLOW);
    draw('$', tx, ty);
}

void drawMap() {
    setColor(BLACK);

    for(int y=0; y<getWindowHeight(); y++) {
        for(int x=0; x<getWindowWidth(); x++) {
            if(!tileMap[x][y]) {
                draw((char)219, x, y);
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

bool isWon() {
    return (px == tx) && (py == ty);
}

void initGame() {
    // Generate the map
    for(int y=0; y<getWindowHeight(); y++) {
        for(int x=0; x<getWindowWidth(); x++) {
            bool isWall = false;
            tileMap[x][y] = rand() % 100 < 70;
        }
    }

    // Generate the player position
    px = rand() % getWindowWidth();
    py = rand() % getWindowHeight();

    // Generate the treasure position
    tx = rand() % getWindowWidth();
    ty = rand() % getWindowHeight();

    tileMap[px][py] = true;
    tileMap[tx][ty] = true;

    // Display everything
    drawMap();
    drawPlayer();
    drawTreasure();
}

////////////////////////////////////////////////////////////////

int main()
{
    init(60, 20);
    setBackgroundColor(DARK_GRAY);

    srand(time(NULL));

    initGame();

    while(true) {
        playerControll();

        if(isWon()) {
            // Clear previous frame
            cls();
            initGame();
        }
    }

    return 0;
}
