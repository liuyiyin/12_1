// 12_1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{
	VideoCapture cap(0);

	if (!cap.isOpened())
	{
		std::cout << "不能打开视频文件" << std::endl;
		return-1;
	}

    int cnt = 0;
	cv::Mat frame;
	cv::Mat bgMat;
	cv::Mat subMat;
	cv::Mat bny_subMat;	

	while (1) {
			
		cap >> frame;
		cvtColor(frame, frame, COLOR_BGR2GRAY);

		if (cnt == 0) {
			frame.copyTo(bgMat);
		}

		else {
			absdiff(frame, bgMat, subMat);
			threshold(subMat, bny_subMat, 50, 255, CV_THRESH_BINARY);
			imshow("b_subMat", bny_subMat);
			imshow("frame", frame);
			waitKey(30);
		}
		cnt++;	
	}
    return 0;
}

