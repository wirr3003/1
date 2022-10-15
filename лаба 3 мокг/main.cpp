#include <time.h>
#include "graphics.h"
#include "control.h"
#include "task.h"
#include "graphics.h"
#include "control.h"

using namespace std;

void rebar()
{
   create_control(PLUS1, 40, 360, "plus1.bmp");
   create_control(MINUS1, 170, 360, "minus1.bmp");
   create_control(PLUS2, 40, 360, "plus2.bmp");
   create_control(MINUS2, 170, 360, "minus2.bmp");
   create_control(SAVE, 350, 360, "SAVE.bmp");
   create_control(EXIT, 400, 360, "EXIT.bmp");
}

int R=10, n = 5;

int change_rad()
{
   if (R < 10){
      R = 10;
   }
   if (R > 90){
      R = 90;
   }
   return R;
}

int change_tops()
{
   if (n < 5){
      n = 5;
   }
   return n;
}

void create_N()
{
      int prom1 = change_rad();
      int prom2 = change_tops();
      setbkcolor(TRANSPARENT); 
      settextstyle(EMPTY_FILL, HORIZ_DIR, 37);      
      outtextxy(210, 40, to_string(prom1).c_str());
      outtextxy(525, 40, to_string(prom2).c_str());
}

int main(){
   initwindow(800, 500);
   
    IMAGE *back;
    back = loadBMP("fon.jpg");
    putimage(0, 0, back, COPY_PUT);
   rebar();
   create_N;


   
   while(true){
      setfillstyle(SOLID_FILL, 15);
      setbkcolor(BLACK);
      while(mousebuttons() != 1);
      switch(select_control()){
         case NONE:
            break;
         case PLUS1: 
            R += 5;
            create_N();
            break;
         case MINUS1:
            R -= 5;
            create_N();
            break;
         case PLUS2: 
            n += 1;
            create_N();
            break;
         case MINUS2:
            n -= 1;
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