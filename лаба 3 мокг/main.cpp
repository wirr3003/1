#include <time.h>
#include "graphics.h"
#include "control.h"
#include "task.h"
#include "graphics.h"
#include "control.h"

using namespace std;

void rebar()
{
   create_control(STAR, SIZEBUTTON, SIZEWINDOW-SIZEBUTTON, "star.bmp");
   create_control(PLUS1, 3*SIZEBUTTON, SIZEWINDOW-SIZEBUTTON, "plus1.bmp");
   create_control(MINUS1, 5*SIZEBUTTON, SIZEWINDOW-SIZEBUTTON, "minus1.bmp");
   create_control(PLUS2, 7*SIZEBUTTON, SIZEWINDOW-SIZEBUTTON, "plus2.bmp");
   create_control(MINUS2, 9*SIZEBUTTON, SIZEWINDOW-SIZEBUTTON, "minus2.bmp");
   create_control(SAVE, 11*SIZEBUTTON, SIZEWINDOW-SIZEBUTTON, "SAVE.bmp");
   create_control(EXIT, 13*SIZEBUTTON, SIZEWINDOW-SIZEBUTTON, "EXIT.bmp");
}

int R=10, n = 5;

int change_rad()
{
   if (R < 10) {
      R = 10;
   }
   if (R > 70) {
      R = 70;
   }
   return R;
}

int change_tops()
{
   if (n < 5) {
      n = 5;
   }
   if (n > 12) {
      n = 12;
   }
   return n;
}

void create_N()
{
   int prom1 = change_rad();
   int prom2 = change_tops();
   setbkcolor(TRANSPARENT);
   settextstyle(EMPTY_FILL, HORIZ_DIR, 37);
   outtextxy(4*SIZEBUTTON+SIZEBUTTON/4, SIZEWINDOW-SIZEBUTTON+SIZEBUTTON/4, to_string(prom1).c_str());
   outtextxy(8*SIZEBUTTON+SIZEBUTTON/4, SIZEWINDOW-SIZEBUTTON+SIZEBUTTON/4, to_string(prom2).c_str());
}

int main() {
   initwindow(1000, 1000);

   IMAGE *back;
   back = loadBMP("fon.jpg");
   putimage(0, 0, back, COPY_PUT);
   rebar();

   while (true) {
      setfillstyle(SOLID_FILL, 15);
      setbkcolor(BLACK);
      while (mousebuttons() != 1);
      switch (select_control()) {
      case NONE:
         break;
      case STAR:
         solve(R, n);
         create_N();
         break;
      case PLUS1:
         R += 5;
         R=change_rad();
         delay(30);
         create_N();
         break;
      case MINUS1:
         R -= 5;
         R=change_rad();
         delay(30);
         create_N();
         break;
      case PLUS2:
         n += 1;
         n = change_tops();
         delay(30);
         create_N();
         break;
      case MINUS2:
         n -= 1;
         n = change_tops();
         delay(30);
         create_N();
         break;
      case SAVE:
         save();
         break;
      case EXIT:
         closegraph();
         return 0;
      }
   }
}