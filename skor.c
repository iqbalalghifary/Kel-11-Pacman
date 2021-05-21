#include "skor.h"

void drawInfo(int score, int up)
{
   setcolor(EGA_BLACK);
   _fill_color = BLACK;
   bar(0,660,600,680);
   setcolor(YELLOW);
   settextstyle(1, 0, 6);
   outtextxy(0, 663, "========================= Score = ");
   outtextxy(270, 663, numToString(score));
   outtextxy(300, 663, "UP = ");
   outtextxy(350, 663, numToString(up));
   outtextxy(380, 663, "=======================");
}

void gameOverPage(int score)
{
  text_mode();
  textbackground(0);
  textcolor(WHITE);
  clrscr();
  gotoxy(20,5);
  cprintf("GAME OVER");
  gotoxy(20,10);
  cprintf("score:%d",score);
  getch();

}
