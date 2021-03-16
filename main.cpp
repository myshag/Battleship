/*
//  Copyright (c) 2021, Alex Zapevalin
//  All rights reserved.
*/

#include "Models/BoardModel.h"
#include "BoardView.h"

//Точка входа в игру
#include "stdio.h"

int initConsole()
{
    /* инициализация ncurses */
    initscr();
	//use_default_colors();
	clear();
	
	cbreak();
	noecho();
    

     if (!has_colors())
    {
	endwin();
	printf("\nОшибка! Не поддерживаются цвета\n");
	return 1;
    }

    start_color(); 
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);

    //init_pair(3, COLOR_BLUE, COLOR_GREEN);
    keypad(stdscr, true);
    return 0;
    
};

int main()
{
    initConsole();
    BoardModel* boardmodel1 = new BoardModel();
    BoardModel* boardmodel2 = new BoardModel();
    
    BoardView* boardView1 = new BoardView(4,4,boardmodel1);
    BoardView* boardView2 = new BoardView(47,4,boardmodel2);

    

    WINDOW* infobox = newwin(4, 20, 24, 10);
    wbkgd(infobox, COLOR_PAIR(2));
	wattron(infobox, A_BOLD|COLOR_PAIR(2));
    wprintw(infobox, "Морской\n");

    int cur = 0;
    bool run=true;

                boardmodel1->setCell(CellType::MISS,5);

    while(run)
	{
        refresh();
        wrefresh(infobox);
        boardView1->show();
        boardView2->show();
		
		char key = getch();
		// clear status window
		switch(key)
		{
            refresh();
            case 'Q':
			case 27:
				run = false;
				break;
            case 'd':
            cur++;
            boardmodel1->setCell(CellType::MISS,cur);
            boardView1->show();
            boardView2->show();
            refresh();
            break;
        }
    }
    
    printw("Press any key to continue...");
    refresh();
    endwin();

    printf("\nBye!\n");

    return 0;
}