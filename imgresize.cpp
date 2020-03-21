#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>

using namespace std;
using namespace cv;

Mat img;
char windowname[50]="Image";

void imgresize()
{
    double w,h;
    Size s=img.size();
    cout<<"Resize Image."<<endl;
    cout<<"Width: ";
    cin>>w;
    cout<<"Height: ";
    cin>>h;
    if(w==0)
    {
        h=h/s.height;
        w=h;
    }
    else if(h==0)
    {
        w=w/s.width;
        h=w;
    }
    else if(w==0 && h==0)
    {
        h=h;
        w=w;
    }
    else
    {
        w=w/s.width;
        h=h/s.height;
    }
    resize(img,img,Size(),w,h);
    imshow(windowname,img);
    waitKey(500);
}
int main()
{
    string s;
    cout<<"Enter the path of Image which you want to display.";
    cin>>s;
    img=imread(s);
    namedWindow(windowname,WINDOW_AUTOSIZE);
    imshow(windowname,img);
    waitKey(300);
    char key;
    cout<<"Press any key amd enter to proceed "<<endl;
    cin>>key;
    while(key!='q')
    {

    cout<<"Enter 'r' to RESIZE and 'e' to EXIT"<<endl ;
    cin>>key;

        switch(key)
        {
            case 'r':
            imgresize();
            break;
            case 'e':
            exit(0);
            break;
            default:
            cout<<"Please enter a valid key"<<endl;
            break;
        }
    }
    exit(0);
}




















