#pragma once
#include "ofMain.h"
#include "vec3.h"
class PutPixel {
public:

	void clear(const ofColor& color);

	void update();
	void draw();

	void putpixel(const int& x, const int& y, const ofColor& color);

	

//private:
	ofImage _img;
	ofColor _currentColor;
	ofVec2f _currentPosition;
	void FASTputpixel(const int& x, const int& y, const ofColor& color);

};