#include<opencv2/opencv.hpp>
#include<windows.h>
using namespace std;
using namespace cv;

int main()
{
	// 设置 要显示的图像路径
	string src = "C:\\Users\\huang\\Desktop\\test\\test.png";

	// 读取图像
	Mat lena_rgb = imread(src);

	//生成三个灰色的图像
	Mat lena_gray_avg = Mat::zeros(lena_rgb.size(), CV_8UC1);
	Mat lena_gray_weighted = Mat::zeros(lena_rgb.size(), CV_8UC1);
	Mat lena_gray_shift = Mat::zeros(lena_rgb.size(), CV_8UC1);

	//遍历每一个像素进行灰度化
	for (int i = 0; i < lena_rgb.rows; i++)
	{
		for (int j = 0; j < lena_rgb.cols; j++)
		{
			Vec3b tmp_px = lena_rgb.at<cv::Vec3b>(i, j);
			lena_gray_avg.at<uchar>(i, j) = (uchar)((tmp_px[0] + tmp_px[1] + tmp_px[2]) / 3);
			//lena_gray_weighted.at<uchar>(i, j) = (uchar)((0.299f * tmp_px[0] + 0.587f * tmp_px[1] + 0.114f * tmp_px[2]));
			//lena_gray_shift.at<uchar>(i, j) = (uchar)((38 * tmp_px[0] + 75 * tmp_px[1] + 15 * tmp_px[2]) >> 7);

		}
	}

	//显示图像
	namedWindow("原图", WINDOW_NORMAL);
	imshow("原图", lena_rgb);
	namedWindow("灰度", WINDOW_NORMAL);
	imshow("灰度", lena_gray_avg);
	
	waitKey(0);
	return 0;
}

