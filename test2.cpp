#include <curses.h>

#define K 1000/255

int main() {
  initscr();
  start_color();
  use_default_colors();

  init_color(COLOR_BLACK, 0, 0, 0);
  init_color(1, K*0x6f, K*0x67, K*0x76);
  init_color(2, K*0x9a, K*0x9a, K*0x97);
  init_color(3, K*0xc5, K*0xcc, K*0xb8);
  init_color(4, K*0x8b, K*0x55, K*0x80);
  init_color(5, K*0xc3, K*0x88, K*0x90);
  init_color(6, K*0xa5, K*0x93, K*0xa5);
  init_color(7, K*0x66, K*0x60, K*0x92);
  init_color(8, K*0x9a, K*0x4f, K*0x50);
  init_color(9, K*0xc2, K*0x8d, K*0x75);
  init_color(10, K*0x7c, K*0xa1, K*0xc0);
  init_color(11, K*0x41, K*0x6a, K*0xa3);
  init_color(12, K*0x8d, K*0x62, K*0x68);
  init_color(13, K*0xbe, K*0x95, K*0x5c);
  init_color(14, K*0x68, K*0xac, K*0xa9);
  init_color(15, K*0x38, K*0x70, K*0x80);
  init_color(16, K*0x6e, K*0x69, K*0x62);
  init_color(17, K*0x93, K*0xa1, K*0x67);
  init_color(18, K*0x6e, K*0xaa, K*0x78);
  init_color(19, K*0x55, K*0x70, K*0x64);
  init_color(20, K*0x9d, K*0x9f, K*0x7f);
  init_color(21, K*0x7e, K*0x9e, K*0x99);
  init_color(22, K*0x5d, K*0x68, K*0x72);
  init_color(23, K*0x43, K*0x34, K*0x55);

  for (int i = 0; i < 24; i++) {
    init_pair(i + 1, i, COLOR_BLACK);
  }

  wbkgd(stdscr, COLOR_PAIR(14));
  refresh();

  move(0, 0);
  for (int i = 0; i < 24; i++) {
    attron(COLOR_PAIR(i + 1));
    printw("#####");
    attroff(COLOR_PAIR(i + 1));
    printw("\n");
  }

  refresh();
  getch();
  endwin();

  return 0;
}
