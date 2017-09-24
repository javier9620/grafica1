#include "Application.h"
#include <iostream>

#define PI  3.1516
void Application::update()
{
	
}

void Application::draw()
{
	int x = 0, y = 0, x0 = 250, y0 = 250; // Corregir luego.
	int alpha;
	for (alpha = 0; alpha < 360; ++alpha) 
	{
		x = (100 * (float)cos(alpha * PI / 180))+ x0;
		y = (100 * (float)sin(alpha * PI / 180))+ y0;
		if (alpha <= 45 && alpha >= 0) //octante 1
			linea(x0,y0,x,y);
		else 
			linea(x,y,x0,y0);
		
	}


	

	
}

void Application::linea(int x0, int y0,int x, int y)
{
	int dy = (y - y0), dx = (x - x0), E = 2 * dy, NE = 2 *dy -2* dx;
	int d = (2 * dy) - dx;
	//putPixel(0, 0, 255, 255, 0, 255);
	putPixel(x0, y0, 255, 255, 0, 255);
	int w = x0 , z = y0;
	while (w <= x)
	{
		if (d > 0)
		{
			++z;
			d += NE;
		}
		else
		{
			d += E;
		}
		putPixel(w, z, 255, 255, 0, 255);
		putPixel(z, w, 255, 255, 0, 255);
		putPixel(-z-10, w, 255, 255, 0, 255);
		putPixel(-w-10, z, 255, 255, 0, 255);
		
		++w;
	
	}
	
}
