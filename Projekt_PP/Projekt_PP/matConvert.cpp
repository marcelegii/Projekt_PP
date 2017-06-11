#include "matConvert.h"

/*
	Na razie nie korzystaæ !
*/
void iplimage_from_cvmat(CvMat* input, IplImage * output)
{
	int x, y;
	for (x = 0; x < output->width; x++) {
		for (y = 0; y < output->height; y++) {
			// note: CvMat is indexed (row, column) but IplImage is indexed (x,y)
			// so the indexes must be interchanged!
			cvSetReal2D(output, x, y, CV_MAT_ELEM(*input, uchar, y, x));
		}
	}
}