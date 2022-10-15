#ifndef TASK_H //проверка на подключенность файла
#define TASK_H

#define M_PI 3.141592
#define SIZEWINDOW 1000
#define SIZEBUTTON  64

void create_star(int x0, int y0, int n, int R);
void create_line(int x1, int y1);
int change_rad();
int change_tops();
void solve(int, int);
void save();

#endif