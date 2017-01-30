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
	for (float a = 0; a < 360; ++a)
	{
		int x1 = 100 * cos(a*PI / 180.0f);
		int y1 = 100 * sin(a*PI / 180.0f);
		
		Line((x0 + xc), (y0 + yc), (x1 + xc), (y1 + yc), ofColor::green);
	}
		


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

void ofApp::Line(const int x0, const int y0, const int x1, const int y1, const ofColor& color)
{
	int dy = y1 - y0;
	int dx = x1 - x0;

	int d = 2 * dy - dx;
	int E = 2 * dy - 2 * dx;
	int NE = 2 * dy;

	int x = x0, y = y0;

	putpixel(x0, y0,color);

	

	while (x <= x1)
	{
		x = x + 1;

		if (d <= 0)
		{
			d = d + E;
		}
		else if (d > 0)
		{
			d = d + NE;
			y = y + 1;
		}

		putpixel(x, y, color);
	}

}