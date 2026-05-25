#include<ncurses.h>
#include <unistd.h>

int main(){
  initscr();
  for(int i=1;i<=10;i++){
    clear();
    printw("%d\n",i);
    refresh();
    usleep(100000);
  }
  getch();
  endwin();
  return 0;
}