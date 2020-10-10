#include <iostream>
#include <vector>
#include "libraries/bitmap.h"

using namespace std;

Bitmap image;
vector <vector <Pixel> > bmp;
Pixel rgb;

void changeColor(int r, int g, int b)
{

  int greyScale = (r+g+b)/2;
 
  rgb.red = greyScale;
  rgb.green = greyScale;
  rgb.blue = greyScale;
}

void pixles(int width, int height)
{

  for(int i = 0; i<height; i++)
  {
    for(int j = 0; j<width; j++)
    {
      rgb = bmp[i][j];
        
      int r = rgb.red;
      int g = rgb.green;
      int b = rgb.blue;

      changeColor(r,g,b);

      bmp[i][j] = rgb;
    }  
  }  
}

int main()
{
  //read a file example.bmp and convert it to a pixel matrix
  image.open("test4.bmp");

  int height = image.height();
  int width = image.width();

  //verify that the file opened was a valid image
  bool validBmp = image.isImage();

  if( validBmp == true )
  {
    bmp = image.toPixelMatrix();

    pixles(width, height);

    image.fromPixelMatrix(bmp);
    image.save("BlackWhite.bmp");
  }
  cout << "done!"<< endl;
  return 0;
}