#include <iostream>
#include <opencv2/opencv.hpp>

static cv::Scalar randomColor(cv::RNG& rng);

int main(int argc, char** argv){
    cv::RNG rng(0xFFFFFFFF);
    int lineType = 8;
    int w = 614;
    cv::Point pt1, pt2;
    cv::Point org;
    cv::Mat img = cv::Mat::zeros(w, w, CV_8UC3);

    for(size_t i = 0; i < 5; i++){
        pt1.x = rng.uniform(100, 200);
        pt1.y = rng.uniform(100, 200);
        pt2.x = rng.uniform(500, 600);
        pt2.y = rng.uniform(600, 600);

        cv::line(img, pt1, pt2, randomColor(rng), rng.uniform(1, 10), lineType);
    }

    for(size_t i = 0; i < 4; i ++){
        org.x = rng.uniform(300, 400);
        org.y = rng.uniform(300, 400);
        cv::putText(img, "Test", org, cv::FONT_HERSHEY_COMPLEX, rng.uniform(0, 100)*0.05, randomColor(rng), rng.uniform(1, 10), lineType);
    }
    cv::imshow("Image", img);
    cv::waitKey(0);
    cv::destroyAllWindows();
}

static cv::Scalar randomColor(cv::RNG& rng){
    int icolor = (unsigned) rng;
    return cv::Scalar(icolor&255, (icolor>>8)&255, (icolor>>16)&255);
}