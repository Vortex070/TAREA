#include "DrawLine.h"

void DrawLine::NewClear()
{
	pixel._img.allocate(1024, 768, ofImageType::OF_IMAGE_COLOR_ALPHA);
	ofColor color;
	color.r = 0;
	color.g = 0;
	color.b = 0;
	pixel.clear(color);
}

void DrawLine::midLine(int x0, int y0, int x1, int y1)
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

	if (dx > dy) {

		for (int x = x0; x <= x1; x++) {
			pixel.putpixel(x, y, color);
			if (d > 0) {
				d = d + DeltaE;
				y++;
			}
			else d = d + DeltaNE;
		}
	}

	//cuadrante 4
	if (y1 > y0 && x1 >= x0) {

		// octante 8
		if (dx > dy) {

			for (int x = x0; x <= x1; x++) {
				pixel.putpixel(x, y, color);
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
				pixel.putpixel(x, y, color);
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
				pixel.putpixel(x, y, color);
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
				pixel.putpixel(x, y, color);
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
				pixel.putpixel(x, y, color);
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
				pixel.putpixel(x, y, color);
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
				pixel.putpixel(x, y, color);
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
				pixel.putpixel(x, y, color);
				if (d > 0) {
					d = d - dy - dx;
					y--;
				}
				else d = d - dy;
			}
		}
	}

}

/*void DrawLine::drawLine(int x1, int y1, int x2, int y2) {


	dx = x2 - x1;
	dy = y2 - y1;

	dOld = 0;

	y = y1;
	x = x1;



	if (y2 >= y1 && x2 >= x1)
	{

		if (dx> dy)
		{
			for (int x = x1; x <= x2; x++)
			{
				pixel.putpixel(x, y, ofColor::green);

				if (dOld > 0) {
					dOld = dOld + dy - dx;
					y++;
				}
				else dOld = dOld + dy;
			}
		}

		else if (dx <= dy)
		{
			for (int y = y1; y <= y2; y++)
			{
				pixel.putpixel(x, y, ofColor::green);

				if (dOld > 0)
				{
					dOld = dOld + dx - dy;
					x++;
				}
				else dOld = dOld + dx;
			}
		}
	}
	else if (y2 >= y1 && x2 < x1)
	{

		if (dx > dy *-1)
		{
			for (int y = y1; y <= y2; y++)
			{
				pixel.putpixel(x, y, ofColor::green);

				if (dOld < 0)
				{
					dOld = dOld + dx - dy * -1;
					x--;
				}
				else dOld = dOld + dx;
			}
		}
		else if (dx <= dy *-1)
		{

			for (int x = x1; x >= x2; x--)
			{
				pixel.putpixel(x, y, ofColor::green);

				if (dOld < 0)
				{
					dOld = dOld - dy - dx;
					y++;
				}
				else dOld = dOld - dy;
			}
		}
	}
	else if (y2 < y1 && x2 <= x1)
	{

		if (dx < dy) {
			for (int x = x1; x >= x2; x--)
			{
				pixel.putpixel(x, y, ofColor::green);

				if (dOld < 0)
				{
					dOld = dOld + dy - dx;
					y--;
				}
				else dOld = dOld + dy;
			}
		}

		else if (dx >= dy)
		{
			for (int y = y1; y >= y2; y--)
			{
				pixel.putpixel(x, y, ofColor::green);

				if (dOld < 0)
				{
					dOld = dOld + dx - dy;
					x--;
				}
				else dOld = dOld + dx;
			}
		}
	}
	else if (y2 < y1 && x2 > x1)
	{

		if (dx *-1 > dy)
		{
			for (int y = y1; y >= y2; y--)
			{
				pixel.putpixel(x, y, ofColor::green);

				if (dOld > 0)
				{
					dOld = dOld + dx - dy*-1;
					x++;
				}
				else dOld = dOld + dx;
			}
		}

		else if (dx *-1 <= dy)
		{
			for (int x = x1; x <= x2; x++)
			{
				pixel.putpixel(x, y, ofColor::green);

				if (dOld > 0)
				{
					dOld = dOld - dy - dx;
					y--;
				}
				else dOld = dOld - dy;
			}
		}
	}
}*/



