#pragma once
//#include "vec3.h"
//#include "PutPixel.h"
#include "DrawLine.h"

class ofApp : public ofBaseApp{
private:
	Vec3 _coords;

	public:
		//ofVec2f cPos;
		ofColor currentColor;

		Vec3 vec3;

		Vec3 v1, v2, v3;

		PutPixel pixel;
		DrawLine line;

		void setup();
		void update();
		void draw();

		void MoveTo(const int x, const int y);
		void LineTo(const int x, const int y);
		void Poly(const float x, const float y, const float r, const float sides);
		void SetCurrentPosition(const int x, const int y);
		void SetColor(const ofColor& color);

		void Gasket(const Vec3 &a, const Vec3 &b, const Vec3 &c, const int& lvl);
		//void Gasket(const Vec3 &a, const Vec3 &b, const Vec3 &c, const int& lvl);

		//void putpixel(const int& x, const int& y);
		//void clear(const ofColor& color);
		void Circle(const int x,const int y, const int r);
		void Triangle(const Vec3 a, const Vec3 b, const Vec3 c);

		/*void Line(const int x0, const int y0, const int x1, const int y1);
		void Line01(const int x0, const int y0, const int x1, const int y1);
		void Line02(const int x0, const int y0, const int x1, const int y1);
		void Line03(const int x0, const int y0, const int x1, const int y1);
		void Line04(const int x0, const int y0, const int x1, const int y1);
		void Line05(const int x0, const int y0, const int x1, const int y1);
		void Line06(const int x0, const int y0, const int x1, const int y1);
		void Line07(const int x0, const int y0, const int x1, const int y1);
		void Line08(const int x0, const int y0, const int x1, const int y1);

		void midLine(int x0, int y0, int x1, int y1);*/



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
		
};
