/*
//  Copyright (c) 2021, Alex Zapevalin
//  All rights reserved.
*/

#include "Observer/Observer.h"
#include "Models/BoardModel.h"
#include <ncurses.h>

class BoardView: public Observer
{
    public:

    void show();
    void update();

    BoardView(int x, int y, BoardModel* model);
    

    private:

    const char* getCharXY(int i, int j);


    int max_i = 11;
    int max_j = 11;

    int _x;
    int _y;

    void drawGrid();
    void initWindow();
    BoardModel* _model;
    WINDOW* grid;
};