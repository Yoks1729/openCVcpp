#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<iostream>

using namespace std;
using namespace cv;
 
Mat img;
char windowname[50]="IMAGE";

int main()
{
    string s;
    cout<<"Enter the path of Image which you want to display.";
    cin>>s;
    img =imread(s);
    namedWindow(windowname,WINDOW_AUTOSIZE);
    imshow(windowname,img);
    waitKey(300);
    char k;

    cout<<"Press 'q' to EXIT"<<endl;
    cin>>k;
    if(k=='q')
        {
        exit(0);
        }
}