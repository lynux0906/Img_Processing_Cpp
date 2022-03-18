#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv){
    cv::Mat img;
    cv::Mat padded;
    img = cv::imread("/home/levanlinh/Pictures/Opencv/lena.jpg", 0);

    if(!img.data){
        std::cout << "Image not found";
        return -1;
    }

    int m = cv::getOptimalDFTSize(img.rows);//row la chieu cao cua anh
    int n = cv::getOptimalDFTSize(img.cols);//cols la chieu rong cua anh

    //std::cout << m << " " << n << std::endl;
    cv::copyMakeBorder(img, padded, 0, m - img.rows, 0, n - img.cols, cv::BORDER_CONSTANT, cv::Scalar::all(0));

    cv::Mat planes[] = {cv::Mat_<float>(padded), cv::Mat::zeros(padded.size(), CV_32F)};
    cv::Mat complexI;
    cv::merge(planes, 2, complexI);
    cv::dft(complexI, complexI);

    cv::split(complexI, planes);
    cv::magnitude(planes[0], planes[1], planes[0]);
    cv::Mat magI = planes[0];

    magI = magI(cv::Rect(0, 0, magI.cols & -2, magI.rows & -2));
    int cx = magI.cols/2;
    int cy = magI.rows/2;

    cv::Mat q0(magI, cv::Rect(0, 0, cx, cy));
    cv::Mat q1(magI, cv::Rect(cx, 0, cx, cy));
    cv::Mat q2(magI, cv::Rect(0, cy, cx, cy));
    cv::Mat q3(magI, cv::Rect(cx, cy, cx, cy));

    cv::Mat tmp;
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);

    q1.copyTo(tmp);
    q2.copyTo(q1);
    tmp.copyTo(q2);

    cv::normalize(magI, magI, 0, 1, cv::NORM_MINMAX);

    cv::imshow("Image", img);
    cv::imshow("spectrum magnitude", magI);
    cv::waitKey(0);
    cv::destroyAllWindows();  
    return 0;
}