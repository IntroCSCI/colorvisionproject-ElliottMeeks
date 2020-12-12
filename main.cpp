#include <iostream>
#include <vector>
#include <string>
#include "Color.h"

using namespace std;

// pototypes
string menu(); 

int main()
{
  Color image; // color blind friendly image

  string name = menu(); 
  image.open(name);

  int height = image.height();  
  int width = image.width();

  bool validBmp = image.isImage();

  if( validBmp == true )
  {
    image.change(height,width); // changes the colors of the image
    image.seeOriginal(); // displays original image

    cout << "Find the NEW.bmp and Original.bmp on the LEFT side of the SCREEN! "<< endl;
  }
  
  return 0;
}

// functions
string menu(){

  string full = "Images/********";
  string name = "IMGi.bmp";
  string prompt = "i) IMGi.bmp\n";
  cout << "Which Image Would You Like To Open \n";

  // this works lol
  for (char i = '1'; i<='5'; i++){
    prompt[0] = i;
    prompt[6] = i;
    cout << prompt;
  }

  char answer;
  do{
    cout<< "Pick a Number Between 1-5 \n";
    cin >> answer;
  } while(!(answer <= 53 && answer >= 49));

  name[3] = answer;

  // changes name to the proper return string
  for (int i =0; i< name.length(); i++){
    full[i+7] = name[i]; 
  }
  return full;
}