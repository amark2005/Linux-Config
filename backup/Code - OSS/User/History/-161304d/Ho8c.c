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
  Player p1={.HP=100,.money=1000,.max_hold=20,.iteminven=0};
  initscr();
  noecho();
  cbreak();
  curs_set(0);


  while (1) {
  box(stdscr,0,0);
  mvprintw(1,2,"Buy Me, Captain Kirk");

  //stat
  mvprintw(3,4,"Health: %d",p1.HP);
  mvprintw(4,4,"Money: %d",p1.money);
  refresh();

  int ch=getch();
  if(ch=='q')break;
  }
  endwin();
  return 0;
}