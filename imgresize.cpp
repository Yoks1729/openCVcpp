// cpp program to read,display and resize the image to our desired dimensions using opencv. 
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;
// declaraing global variables(so that they can further be used in any of the function).
// Mat-The Basic Image Container.
Mat img;
// the header name which you want to display on the top of image widow.
char windowname[50] = "Image";
// function to resize the image.It is of void type,as it returns nothing.
void imgresize()
{
    // these variables aur used to store the dimensions of new image
    double w,h;
    // to store the dimensions of image
    Size s = img.size();
    cout<< "Resize Image." <<endl;
    cout<< "Width: ";
    cin>> w;
    cout<< "Height: ";
    cin>> h;
    // if new width=0 then it will resize it with proportion to new height(new height:new width::original height:original width)
    if (w == 0)
    {
        h = h/s.height;
        w = h;
    }
    // if new height=0 then it will resize it with proportion to new width(new height:new width::original height:original width)
    else if (h == 0)
    {
        w = w/s.width;
        h = w;
    }
    // it will abort the program as dimensions are supposed to be positive numbers
    else if (w == 0 && h == 0)
    {
        h = h;
        w = w;
    }
    // it will change the older dimensions to new ones
    else
    {
        w = w/s.width;
        h = h/s.height;
    }
    // this function resizes the image to our desire dimensions
    resize (img,img,Size(),w,h);
     // show our image inside it.
    imshow (windowname,img);
    // the int value inside wait key is time in milliseconds the program waits.
    waitKey (500);
}
int main()
{
    // variable s of string type is used to store the path of image which you want to display.
    string s;
    cout<< "Enter the path of Image which you want to display.";
    cin>> s;
    // imread returns the image data in the array.
    img = imread(s);
    // creating a window to display image.
    namedWindow (windowname,WINDOW_AUTOSIZE);
     // show our image inside it.
    imshow (windowname,img);
    // the int value inside wait key is time in milliseconds the program waits.
    waitKey (300);
    char key;
    cout<< "Press any key amd enter to proceed " << endl;
    cin>> key;
    while ( key != 'q')
    {

    cout<< "Enter 'r' to RESIZE and 'e' to EXIT" << endl ;
    cin>> key;

    switch(key)
    {
        case 'r':
        imgresize();
        break;
        case 'e':
        // to exit the program. 
         exit (0);
         break;
         default:
         cout<< "Please enter a valid key" << endl;
         break;
        }
    }
    // to exit the program. 
    exit (0);
}
