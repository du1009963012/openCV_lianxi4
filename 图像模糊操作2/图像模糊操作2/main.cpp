#include <opencv2/opencv.hpp>
#include <iostream>
#include <Windows.h>
using namespace std;
using namespace cv;
class blur_fouction {
public:
	void avg_blur(Mat &img);
	void gassius_blur(Mat &img);
	void mid_blur(Mat &img);
	void double_blur(Mat &img);
};
void blur_fouction::avg_blur(Mat &img){
	Mat avg_src(img.size(),img.type());
	blur(img, avg_src, Size(3, 3));
	imshow("avg_blur",avg_src);
}
void blur_fouction::double_blur(Mat &img){
	Mat double_src(img.size(),img.type());
	bilateralFilter(img,double_src,128,0,0);
	imshow("bilateralFilter",double_src);
}
void blur_fouction::gassius_blur(Mat &img) {
	Mat gassius_src(img.size(),img.type());
	GaussianBlur(img,gassius_src,Size(5,5),0);
	imshow("gassius_blur",gassius_src);

}
void blur_fouction::mid_blur(Mat &img) {
	Mat mide_src(img.size(),img.type());
	medianBlur(img,mide_src,3);
	imshow("mediaBlur",mide_src);
}

int main(int argc,char** argv) {
	Mat src,src1;
	blur_fouction a;
	src = imread("G:/picture/pic/25.jpg");
	if (!src.data) {
		cout << "ÎÄ¼þÎª¿Õ£¡";
		return -1;
		
	}

	resize(src,src,src.size()/8);
	src1=src.clone();
	RNG rng(16);
		
	for (int i = 0; i < 500; i++) {
		int hight = rng.uniform(0, src.rows), wight = rng.uniform(0,src.cols);
		src1.at<Vec3b>(hight, wight)[0] = 255;
		src1.at<Vec3b>(hight, wight)[1] = 255;
		src1.at<Vec3b>(hight, wight)[2] = 255;
		/*cout << "gaussian:"<<rng.gaussian(10)<<"\t";
		cout << "next:" << rng.next()<<"\t";
		cout << "uniform" << rng.uniform(0,256)<<"\n";*/
	}
	namedWindow("src",CV_WINDOW_AUTOSIZE);
	imshow("src",src);
	imshow("src1",src1);
	a.avg_blur(src1);
	a.double_blur(src1);
	a.gassius_blur(src1);
	a.mid_blur(src1);
	waitKey(0);
	return 0;
}