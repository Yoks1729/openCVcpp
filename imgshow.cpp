// cpp program to read and display the image using opencv. 
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;
// declaraing global variables(so that can be used further in any of the function). 
// Mat-The Basic Image Container.
Mat img;
// the header name which you want to display on the top of image widow.
char windowname[50] = "IMAGE";

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
 // show our image inside it
    imshow (windowname,img);
 // the int value inside wait key is time in milliseconds the program waits.
    waitKey (300);
    char k;
    cout<< "Press 'q' to EXIT" << endl;
    cin>> k;
    if (k=='q')
    {
    // to exit the program.    
        exit (0);
     }
}
