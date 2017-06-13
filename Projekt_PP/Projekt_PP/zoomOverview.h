#pragma once
//wczytanie zdjecia glownego do originalImage w oryginalnym rozmiarze
//negatyw tylko dla biezacego obrazu - usunac wyswietlanie go !
//aktualnie wyswietlane okno w zoomedImage

#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

cv::Mat originalImage, zoomedImage, overviewImage, overviewRectangleImage, negativeImage;

//GENERAL
int mousex, mousey;

//MAIN WINDOW
int mainWindowMaxHeight = 800;
int mainWindowMaxWidth = 1500;
double scaleFactor;
int moveAWSDvalue = 50;
//originalImage - position of overview middle on original screen - size is half
int originalImgCurrentXCenter;
int originalImgCurrentYCenter;
int originalImgCurrentWidthX;//half 
int originalImgCurrentHeightY;//half

//OVERVIEW
int imageOverviewHeight = 200;
bool overviewActive = false;
int numOfZooms = 0;
bool overviewDrawing = false;
//rectangle
//middle point in rectangle area - overviewRectangleXCoordinate
float ovRecXCenter, ovRecYCenter;
//length of rectangle area in coordinates from middle point outside (left/right , up/down)
float ovRecWidthX, ovRecHeightY;//half
//rectangle corner P0 left up , P1 right down
int px0, py0, px1, py1;


void updateOverviewWindow()
{
	overviewImage.copyTo(overviewRectangleImage);
	rectangle(overviewRectangleImage,
		cv::Point(px0, py0),
		cv::Point(px1, py1),
		cv::Scalar(0, 255, 0));
	imshow("OverviewWindow", overviewRectangleImage);
}

void updateOverviewRectangleSize(float halfWidth = ovRecWidthX, float halfHeight = ovRecHeightY) {

	ovRecWidthX = halfWidth;
	ovRecHeightY = halfHeight;
	px0 = (int)ovRecXCenter - ovRecWidthX;
	py0 = (int)ovRecYCenter - ovRecHeightY;
	px1 = (int)ovRecXCenter + ovRecWidthX - 1;
	py1 = (int)ovRecYCenter + ovRecHeightY - 1;

	//if rectangle corners out of the picture
	if (px1 > overviewImage.size().width) { px1 = overviewImage.size().width - 1; px0 = overviewImage.size().width - 2 * ovRecWidthX - 1; }
	if (py1 > overviewImage.size().height) { py1 = overviewImage.size().height - 1; py0 = overviewImage.size().height - 2 * ovRecHeightY - 1; }
	if (px0 < 0) { px0 = 0; px1 = ovRecWidthX * 2 - 1; }
	if (py0 < 0) { py0 = 0; py1 = ovRecHeightY * 2 - 1; }

	//update overview window
	updateOverviewWindow();
}

void updateOverviewRectangleCenter(float xC = ovRecXCenter, float yC = ovRecYCenter) {
	ovRecXCenter = xC;
	ovRecYCenter = yC;
	updateOverviewRectangleSize();
}

void updateZoomImage() {
	cv::Rect roi = cv::Rect(originalImgCurrentXCenter - originalImgCurrentWidthX, originalImgCurrentYCenter - originalImgCurrentHeightY, 2 * originalImgCurrentWidthX, 2 * originalImgCurrentHeightY);
	zoomedImage = originalImage(roi);
	resize(zoomedImage, zoomedImage, cv::Size(originalImage.size().width / scaleFactor, originalImage.size().height / scaleFactor), 0, 0, CV_INTER_AREA);
	imshow("ImageWindow", zoomedImage);
}

void updateZoomImage(cv::Mat img) {

	cv::resize(img, img, cv::Size(zoomedImage.size().width, zoomedImage.size().height), 0, 0, CV_INTER_AREA);
	img.copyTo(zoomedImage);
	imshow("ImageWindow", zoomedImage);
}

void updateMainWindowCenter(int centerX = originalImgCurrentXCenter, int centerY = originalImgCurrentYCenter) {
	originalImgCurrentXCenter = centerX;
	originalImgCurrentYCenter = centerY;

	if (centerX < originalImgCurrentWidthX)
		originalImgCurrentXCenter = originalImgCurrentWidthX;

	if (centerX > originalImage.size().width - originalImgCurrentWidthX)
		originalImgCurrentXCenter = originalImage.size().width - originalImgCurrentWidthX;

	if (centerY < originalImgCurrentHeightY)
		originalImgCurrentYCenter = originalImgCurrentHeightY;

	if (centerY > originalImage.size().height - originalImgCurrentHeightY)
		originalImgCurrentYCenter = originalImage.size().height - originalImgCurrentHeightY;

	updateZoomImage();

	if (overviewActive)
		updateOverviewRectangleCenter(originalImgCurrentXCenter* overviewImage.size().height / originalImage.size().height, originalImgCurrentYCenter * overviewImage.size().width / originalImage.size().width);
}

void updateMainWindowSize(int halfWidth, int halfHeight) {
	originalImgCurrentWidthX = halfWidth;
	originalImgCurrentHeightY = halfHeight;
	updateMainWindowCenter();
}

