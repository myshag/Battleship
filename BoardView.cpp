/*
//  Copyright (c) 2021, Alex Zapevalin
//  All rights reserved.
*/

#include "Observer/Observer.h"
#include "Models/BoardModel.h"
#include "BoardView.h"
#include <ncurses.h>

#define COLOR_HIGHLIGHT_CURSOR	5

void BoardView::update()
{
    
}

const char* BoardView::getCharXY(int i, int j)
{

    switch (_model->getCell(i*10+j))
    {
    case CellType::FREE:
            return " ";
        break;

    case CellType::DEMAGE:
            return "*";
        break;

    case CellType::KILL:
            return "X";
        break;

    case CellType::MISS:
            return "O";
        break;

     case CellType::SHIP:
            return "H";
        break;   
    
    default:
        return " ";
        break;
    }

}

void BoardView::show()
    {
        drawGrid();
        wrefresh(grid);
        refresh();
    };

void BoardView::initWindow ()
{
    grid = newwin(max_j*2-1, (max_i-1)*3+max_i, _y, _x);
	drawGrid();
}

void BoardView::drawGrid()
{

	int i, j;

	for(i = 0;i < max_i;i++)
	{
		for(j = 0;j < max_j;j++)
		{
			
		wattron(grid, A_BOLD|COLOR_PAIR(1));	

			if(i == 0 && j == 0)
				waddch(grid, ACS_ULCORNER);
			else if(i == 0 && j == max_j-1)
				waddch(grid, ACS_URCORNER);
			else if(i == max_i-1 && j == max_j-1)
				waddch(grid, ACS_LRCORNER);
			else if(i == max_i-1 && j == 0)
				waddch(grid, ACS_LLCORNER);
			else if(i == 0)
				waddch(grid, ACS_TTEE);
			else if(i == max_i-1)
				waddch(grid, ACS_BTEE);
			else if(j == 0)
				waddch(grid, ACS_LTEE);
			else if(j == max_j)
				waddch(grid, ACS_RTEE);
			else
				waddch(grid, ACS_PLUS);

			if(j < max_j-1)
			{
				waddch(grid, ACS_HLINE);
				waddch(grid, ACS_HLINE);
				waddch(grid, ACS_HLINE);
			}
			if(i % 3 == 0)
			{
				wattron(grid, A_BOLD|COLOR_PAIR(1));
			}
		}
		for(j = 0;j < max_j && i < max_i-1;j++)
		{
			if(j % 3 == 0)
				wattron(grid, A_BOLD|COLOR_PAIR(1));
			if(j > 0)
            {
                 wprintw(grid, " ");
				wattron(grid, COLOR_PAIR(1));
                wprintw(grid,getCharXY(i,j));
                wattron(grid, A_BOLD|COLOR_PAIR(1));
                wprintw(grid, " ");

            }
			waddch(grid, ACS_VLINE);
			if(j % 3 == 0)
			{
				wattron(grid, A_BOLD|COLOR_PAIR(1));
			}
		}
	}
    //move(5,2);
    //waddch(grid, 'A' | A_BOLD | A_UNDERLINE);
}



BoardView::BoardView(int x, int y,BoardModel* model)
{
    _x=x;
    _y=y;
        _model = model;
        _model->addObserver(this);
        initWindow();
        drawGrid();
        
};