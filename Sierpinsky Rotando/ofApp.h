#pragma once
//#include "vec3.h"
//#include "PutPixel.h"
#include "DrawLine.h"
#include <vector>
#include "Matrix3.h"
#include "Vec4.h"

class ofApp : public ofBaseApp{
private:
	Vec3 _coords;

	public:
		//ofVec2f cPos;
		ofColor currentColor;

		Vec3 vec3;

		std::vector<Vec3> vects;
		std::vector<Vec3> rot;

		Vec3 v1, v2, v3,cen, posC, negC;

		Vec4 f1, f2, f3, f4, f5, f6;
		Vec4 r1, r2, r3, r4, r5, r6;
		Vec4 b1, b2, b3, b4, b5, b6;
		Vec4 l1, l2, l3, l4, l5, l6;
		Vec4 t1, t2, t3, t4, t5, t6;
		Vec4 bo1, bo2, bo3, bo4, bo5, bo6;
		float angle;

		PutPixel pixel;
		DrawLine line;

		void setup();
		void update();
		void draw();

		void MoveTo(const int x, const int y);
		void LineTo(const int x, const int y);
		void Poly(const float x, const float y, const float r, const float sides);
		
		void SetColor(const ofColor& color);

		//Vec3 Gasket(const Vec3 &a, const Vec3 &b, const Vec3 &c, const int& lvl);
		void Gasket(const Vec3 &a, const Vec3 &b, const Vec3 &c, const int& lvl);

		//void putpixel(const int& x, const int& y);
		//void clear(const ofColor& color);
		void Circle(const int x,const int y, const int r);
		void Triangle(const Vec3 a, const Vec3 b, const Vec3 c);
		void Triangle2(const Vec4 a, const Vec4 b, const Vec4 c);
		void Cube();

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
