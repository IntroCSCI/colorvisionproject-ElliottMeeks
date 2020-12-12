
#ifndef COLORS_H
#define COLORS_H

#include <iostream>
#include <string>
#include <vector>
#include "bitmap.h"

using std::string;
using std::vector;


class Color: public Bitmap {
  private: 
    bool convert = true;
    Pixel rgb;
    vector <vector <Pixel> > bmp;
    vector <vector <Pixel> > origin;
    
    void changeColor(Pixel &,int,int,int); 
    void pixels(Pixel &, vector <vector <Pixel>> &,int, int); 
    int findGreatest(int , int, int); 
    int algorithm(int , double);  

  public: 
    void change(int,int);
    void seeOriginal();
};

#endif