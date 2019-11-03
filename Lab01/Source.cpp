﻿#include<opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>

using namespace std;
using namespace cv;
int main()
{
	//// Load ảnh
	//Mat src = imread("lena.jpg");

	//// Chuyển về thang độ xám

	//// Tạo ảnh mới sử dụng toán tử Sobel abs(gx) trên ảnh cũ xuất ảnh


	//// Tạo ảnh mới sử dụng toán tử Sobel abs(gy) trên ảnh cũ xuất ảnh

	//// Tạo ảnh mới abs(gx) + abs(gy) trên ảnh gx, gy và xuất ảnh.

	//int nCols = src.cols, nRows = src.rows;

	//int nChannels = src.channels();

	//for (int y = 0; y < nRows; y++) {
	//	uchar* pRow = src.ptr<uchar>(y);

	//	for (int x = 0; x < nCols; x++, pRow += nChannels)
	//	{
	//		for (int z = 0; z < nChannels; z++);
	//			
	//	}
	//}

	//// Display
	//namedWindow("calcHist Demo");
	//imshow("calcHist Demo", src);

	//waitKey(0);
	//return 0;

	Mat src, dst;

	/// Load image
	src = imread("lena.jpg", 1);

	if (!src.data)
	{
		return -1;
	}

	/// Separate the image in 3 places ( B, G and R )
	vector<Mat> bgr_planes;
	split(src, bgr_planes);

	/// Establish the number of bins
	int histSize = 256;

	/// Set the ranges ( for B,G,R) )
	float range[] = { 0, 256 };
	
	const float* histRange = { range };

	bool uniform = true; bool accumulate = false;

	//Mat b_hist;
	// Mat b_hist, g_hist, r_hist;
	Mat b_hist(256, 1, CV_32FC1, Scalar(0));

	// Chon kenh mau b_hist
	for (int y = 0; y < bgr_planes[0].rows; y++)
	{
		uchar* pRow = bgr_planes[0].ptr<uchar>(y);
		for (int x = 0; x < bgr_planes[0].cols; x++)
		{
			int index = int(pRow[x]);
			b_hist.ptr<float>(index)[0]++;
		}
	}

	// cout << endl << g_hist;
	// cout << g_hist.cols << " " << g_hist.rows << " " << g_hist.channels() << endl;
	/// Compute the histograms:
	//calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);
	//calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
	//calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);

	//cout << b_hist.cols << " " << b_hist.rows << " " << b_hist.channels() << endl;
	
	
	// Your code above

	//waitKey(0);

	// Draw the histograms for B, G and R
	int hist_w = 512; int hist_h = 400;
	int bin_w = cvRound((double)hist_w / histSize);

	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));

	/// Normalize the result to [ 0, histImage.rows ]
	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	//normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	//normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

	///// Draw for each channel
	for (int i = 1; i < histSize; i++)
	{
		line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
			Point(bin_w * (i), hist_h - cvRound(b_hist.at<float>(i))),
			Scalar(255, 0, 0), 2, 8, 0);
		//line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
		//	Point(bin_w * (i), hist_h - cvRound(g_hist.at<float>(i))),
		//	Scalar(0, 255, 0), 2, 8, 0);
		//line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
		//	Point(bin_w * (i), hist_h - cvRound(r_hist.at<float>(i))),
		//	Scalar(0, 0, 255), 2, 8, 0);
	}

	/// Display
	namedWindow("calcHist Demo");
	imshow("calcHist Demo", histImage);

	waitKey(0);

	return 0;
}
