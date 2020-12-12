#include "Color.h"
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

// public Member function implementations...

// shows color blind friendly image
void Color :: change(int width, int height){
  convert = false;
  bmp = toPixelMatrix();
  origin = toPixelMatrix();
  pixels(rgb, bmp ,width, height); 
  fromPixelMatrix(bmp);
  save("NEW.bmp");
}

// showes original image
void Color :: seeOriginal(){
  if (convert){
    origin = toPixelMatrix();
  }
  fromPixelMatrix(origin);
  save("Original.bmp");
}

// private member functions...
// finds the greatest value of rgb
int Color :: findGreatest(int r, int g, int b) 
{
    if(r>=b && r>=g){
    return r;
  } else if (b>=r && b>=g){
    return b;
  } else if (g>=b && g>=r){
    return g;
  }
  return 0;
}

// my formula to change the ration or red green blue to become color blind friendly
int Color :: algorithm(int color, double largest)
{
  int newColor = 255.0*(color/largest); 
  return newColor;
}

// changes the value of rgb utilizing the formula
void Color :: changeColor(Pixel & rgb, int r, int g, int b) 
{
  int largest = findGreatest(r,g,b);
  
  rgb.red = algorithm(r,largest);
  rgb.green = algorithm(g,largest);
  rgb.blue = algorithm(b,largest);
}

// gets the location of each pixle i,j to change their value
void Color :: pixels(Pixel & rgb, vector <vector <Pixel>> & bmp, int width, int height) 
{

  for(int i = 0; i<height; i++)
  {
    for(int j = 0; j<width; j++)
    {
      rgb = bmp[i][j];
        
      int r = rgb.red;
      int g = rgb.green;
      int b = rgb.blue;

      changeColor(rgb, r,g,b);

      bmp[i][j] = rgb;
    }  
  }  
}