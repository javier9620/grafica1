#include "Application.h"
#include "iostream"
#include <vector>

#define PI 3.1416

std::vector<Vect3> vertices;

std::vector<Vect3> Application::vertices2(int l, int r)
{

	int lados = l, angulo = 0, radio = r;
	int incremento = 360 / lados;
	Vect3 mv;
	moveTo(100, 100);
	mv.x = x0;
	mv.y = y0;
	mv.z = 0;
	for (int i = 0; i < lados; ++i)
	{
		mv.x += radio * cos(angulo * PI / 180);
		mv.y += radio * sin(angulo * PI / 180);
		vertices.push_back(mv);
		angulo += incremento;
	}

	return vertices;

}

Vect3 Application::middlePoint(Vect3 o, Vect3 p)
{
	Vect3 result;

	result.x = (o.x + p.x) / 2;
	result.y = (o.y + p.y) / 2;
	return result;

}

std::vector<std::vector<Vect3>> Application::sierpinky(int ra, int sub)
{
	std::vector<std::vector<Vect3>> vertex;
	vertex.push_back(vertices2(3, ra));
	for (int i = 0; i < sub; ++i)
	{
		std::vector<std::vector<Vect3>> lel;
		for (int j = 0; j < vertex.size(); ++j)
		{
			std::vector<Vect3> lul;
			for (int e = 0; e < vertex.at(j).size(); ++e)
			{
				lul.push_back(middlePoint(vertex.at(j).at(e), vertex.at(j).at((e + 1) % vertex.at(j).size())));
			}
			std::vector<Vect3> temp1, temp2, temp3;
			temp1.push_back(lul.at(0));
			temp1.push_back(vertex.at(j).at(0));
			temp1.push_back(lul.at(2));
			temp2.push_back(lul.at(1));
			temp2.push_back(vertex.at(j).at(1));
			temp2.push_back(lul.at(0));
			temp3.push_back(lul.at(2));
			temp3.push_back(vertex.at(j).at(2));
			temp3.push_back(lul.at(1));
			lel.push_back(temp1);
			lel.push_back(temp2);
			lel.push_back(temp3);
		}
		vertex = lel;
	}

	return vertex;
}

void Application::seTup()
{
	vertex = sierpinky(150, 6);

}

void Application::draw()
{
	for (int j = 0; j < vertex.size(); ++j)
	{
		for (int i = 0; i < vertex.at(j).size(); ++i)
		{
			moveTo(vertex.at(j).at(i).x, vertex.at(j).at(i).y);
			lineTo(vertex.at(j).at((i + 1) % vertex.at(j).size()).x, vertex.at(j).at((i + 1) % vertex.at(j).size()).y);
		}
	}
}

void Application::update()
{

}