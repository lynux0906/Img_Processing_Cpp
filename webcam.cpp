#include<opencv2/highgui.hpp>
#include<iostream>

int main(int argc, char** argv){
	cv::namedWindow("Webcam", cv::WINDOW_AUTOSIZE);
	//cv::VideoCapture cap("/home/levanlinh/Videos/eye_recording.mp4");
	cv::VideoCapture cap(0);
	if(!cap.isOpened()){
		std::cout<<"Out of camera" <<std::endl;
		return -1;
	}

	cv::Mat frame;
	while(1){
		cap >> frame;
		cv::imshow("Webcam", frame);
		char c = (char)cv::waitKey(25);
		if(c == 27)
			break;
	}
cap.release();
cv::destroyAllWindows();
return 0;
}
