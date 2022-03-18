#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv){
	int w = 614;

	//Windows names
	char atom_window[] = "Drawing 1: Atom";
	char rook_window[] = "Drawing 2: Rook";

	//Create black images
	cv::Mat atom_image = cv::Mat::zeros(w, w, CV_8UC3);
	cv::Mat rook_image = cv::Mat::zeros(w, w, CV_8UC3);

	//Draw Circle
	cv::circle(atom_image, cv::Point(w/2, w/2), 5, cv::Scalar(0, 0, 255), -1);

	//Draw ellipses
	cv::ellipse(atom_image, cv::Point(w/2, w/2), cv::Size(50, 90), 0, 0, 360, cv::Scalar(0, 255, 0), 1);
	cv::ellipse(atom_image, cv::Point(w/2, w/2), cv::Size(50, 90), 30, 0, 360, cv::Scalar(0, 255, 0), 1);
	cv::ellipse(atom_image, cv::Point(w/2, w/2), cv::Size(50, 90), 60, 0, 360, cv::Scalar(0, 255, 0), 1);
	cv::ellipse(atom_image, cv::Point(w/2, w/2), cv::Size(50, 90), 90, 0, 360, cv::Scalar(0, 255, 0), 1);
	cv::ellipse(atom_image, cv::Point(w/2, w/2), cv::Size(50, 90), 120, 0, 360, cv::Scalar(0, 255, 0), 1);
	cv::ellipse(atom_image, cv::Point(w/2, w/2), cv::Size(50, 90), 150, 0, 360, cv::Scalar(0, 255, 0), 1);


	//danh sach cac diem
	cv::Point rook_points[1][20];
	rook_points[0][0] = cv::Point( w/4.0, 7*w/8.0 );
	rook_points[0][1] = cv::Point( 3*w/4.0, 7*w/8.0 );
	rook_points[0][2] = cv::Point( 3*w/4.0, 13*w/16.0 );
	rook_points[0][3] = cv::Point( 11*w/16.0, 13*w/16.0 );
	rook_points[0][4] = cv::Point( 19*w/32.0, 3*w/8.0 );
	rook_points[0][5] = cv::Point( 3*w/4.0, 3*w/8.0 );
	rook_points[0][6] = cv::Point( 3*w/4.0, w/8.0 );
	rook_points[0][7] = cv::Point( 26*w/40.0, w/8.0 );
	rook_points[0][8] = cv::Point( 26*w/40.0, w/4.0 );
	rook_points[0][9] = cv::Point( 22*w/40.0, w/4.0 );
	rook_points[0][10] = cv::Point( 22*w/40.0, w/8.0 );
	rook_points[0][11] = cv::Point( 18*w/40.0, w/8.0 );
	rook_points[0][12] = cv::Point( 18*w/40.0, w/4.0 );
	rook_points[0][13] = cv::Point( 14*w/40.0, w/4.0 );
	rook_points[0][14] = cv::Point( 14*w/40.0, w/8.0 );
	rook_points[0][15] = cv::Point( w/4.0, w/8.0 );
	rook_points[0][16] = cv::Point( w/4.0, 3*w/8.0 );
	rook_points[0][17] = cv::Point( 13*w/32.0, 3*w/8.0 );
	rook_points[0][18] = cv::Point( 5*w/16.0, 13*w/16.0 );
	rook_points[0][19] = cv::Point( w/4.0, 13*w/16.0) ;

	const cv::Point* ppt[1] = { rook_points[0] };
	int npt[] = { 20 };

	cv::fillPoly(rook_image, ppt, npt, 1, cv::Scalar(0, 255, 0), 8);
	cv::rectangle(rook_image, cv::Point(0, 7*w/8.0), cv::Point(w, w), cv::Scalar(255, 255, 0), -1, 8);
	cv::line(rook_image, cv::Point(0, 7.5*w/8.0), cv::Point(w, 7.5*w/8.0), cv::Scalar(0, 255, 255), 2);
	cv::line(rook_image, cv::Point(w/5.0, 7.0*w/8.0), cv::Point(w/5.0, w), cv::Scalar(0, 0, 0), 2);
	cv::line(rook_image, cv::Point(2.0*w/5.0, 7.0*w/8.0), cv::Point(2.0*w/5.0, w), cv::Scalar(0, 0, 0), 2);
	cv::line(rook_image, cv::Point(3.0*w/5.0, 7.0*w/8.0), cv::Point(3.0*w/5.0, w), cv::Scalar(0, 0, 0), 2);
	cv::line(rook_image, cv::Point(4.0*w/5.0, 7.0*w/8.0), cv::Point(4.0*w/5.0, w), cv::Scalar(0, 0, 0), 2);

	cv::imshow(atom_window, atom_image);
	cv::imshow(rook_window, rook_image);

	cv::waitKey(0);
	cv::destroyAllWindows();
	return 0;
}
