#include "ui.hpp"
#include <ncurses.h>

WINDOW* draw_filter_rack(int yMax, int xMax)
{
    int width = 30;
    int height = yMax;
    WINDOW* filterRack = newwin(height, width, 0, 0);
    box(filterRack, 0, 0);
    refresh();
    mvprintw(0, 9, "Filter Rack");
    wrefresh(filterRack);
    return filterRack;
}

WINDOW* draw_hotkey_box(int yMax, int xMax)
{
    int offset = 31;
    int width = xMax - offset;
    int height = 10;
    int startY = yMax - height;
    int startX = offset;
    WINDOW* hotkeyBox = newwin(height, width, startY, startX);
    box(hotkeyBox, 0, 0);
    refresh();
    mvprintw(yMax - height, width / 2 + 24, "Hotkeys");
    wrefresh(hotkeyBox);
    return hotkeyBox;
}

WINDOW* draw_preview_screen(int yMax, int xMax)
{
    int yOffset = 10;
    int xOffset = 31;
    int height = yMax - yOffset;
    int width = xMax - xOffset;
    int startY = 0;
    int startX = xOffset;
    WINDOW* previewScreen = newwin(height, width, startY, startX);
    box(previewScreen, 0, 0);
    wrefresh(previewScreen);
    return previewScreen;
}

void run_ui()
{
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);

    // get scree size
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    draw_filter_rack(yMax, xMax);
    draw_hotkey_box(yMax, xMax);
    draw_preview_screen(yMax, xMax);


    int ch;
    while ((ch = getch()) != 'q') {}

    endwin();
}

