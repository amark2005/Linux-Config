#include<ncurses.h>
#include <unistd.h>

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
  mvprintw(3,4)
  }
}