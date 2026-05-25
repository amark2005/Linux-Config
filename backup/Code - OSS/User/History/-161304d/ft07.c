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

int openinvo(Player *hlo){
  clear();
  box(stdscr,0,0);
  mvprintw(1,2,"Inventory");
  //stat
  mvprintw(3,4,"Max_Hold: %d",hlo->max_hold);
  mvprintw(4,4,"No.of Item: %d",hlo->iteminven);
  refresh();
  int ch=getch();
  if (ch=='q') {
  return 0;
  }
  return 0;
}

int mainmenu(Player *hlo){
  box(stdscr,0,0);
    mvprintw(1,2,"Buy Me, Captain Kirk");

    //stat
    mvprintw(3,4,"Health: %d",hlo->HP);
    mvprintw(4,4,"Money: %d",hlo->money);
    refresh();

    int ch=getch();
    if (ch=='i') openinvo(hlo);
    if(ch=='q')return 0;
    return 0;
}

int main(){
  Player p1={.HP=100,.money=1000,.max_hold=20,.iteminven=0};
  initscr();
  noecho();
  cbreak();
  curs_set(0);


  while (1) {
    clear();
    int mainmenu_run=mainmenu(&p1);
    if(mainmenu_run==0)break;
  }
  endwin();
  return 0;
}