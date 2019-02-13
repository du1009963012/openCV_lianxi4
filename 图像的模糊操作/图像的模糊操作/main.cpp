#include <opencv2\opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main(int argc,char** argv) {
	Mat src,blur_img,gaussian_blur;
	src = imread("G:/picture/pic/id=01.jpg");
	if (!src.data) {
		cout << "ÎÄ¼þÎª¿Õ£¡";
		return 0;
	}
	resize(src,src,src.size()/8);
	blur(src,blur_img,Size(9,9));
	GaussianBlur(src,gaussian_blur,Size(9,9));
	namedWindow("src",CV_WINDOW_AUTOSIZE);
	imshow("src",src);
	imshow("blur_img",blur_img);
	imshow("gaussian_blur",gaussian_blur);
	waitKey(0);
	return 0;
}