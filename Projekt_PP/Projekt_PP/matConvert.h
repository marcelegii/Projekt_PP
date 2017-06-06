#pragma once
#include <opencv2\core.hpp>
#include <opencv2\imgcodecs.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\opencv.hpp>
#include <Windows.h>
#include <iostream>
#include <string>

/*
	Na razie nie korzystaæ !
*/
void iplimage_from_cvmat(CvMat* input, IplImage * output);