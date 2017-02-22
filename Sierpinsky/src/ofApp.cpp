#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	line.NewClear();

	v1= { 200.0f , 650.0f , 0.0f };
	v2 = { 800.0f , 650.0f , 0.0f };
	v3 = { 500.0f , 100.0f , 0.0f };
	std::cout << "Porn is Good" << endl;
}

//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	/*ofColor color;
	color.r = 0;
	color.g = 255;
	color.b = 0;

	SetColor(ofColor::green);*/

	Gasket(v1, v2, v3, 5);
	//Triangle(v1, v2, v3);
	//int xc = ofGetWidth() / 2;
	//int yc = ofGetHeight() / 2;
	/*
	int x0 = 0, y0 = 0;
	
	//Circulo de Líneas
	for (float a = 0; a < 360; ++a)
	{
		int x1 = 300.0f * cos(a*PI / 180.0f);
		int y1 = 300.0f * sin(a*PI / 180.0f);
		
		line.midLine(xc+x0, yc+y0, (x1 + xc), (y1 + yc));
	}*/

	

	//Círculo con algoritmo
	//MoveTo(xc, yc);
	//Circle(cPos.x, cPos.y, 50);

	//MoveTo(360, 360);
	//SetColor(ofColor::green);
	//Circle(cPos.x, cPos.y, 50);
	
	//MoveTo(xc, yc);
	//Poly(xc, yc, 50, 3);
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
void ofApp::MoveTo(const int x, const int y)
{
	pixel._currentPosition.set(x, y);
}

void ofApp::LineTo(const int x, const int y)
{
	line.midLine(pixel._currentPosition.x, pixel._currentPosition.y, x, y);
	MoveTo(x, y);
}

void ofApp::Poly(const float x, const float y, const float r, const float sides)
{
	ofColor color;

	color.r = 0;
	color.g = 255;
	color.b = 0;

	float angle;
	int x1, y1;

	MoveTo(x+r, 0+y);

	float increment;
	increment = 360.0f / sides;
	increment = (increment*PI) / 180.0f;

	angle = increment;

	for (int i = 0; i < sides; ++i)
	{
		x1 = r*cos(angle);
		y1 = r*sin(angle);
		pixel.putpixel(x1+x, y1+y, color);
		angle += increment;
	}
}

void ofApp::SetColor(const ofColor & color)
{

}

void ofApp::Circle(const int x, const int y, const int r)
{
	ofColor color;
	
	color.r = 0;
	color.g = 255;
	color.b = 0;

	int xr = 0;
	int yr = r;

	float d = 1 - r;
	//si se suman los valores como variables, hace un cuadrado
	float E = 2 * xr + 3;
	float SE = 2 * xr -2* yr + 5;

	while (xr != yr)
	{	
		if (d <= 0)
		{
			d += 2*xr+3;
		}
		else
		{
			--yr;
			d += 2 * xr - 2 * yr + 5;
		}
		++xr;

		pixel.putpixel(xr + x, yr + y, color);
		pixel.putpixel(-xr + x, yr + y, color);
		pixel.putpixel(xr + x, -yr + y, color);
		pixel.putpixel(-xr + x, -yr + y, color);
		
		pixel.putpixel(yr + x, xr + y, color);
		pixel.putpixel(-yr + x, xr + y, color);
		pixel.putpixel(yr + x, -xr + y, color);
		pixel.putpixel(-yr + x, -xr + y, color);
		
	}
}

void ofApp::Triangle(const Vec3 a, const Vec3 b, const Vec3 c)
{
	MoveTo(a.x, a.y);
	LineTo(b.x, b.y);
	LineTo(c.x, c.y);
	LineTo(a.x, a.y);
}

void ofApp::Gasket(const Vec3 &a, const Vec3 &b, const Vec3 &c, const int& lvl)
{
	if (lvl == 0)
	{
		Triangle(a, b, c);
	}
	else
	{
		Vec3 ab = vec3.midPoint(a, b);
		Vec3 bc = vec3.midPoint(b, c);
		Vec3 ca = vec3.midPoint(c, a);

		Gasket(a, ab, ca, lvl - 1);
		Gasket(ab, b, bc, lvl - 1);
		Gasket(ca, bc, c, lvl - 1);
	}
}