static void onMouseOverview(int event, int x, int y, int /*flags*/, void* /*param*/)
{
	if (overviewActive) {
		mousex = x;
		mousey = y;

		if (event == CV_EVENT_LBUTTONDOWN) {
			//jezeli chwyt w ramaie zdjecia z overview
			if ((x > px0) && (x < px1) && (y > py0) && (y < py1)) {
				overviewDrawing = true;
				std::cout << "DRAWING" << std::endl;
			}
		}
		else if (event == CV_EVENT_LBUTTONUP) {
			overviewDrawing = false;
		}

		if ((overviewDrawing == true) && (((mousex >= ovRecWidthX) && (mousex < overviewImage.size().width - ovRecWidthX) && (mousey >= ovRecHeightY) && (mousey < overviewImage.size().height - ovRecHeightY)))) {
			updateOverviewRectangleCenter(mousex, mousey);
			updateMainWindowCenter(ovRecXCenter * originalImage.size().height / overviewImage.size().height, ovRecYCenter * originalImage.size().width / overviewImage.size().width);
		}
	}
}


void initMainWindow(){
	//MAIN WINDOW
	cv::namedWindow("ImageWindow", 1);

	//resize original image to fit the main window
	int mainWindowWidth = 0;
	int mainWindowHeight = 0;
	float tempScaleFactor;
	int tempOriginalWidth = originalImage.size().width;
	int tempOriginalHeight = originalImage.size().height;

	if ((tempOriginalHeight > mainWindowMaxHeight) && (tempOriginalWidth > mainWindowMaxWidth)) {
		//too height, too width
		scaleFactor = (float)(tempOriginalHeight) / (float)(mainWindowMaxHeight);
		tempScaleFactor = (float)(tempOriginalWidth) / (float)(mainWindowMaxWidth);
		if (scaleFactor > tempScaleFactor) {
			//more height than width
			mainWindowHeight = mainWindowMaxHeight;
			mainWindowWidth = tempOriginalWidth / scaleFactor;
		}
		else {
			//more width than height
			scaleFactor = tempScaleFactor;
			mainWindowWidth = mainWindowMaxWidth;
			mainWindowHeight = tempOriginalHeight / scaleFactor;
		}
	}
	else if (tempOriginalHeight > mainWindowMaxHeight) {
		//too height
		scaleFactor = (float)(tempOriginalHeight) / (float)(mainWindowMaxHeight);
		mainWindowHeight = mainWindowMaxHeight;
		mainWindowWidth = tempOriginalWidth / scaleFactor;
	}
	else if (tempOriginalWidth > mainWindowMaxWidth) {
		//too width
		scaleFactor = (float)(tempOriginalWidth) / (float)(mainWindowMaxWidth);
		mainWindowWidth = mainWindowMaxWidth;
		mainWindowHeight = tempOriginalHeight / scaleFactor;
	}
	else {
		mainWindowWidth = tempOriginalWidth;
		mainWindowHeight = tempOriginalHeight;
	}

	cv::Rect roi = cv::Rect(0, 0, originalImage.size().width, originalImage.size().height);
	zoomedImage = originalImage(roi);
	resize(zoomedImage, zoomedImage, cv::Size(mainWindowWidth, mainWindowHeight), 0, 0, CV_INTER_AREA);
	imshow("ImageWindow", zoomedImage);

	originalImgCurrentXCenter = originalImage.size().width / 2;
	originalImgCurrentYCenter = originalImage.size().height / 2;
	originalImgCurrentWidthX = originalImage.size().width / 2;
	originalImgCurrentHeightY = originalImage.size().height / 2;
}

void initOverviewWindow() {
	//OVERVIEW WINDOW
	cv::namedWindow("OverviewWindow", cv::WINDOW_AUTOSIZE);
	cv::setMouseCallback("OverviewWindow", onMouseOverview, 0);
	cv::Rect roi = cv::Rect(0, 0, originalImage.size().width, originalImage.size().height);
	overviewImage = originalImage(roi);
	resize(overviewImage, overviewImage, cv::Size(originalImage.size().width * imageOverviewHeight / originalImage.size().height, imageOverviewHeight), 0, 0, CV_INTER_AREA);
	imshow("OverviewWindow", overviewImage);
	overviewImage.copyTo(overviewRectangleImage);

	if (numOfZooms == 0) {
		ovRecWidthX = overviewImage.size().width / 2;
		ovRecHeightY = overviewImage.size().height / 2;
	}
	else {
		ovRecWidthX = overviewImage.size().width / (numOfZooms + 1) / 2;
		ovRecHeightY = overviewImage.size().height / (numOfZooms + 1) / 2;
	}

	updateOverviewRectangleCenter(originalImgCurrentXCenter * overviewImage.size().width / originalImage.size().width, originalImgCurrentYCenter * overviewImage.size().height / originalImage.size().height);
}

void makeNegative() {
	cv::Mat new_image = cv::Mat::zeros(zoomedImage.size(), zoomedImage.type());
	cv::Mat sub_mat = cv::Mat(zoomedImage.rows, zoomedImage.cols, zoomedImage.type(), cv::Scalar(1, 1, 1)) * 255;
	subtract(sub_mat, zoomedImage, new_image);
	updateZoomImage(new_image);
}

void zoomIn(int x = originalImgCurrentXCenter, int y = originalImgCurrentYCenter)
{
	numOfZooms++;
	updateMainWindowSize(originalImgCurrentWidthX / 2, originalImgCurrentHeightY / 2);
	if (overviewActive) updateOverviewRectangleSize(ovRecWidthX / 2, ovRecHeightY / 2);
}

void zoomOut(int x = originalImgCurrentXCenter, int y = originalImgCurrentYCenter)
{
	if (numOfZooms > 0) {
		numOfZooms--;
		updateMainWindowSize(originalImgCurrentWidthX * 2, originalImgCurrentHeightY * 2);
		if (overviewActive) updateOverviewRectangleSize(ovRecWidthX * 2, ovRecHeightY * 2);
	}
	else if (numOfZooms == 0) {
		if (overviewActive) updateOverviewRectangleSize(overviewImage.size().width / 2, overviewImage.size().height / 2);
	}
}

