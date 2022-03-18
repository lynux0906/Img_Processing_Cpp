#include<opencv2/highgui.hpp>
#include<iostream>

int main(int argc, char** argv){
	cv::Mat image;
	image = cv::imread(argv[1], -1);

	if(!image.data){
		std::cout<<"Image not found"<<std::endl;
		return -1;
	}

	cv::imshow("Image", image);
	cv::waitKey(0);
	return 0;
}
