
#include "stdafx.h"
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <stdio.h>
#include <opencv/cv.h>
using namespace cv;

int main(int argc, char *argv[])
{
	CvCapture* capture = cvCaptureFromAVI("./video_avi/store_224*224/testvideo_3_1.avi");
	int i = 0;
	IplImage* img = 0;
	char image_name[25];
	//const char address ="/home/linhan/huang/test/restore"
	cvNamedWindow( "vivi");
	//读取和显示
	while(1)
	{
		img = cvQueryFrame(capture); //获取一帧图片
		if(img == NULL)
		break;

		cvShowImage( "vivi", img ); //将其显示
		//char key = cvWaitKey(20);
		cvWaitKey(20);
		//eidt string
		sprintf(image_name, "%s%d%s", "/home/linhan/huang/project/test/restore/image-shi-224*224/", ++i, ".jpg");//保存的图片名
		cvSaveImage( image_name, img); //保存一帧图片
		//cvSaveImage(address, img ,0);
	}

	cvReleaseCapture(&capture);
	cvDestroyWindow("vivi");

	return 0;
} 
