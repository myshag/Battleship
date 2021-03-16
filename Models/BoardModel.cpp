/*
//  Copyright (c) 2021, Alex Zapevalin
//  All rights reserved.
*/

#include "BoardModel.h"

BoardModel::BoardModel() {

   // board[99]=CellType::DEMAGE;

};

CellType BoardModel::getCell(int index)

{
   // if (index==4) return CellType::DEMAGE;
    return this->board[index-1];
}

void BoardModel::setCell(CellType type,int index)
{
    this->board[index-1]=type;
}

