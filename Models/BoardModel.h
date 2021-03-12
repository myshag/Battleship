/*
//  Copyright (c) 2021, Alex Zapevalin
//  All rights reserved.
*/
#include "stdio.h"
#ifndef BOARDMODEL_H
#define BOARDMODEL_H 

#include "../Observer/Observer.h"


class BoardModel : public Observable
{
public:
    BoardModel();
    BoardModel(BoardModel &&) = default;
    BoardModel(const BoardModel &) = default;
    
    ~BoardModel();

private:
    
};

BoardModel::BoardModel()
{
     printf("BoardModel()");
}

BoardModel::~BoardModel()
{
}

#endif // !1