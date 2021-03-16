/*
//  Copyright (c) 2021, Alex Zapevalin
//  All rights reserved.
*/
#include "stdio.h"
#ifndef BOARDMODEL_H
#define BOARDMODEL_H 

#include "../Observer/Observer.h"


//Ячейка игвого поля
enum class CellType
{
    FREE,
    SHIP,
    KILL,
    DEMAGE,
    MISS
    
};

class BoardModel : public Observable
{
public:




    BoardModel();
    BoardModel(BoardModel &&) = default;
    BoardModel(const BoardModel &) = default;

    CellType getCell(int index);
    void setCell(CellType type,int index);

    
    
    ~BoardModel();

private:
    CellType board[100] = {CellType::FREE};
};


#endif // !1