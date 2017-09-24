#include "Application.h"
#include "iostream"

int i = 0;
int i2 = 0;
bool lol = true;
void Application::draw()
{

	while (lol)
	{
		circle(rand() % WIDTH, rand() % HEIGHT, rand() % 150);
		if (i >= 20)
		{
			lol = false;
		}
		++i;
	}


}


void Application::update()
{

}

void Application::circle(int cx, int cy, int r)
{
	int x = 0, y = r;
	int d = 1 - r;

	while (x < y)
	{
		putPixel(x + cx, y + cy);
		putPixel(y + cx, -x + cy);
		putPixel(-x + cx, -y + cy);
		putPixel(-y + cx, x + cy);
		putPixel(y + cx, x + cy);
		putPixel(-x + cx, y + cy);
		putPixel(-y + cx, -x + cy);
		putPixel(x + cx, -y + cy);

		if (d < 0)
		{
			d += 2 * x + 3;
		}
		else
		{
			d += 2 * (x - y) + 5;
			--y;
		}
		++x;
	}

}

void Application::putPixel(int x, int y)
{
	putPixel(x, y, rand() % 255, rand() % 250, 0, 0);
}
