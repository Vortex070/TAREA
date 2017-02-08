#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	_img.allocate(1024, 768, ofImageType::OF_IMAGE_COLOR_ALPHA);
	clear(ofColor::black);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	int xc = ofGetWidth() / 2;
	int yc = ofGetHeight() / 2;

	int x0 = 0, y0 = 0;
	
	int xf, yf;

	xf = (x0 + xc);
	yf = (y0 + yc);
	//Circulo de Líneas
	for (float a = 0; a < 360; ++a)
	{
		int x1 = 50.0f * cos(a*PI / 180.0f);
		int y1 = 50.0f * sin(a*PI / 180.0f);
		
		Line(xf, yf, (x1 + xc), (y1 + yc), ofColor::green);
		//putpixel(x0 + xc, y0 + yc, ofColor::green);
		//putpixel(x1 + xc, y1 + yc, ofColor::green);
		
	}

	//Círculo con algoritmo
	//Circle(0, 0, 50,ofColor::green);
		
	//Line(xc, yc, xc + 200, yc + 100, ofColor::red);

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
void ofApp::putpixel(const int& x, const int& y, const ofColor& color)
{
	_img.setColor(x, y, color);	
	_img.update();
	_img.draw(ofPoint(0, 0, 0));
}

void ofApp::FASTputpixel(const int& x, const int& y, const ofColor& color)
{
	_img.setColor(x, y, color);
}

void ofApp::clear(const ofColor& color)
{
	for (int y = 0; y < 768; ++y)
		for (int x = 0; x < 1024; ++x)
			FASTputpixel(x, y, color);

	_img.update();
	_img.draw(ofPoint(0, 0, 0));
}
//Circulo de Líneas
void ofApp::Line(const int x0, const int y0, const int x1, const int y1, const ofColor& color)
{
	int dy = y1 - y0;
	int dx = x1 - x0;

	int d = 2 * dy - dx;
	int NE = 2 * (dy - dx);
	int E = 2 * dy;

	int x = x0, y = y0;

	putpixel(x0, y0,color);

	while (x <= x1)
	{
		++x;
		if (d >= 0)
		{
			d += NE;
			++y;
		}
		else if(d<0)
		{
			d += E;
		}
			
		putpixel(x, y, color);
		putpixel(-x, y, color);
	}
	while (x >= x1)
	{
		--x;
		if (d <= 0)
		{
			d += NE;
			--y;
		}
		else if (d>0)
		{
			d += E;
			
		}

		putpixel(x, y, color);
		putpixel(-x, y, color);
	}

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

		putpixel(x, y, color);
		putpixel(-x, y, color);
	}
	while (y >= y1)
	{
		--y;
		if (d >= 0)
		{
			d += NE;
			--x;

		}
		else if (d>0)
		{
			d += E;

		}

		putpixel(x, y, color);
		putpixel(-x, y, color);
	}
	
	

	//std::cout << endl;
}

void ofApp::Circle(const int x, const int y, const int r,const ofColor& color)
{
	int d = 1 - r;
	int xr = x, yr = y;
	xr = 0;
	yr = r;
	int E = (2 * xr) + 3;
	int SE = (2 * xr) - (2 * yr) + 5;
	putpixel(xr, yr, color);
	while (xr != yr)
	{
		if (d <= 0)
		{
			d += E;
		}
		else
		{
			d += SE; 
			--yr;
		}
		++xr;
		putpixel(xr, yr, color);
		//putpixel(-x0, yr, color);
		//putpixel(-x0, -yr, color);
		//putpixel(x0, -yr, color);

		/*putpixel(y, x, color);
		putpixel(-y, x, color);
		putpixel(y, -x, color);
		putpixel(-y, -x, color);*/
	}
}