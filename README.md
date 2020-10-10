Black and White

## Description

Takes any image and changes it to Black and White 

## Developer

Elliott Meeks

## Example

1. Upload a bmp image
2. change image.open("test4.bmp") to your file name.

```
g++ --std=c++11 main.cpp -o cvp
./cvp
```

Here is an example of the program running:

```
!!!Replace with an example of the program running with user interaction!!!
```

## C++ Guide

### Variables and Data Types

Width of image and height of image are used in the for loops

### Input and Output

inputs a pixles rgb values and outputs their average for a greyscale efect

### Decisions

in your library I made it if the r,g,b values exceded 255 or was less than 0 than it would set the value to 255 and 0 respectively.

### Iteration

for loops going through each pixle

### File Input and Output

input an image file, outputs its greyscale