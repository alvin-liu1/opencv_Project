#include<opencv2/opencv.hpp>
#include<windows.h>
using namespace std;
using namespace cv;

int main()
{
	// ���� Ҫ��ʾ��ͼ��·��
	string src = "C:\\Users\\huang\\Desktop\\test\\test.png";

	// ��ȡͼ��
	Mat lena_rgb = imread(src);

	//����������ɫ��ͼ��
	Mat lena_gray_avg = Mat::zeros(lena_rgb.size(), CV_8UC1);
	Mat lena_gray_weighted = Mat::zeros(lena_rgb.size(), CV_8UC1);
	Mat lena_gray_shift = Mat::zeros(lena_rgb.size(), CV_8UC1);

	//����ÿһ�����ؽ��лҶȻ�
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

	//��ʾͼ��
	namedWindow("ԭͼ", WINDOW_NORMAL);
	imshow("ԭͼ", lena_rgb);
	namedWindow("�Ҷ�", WINDOW_NORMAL);
	imshow("�Ҷ�", lena_gray_avg);
	
	waitKey(0);
	return 0;
}

