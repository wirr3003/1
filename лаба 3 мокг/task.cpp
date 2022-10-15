#include <math.h>
#include "graphics.h"
#include <cstdlib>
#include "task.h"

fillbar fillbar;

void create_line(int x1, int y1)
{
   setcolor(WHITE);//текущий цвет рисования
   setfillstyle(SOLID_FILL, WHITE);//шаблон, цвет заполнения и опционально цвет фона
   setcolor(WHITE);
   int x0 = create_x();
   int y0 = create_y();
   int Sx, Sy, dx, dy, p;
   
   Sx = x0 > x1 ? -1 : 1;
   Sy = y0 > y1 ? -1 : 1;
   dx = abs(x1 - x0);
   dy = abs(y1 - y0);
   
   if (dx >= dy){
      p = 2 * dy - dx;
      for (int i = x0; i != x1; i += Sx){
        putpixel (i, y0, getcolor());
         y0 = p > 0 ? y0 + Sy : y0;
         p = p > 0 ? p + 2 * (dy - dx) : p + 2 * dy; 
      }
   }
   else{
      p = 2 * dx - dy;
      for (int i= y0; i != y1; i += Sy)
      {
         putpixel (x0, i, getcolor());
         x0 = p > 0 ? x0 + Sx : x0;
         p = p > 0 ? p + 2 * (dx - dy) : p + 2 * dx;
      }
      putpixel(x1, y1, WHITE);
   }

}

void create_star(int x0, int y0, int R, int n)
{
   double r = (R * cos(2 * M_PI / n)) / cos(M_PI / n);
   double pi = M_PI / n;
   
   for (int k = 0; k < 2 * n + 1; k++)
    {
        int l = k % 2 == 0 ? R : r;
        double x = (x0 + l * cos(k * pi));
        double y = (y0 + l * sin(k * pi));
        if (k == 0) moveto(x, y);
        create_line(x, y);
        moveto(x, y);
    }
   //delay(10);
   floodfill(x0, y0, getcolor());
}
   
void save()
{
   int w, h;
   IMAGE *output;
   
   w = getmaxx() + 1;
   h = getmaxy() + 1;
   output = createimage(w, h);
   
   getimage(0, 0, w - 1, h - 1, output);
   saveBMP("output1.bmp", output);
   freeimage(output);
}