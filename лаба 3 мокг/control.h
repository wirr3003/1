#ifndef CONTROL_H
#define CONTROL_H

enum control_values { NONE = -1, SAVE, EXIT, 
                      PLUS1,  MINUS1, 
                      PLUS2, MINUS2, N_CONTROLS };

struct Control{
   int left;
   int top;
   int right;
   int bottom;
};

void create_control(int, int, int, const char *);
int select_control();

#endif