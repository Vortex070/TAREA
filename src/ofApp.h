#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void putpixel(const int& x, const int& y, const ofColor& color);
		void clear(const ofColor& color);
		void Line(const int x0, const int y0, const int x1, const int y1, const ofColor& color);
		void Circle( int x,  int y, const int r, const ofColor& color);


		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
private:
		ofImage _img;
		void FASTputpixel(const int& x, const int& y, const ofColor& color);
		
};
