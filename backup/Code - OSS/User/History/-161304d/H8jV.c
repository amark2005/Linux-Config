#include<ncurses.h>
#include <unistd.h>
typedef struct{
  unsigned int money;
  unsigned int max_hold;
  unsigned int iteminven;
  unsigned int HP;
} Player;

typedef struct{
  unsigned int inventorysize;
  
} Market;

int main(){
  initscr();
  noecho();
  cbreak();

  int hp=100;
  int thirst=0;

  while (1) {
  box(stdscr,0,0);
  mvprintw(1,2,"Neeya Naana");

  //stat
  mvprintw(3,4,"Health: %d",hp);
  mvprintw(4,4,"Thirst: %d",thirst);
  refresh();

  int ch=getch();
  if(ch=='q')break;
  }
  endwin();
  return 0;
}