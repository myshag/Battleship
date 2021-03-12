/*
//  Copyright (c) 2021, Alex Zapevalin
//  All rights reserved.
*/

#include "Observer/Observer.h"
#include "Models/BoardModel.h"

class BoardView: public Observer
{
    public:
    BoardView(BoardModel* model)
    {
        _model = model;
        _model->addObserver(this);

    }
    private:
    BoardModel* _model;
};