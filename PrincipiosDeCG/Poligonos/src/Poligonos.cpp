#include "Application.h"
#include "iostream"

#define PI 3.1416

std::vector<Vector> vertices;

void Application::setup()
{
	int lados = 4, angulo = 0, radio = 50;
	int incremento = 360 / lados;
	Vector mv;

	for (int i = lados + 1; --i;)
	{
		mv.v[0] += radio * cos(angulo * PI / 180);
		mv.v[1] += radio * sin(angulo * PI / 180);
		vertices.push_back(mv);
		angulo += incremento;
	}
	
}

void Application::draw()
{

	for (int i = vertices.size();--i;)
	{

		lineTo(vertices[i].x, vertices[i].y);
	}

}

void Application::update()
{

}