#include <iostream>
#include <vector>
#include "libraries/bitmap.h"

using namespace std;

// pototypes
void changeColor(Pixel &, int,int,int); // changes the color rgb values in each pixle
void pixles(Pixel &, vector <vector <Pixel>> &,int, int); // locates all the pixles
int findGreatest(int , int, int); // find the largests of red,green,blue
int algerithem(int , double);  // makes colors more viberant
string menue(); // starting menue

int main()
{
  Bitmap image;
  Pixel rgb;
  vector <vector <Pixel> > bmp;

  string name = menue(); // generates menue and gets user input
  image.open(name); // Opens Image

  int height = image.height();
  int width = image.width();

  //verify that the file opened was a valid image
  bool validBmp = image.isImage();

  if( validBmp == true )
  {
    bmp = image.toPixelMatrix(); // Images Pixles to a vector of vectors 

    pixles(rgb, bmp ,width, height); // Alters the color of each pixle to be seen more easily

    // saves image
    image.fromPixelMatrix(bmp);
    image.save("NEW.bmp");

    cout << "Find the NEW.bmp on the LEFT side of the SCREEN! "<< endl;
  }
  
  return 0;
}

string menue(){

  string name = "IMGi.bmp";
  string prompt = "i) IMGi.bmp\n";
  cout << "Which Image Would You Like To Open \n";

  // this works lol
  for (char i = '1'; i<='5'; i++){
    prompt[0] = i;
    prompt[6] = i;
    cout << prompt;
  }

  char ans;
  cin >> ans;

  while (!(ans <='5' && ans >= '1')){
    cout<< "Please Pick a Number Between 1-5 \n";
    cin >> ans;
  }

  name[3] = ans;
  return name;
}

int findGreatest(int r, int g, int b) 
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

int algerithem(int color, double largest)
{
  int newColor = 255.0*(color/largest); 
  return newColor;
}


void changeColor(Pixel & rgb, int r, int g, int b) 
{
  int largest = findGreatest(r,g,b);
  
  rgb.red = algerithem(r,largest);
  rgb.green = algerithem(g,largest);
  rgb.blue = algerithem(b,largest);
}

void pixles(Pixel & rgb, vector <vector <Pixel>> & bmp, int width, int height) 
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