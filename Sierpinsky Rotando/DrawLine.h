#pragma once
#include "PutPixel.h"
class DrawLine {
public:

	PutPixel pixel;
	
	void NewClear();

	void midLine(int x0, int y0, int x1, int y1);

	//PutPixel pixel;

	int dx, dy, y, x;
	int dOld;
	//void drawLine(int x1, int y1, int x2, int y2);


};