/*
//Lines
void ofApp::Line(const int x0, const int y0, const int x1, const int y1) 
{
	Line01(x0, y0, x1, y1);
	//Line02(x0, y0, x1, y1);
	//Line03(x0, y0, x1, y1);
	Line04(x0, y0, x1, y1);
	//Line05(x0, y0, x1, y1);
	//Line06(x0, y0, x1, y1);
	//Line07(x0, y0, x1, y1);
	Line08(x0, y0, x1, y1);

}
void ofApp::Line01(const int x0, const int y0, const int x1, const int y1)
{
	int dy = y1 - y0;
	int dx = x1 - x0;

	int d = 2 * dy - dx;
	int NE = 2 * (dy - dx);
	int E = 2 * dy;

	int x = x0, y = y0;

	putpixel(x0, y0);
	//1
	
	while (x <= x1)
	{
		++x;
		if (d >= 0)
		{
			d += NE;
			++y;
		}
		else if (d < 0)
		{
			d += E;
		}

		putpixel(x, y);
		//putpixel(-x, y);
	}
	
}
void ofApp::Line02(const int x0, const int y0, const int x1, const int y1) {
	int dy = y1 - y0;
	int dx = x1 - x0;

	int d = 2 * dy - dx;
	int NE = 2 * (dy - dx);
	int E = 2 * dy;

	int x = x0, y = y0;

	putpixel(x0, y0);

	while (y <= y1)
	{
		++y;
		if (d <= 0)
		{
			d += NE;
			++x;
		}
		else if (d>0)
		{
			d += E;
		}

		putpixel(x, y);
		//putpixel(-x, y);
	}
}
void ofApp::Line03(const int x0, const int y0, const int x1, const int y1) {
	int dy = y1 - y0;
	int dx = x1 - x0;

	int d = 2 * dy - dx;
	int NE = 2 * (dy - dx);
	int E = 2 * dy;

	int x = x0, y = y0;

	putpixel(x0, y0);

	while (x >= x1)
	{
		--x;
		if (d <= 0)
		{
			d += NE;
			++y;
		}
		else if (d > 0)
		{
			d += E;

		}

		putpixel(x, y);
		//putpixel(-x, y);
	}
}
void ofApp::Line04(const int x0, const int y0, const int x1, const int y1) {
	int dy = y0 - y1;
	int dx = x0 - x1;

	int d = 2 * dy - dx;
	int NE = 2 * (dy - dx);
	int E = 2 * dy;

	int x = x1, y = y1;

	putpixel(x1, y1);

	while (x <= x0)
	{
		++x;
		if (d >= 0)
		{
			d += NE;
			++y;
		}
		else if (d<0)
		{
			d += E;
		}

		putpixel(x, y);
		//putpixel(-x, y);
	}
}
void ofApp::Line05(const int x0, const int y0, const int x1, const int y1) 
{
	int dy = y0 - y1;
	int dx = x0 - x1;

	int d = 2 * dy - dx;
	int NE = 2 * (dy - dx);
	int E = 2 * dy;

	int x = x1, y = y1;

	putpixel(x1, y1);
	
	while (x <= x0)
	{
		++x;
		if (d >= 0)
		{
			d += NE;
			++y;
		}
		else if (d<0)
		{
			d += E;
		}

		putpixel(x, y);
		//putpixel(-x, y);
	}
}
void ofApp::Line06(const int x0, const int y0, const int x1, const int y1) {
	int dy = y1 - y0;
	int dx = x1 - x0;

	int d = 2 * dy - dx;
	int NE = 2 * (dy - dx);
	int E = 2 * dy;

	int x = x0, y = y0;

	putpixel(x0, y0);

	while (x >= x1)
	{
		--x;
		if (d <= 0)
		{
			d += NE;
			++y;
		}
		else if (d > 0)
		{
			d += E;

		}

		putpixel(x, y);
		//putpixel(-x, y);
	}
}
void ofApp::Line07(const int x0, const int y0, const int x1, const int y1) {
	int dy = y1 - y0;
	int dx = x1 - x0;

	int d = 2 * dy - dx;
	int NE = 2 * (dy - dx);
	int E = 2 * dy;

	int x = x0, y = y0;

	putpixel(x0, y0);

	while (y <= y1)
	{
		++y;
		if (d <= 0)
		{
			d += NE;
			++x;
		}
		else if (d>0)
		{
			d += E;
		}

		putpixel(x, y);
		//putpixel(-x, y);
	}
}
void ofApp::Line08(const int x0, const int y0, const int x1, const int y1) {
	int dy = y1 - y0;
	int dx = x1 - x0;

	int d = 2 * dy - dx;
	int NE = 2 * (dy - dx);
	int E = 2 * dy;

	int x = x0, y = y0;

	putpixel(x0, y0);

	while (x <= x1)
	{
		++x;
		if (d >= 0)
		{
			d += NE;
			--y;
		}
		else if (d<0)
		{
			d += E;
		}

		putpixel(x, y);
		//putpixel(-x, y);
	}
}
*/
