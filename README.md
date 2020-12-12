# v1.0 Updates
IMAGE CHANGER

## Description

My challenge I came up with for myself was to create a program that could change 
the color of a image to help color blind people while keeping the integrety of the image.
By integrety I mean the basic color of the image. The program seems to work well for 
helping colorblind people. I used a colorblind simulator to test out my altered images and 
the numbers could be seen easily.

## Developer

Elliott Meeks

## C++ Guide

### Algerithem Explination

What I found out is that what defines a color is the ratio of red to green to blue of each pixle. My algerithem keeps 
the red, green, blue ratio but maximizes it. so the largest of the three will go to the value 255 while 
the others will keep the original ratio. this will keep the color of the original image. 

What I suspect this does is it maximizes the brightness of the image. Maybe decreases the contrast. I am 
still not supper sure what it exaclt does but it works and seems to fix the colorblind problem with the testing that I 
have done. 

### Variables and Data Types

Pixel and Bitmap Classes are used to get and alter the pixles of a bmp image.
width and height variebles are important to make sure the program will work with any sized image.
 

### Input and Output

Gets user input to select which file they would like to change. Out puts the altered image and the program also 
prompts the user in the console.

### Decisions

I used if statements to find the greatest of three numbers as part of my algerithem.
in the bitmap.h library I made it if the r,g,b values exceded 255 or was less than 0 than it would set the value to 255 and 0 respectively.

### Iteration

nested for loop to go through each pixle

### File Input and Output

inputs a bmp image and alters the colors slightly in order to help colorblind people.

### Arrays/Vectors
vector < vector <Pixel> > bmp 
2D Vector that gets the Pixel from every coordinant of the image.

### Functions

void changeColor(Pixel &, int,int,int)
function to change the rgb values of the image. used in pixles()

void pixles(Pixel &, vector <vector <Pixel>> &,int, int)
locates each pixle in the image and gets it orginal rgb values and changes them.

int findGreatest(int , int, int)
finds the greates of red, green and blue.

int algerithem(int , double)
maximises the ration of red green and blue. SEE Algerithem Explination.

string menue()
generates the starting image and gets the user input to choose an image to change

### Classes

Class Color
this allowes you to creat an image data type that can be used to take a normal bmp picture and change it to a color blind friendy picture useing .change() and it also saves the original picture with 
.seeOriginal()