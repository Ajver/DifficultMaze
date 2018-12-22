#include "slEngine.h"

void setUpEngine() {
    setUpEngine(80, 25);
}

void setUpEngine(int w, int h) {
    ios_base::sync_with_stdio(false);
    hideCursor();
    setBackgroundColor(0);
    setWindowSize(w, h);
}
