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
	/*for (float a = 0; a < 360; ++a)
	{
		int x1 = 50.0f * cos(a*PI / 180.0f);
		int y1 = 50.0f * sin(a*PI / 180.0f);
		
		Line(xf, yf, (x1 + xc), (y1 + yc), ofColor::green);
		putpixel(x0 + xc, y0 + yc, ofColor::green);
		putpixel(x1 + xc, y1 + yc, ofColor::green);
	
	}*/

	//Círculo con algoritmo
	//Circle(xf, yf, 50, ofColor::green);
		
	//Line(xc, yc, xc + 200, yc + 100, ofColor::red);
	Poly(xf, yf, 50, 5);
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

void ofApp::MoveTo(const int x, const int y)
{
	_currentPosition.set(x, y);
}

void ofApp::LineTo(const int x, const int y)
{
	midLine(_currentPosition.x, _currentPosition.y, x, y);
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

	MoveTo(x + r, 0 + y);

	float increment;
	increment = 360.0f / sides;
	increment = (increment*PI) / 180.0f;

	angle = increment;

	for (int i = 0; i < sides; ++i)
	{
		x1 = r*cos(angle);
		y1 = r*sin(angle);
		LineTo(x1 + x, y1 + y);
		//putpixel(x1 + x, y1 + y, color);
		angle += increment;
	}
}

//Circulo de Líneas
void ofApp::midLine(int x0, int y0, int x1, int y1)
{
	ofColor color;
	color.r = 0;
	color.g = 255;
	color.b = 0;
	//color.a = 255;

	int dx = (x1 - x0);
	int dy = (y1 - y0);
	int d = 0;
	int DeltaNE = dy;
	int DeltaE = (dy - dx);

	int x = x0;
	int y = y0;

	//cuadrante 4
	if (y1 >= y0 && x1 >= x0) {

		// octante 8
		if (dx > dy) {

			for (int x = x0; x <= x1; x++) {
				putpixel(x, y, color);
				if (d > 0) {
					d = d + DeltaE;
					y++;
				}
				else d = d + DeltaNE;
			}
		}
		// octante 7
		else if (dx <= dy) {
			for (int y = y0; y <= y1; y++) {
				putpixel(x, y, color);
				if (d > 0) {
					d = d + dx - dy;
					x++;
				}
				else d = d + dx;
			}
		}
	}

	//cuadrante 3
	else if (y1 >= y0 && x1 < x0) {

		// octante 6
		if (dx > dy*-1) {

			for (int y = y0; y <= y1; y++) {
				putpixel(x, y, color);
				if (d < 0) {
					d = d + dx - dy*-1;
					x--;
				}
				else d = d + dx;
			}
		}
		// octante 5
		else if (dx <= dy*-1) {
			for (int x = x0; x >= x1; x--) {
				putpixel(x, y, color);
				if (d < 0) {
					d = d - dx - dy;
					y++;
				}
				else d = d - dy;
			}
		}
	}


	//cuadrante 2
	else if (y1 < y0 && x1 <= x0) {

		// octante 4
		if (dx < dy) {

			for (int x = x0; x >= x1; x--) {
				putpixel(x, y, color);
				if (d < 0) {
					d = d + dy - dx;
					y--;
				}
				else d = d + DeltaNE;
			}
		}
		// octante 3
		else if (dx >= dy) {
			for (int y = y0; y >= y1; y--) {
				putpixel(x, y, color);
				if (d < 0) {
					d = d + dx - dy;
					x--;
				}
				else d = d + dx;
			}
		}
	}

	//cuadrante 1
	else if (y1 <y0 && x1 >= x0) {

		// octante 2
		if (dx*-1 > dy) {

			for (int y = y0; y >= y1; y--) {
				putpixel(x, y, color);
				if (d > 0) {
					d = d + dx - dy*-1;
					x++;
				}
				else d = d + dx;
			}
		}
		// octante 1
		else if (dx*-1 <= dy) {
			for (int x = x0; x <= x1; x++) {
				putpixel(x, y, color);
				if (d > 0) {
					d = d - dy - dx;
					y--;
				}
				else d = d - dy;
			}
		}
	}

}

void ofApp::Circle(const int x, const int y, const int r,const ofColor& color)
{
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

		putpixel(xr + x, yr + y, color);
		putpixel(-xr + x, yr + y, color);
		putpixel(xr + x, -yr + y, color);
		putpixel(-xr + x, -yr + y, color);

		putpixel(yr + x, xr + y, color);
		putpixel(-yr + x, xr + y, color);
		putpixel(yr + x, -xr + y, color);
		putpixel(-yr + x, -xr + y, color);
		
	}
}