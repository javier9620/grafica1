#include "Application.h"
#include "iostream"
#include <vector>
#include "Application.h"
#define PI 3.1416

std::vector<Vect3> vertices;
std::vector<std::vector<Vect3>>  vertex;


void Application::seTup()
{
	moveTo(255, 255);
	vertex = sierpinky(150, 6);
	tx = x0;
	ty = y0;
	tx2 = -255;
	ty2 =-255;
}

void Application::update()
{

	r.matriz[0][0] = 1;
	r.matriz[0][1] = 0;
	r.matriz[0][2] = 0;

	r.matriz[1][0] = 0;
	r.matriz[1][1] = 1;
	r.matriz[1][2] = 0;

	r.matriz[2][0] = 0;
	r.matriz[2][1] = 0;
	r.matriz[2][2] = 1;

	//r2.matriz[0][0] = -100;
	//r2.matriz[0][1] = 0;
	//r2.matriz[0][2] = 0;

	//r2.matriz[1][0] = 0;
	//r2.matriz[1][1] = -100;
	//r2.matriz[1][2] = 0;

	//r2.matriz[2][0] = 0;
	//r2.matriz[2][1] = 0;
	//r2.matriz[2][2] = -100;


	t2.matriz[0][0] = cos((angulo* PI)/180);
	t2.matriz[0][1] = -sin((angulo* PI) / 180);
	t2.matriz[0][2] = 0;

	t2.matriz[1][0] = sin((angulo* PI) / 180);
	t2.matriz[1][1] = cos((angulo* PI) / 180);
	t2.matriz[1][2] = 0;

	t2.matriz[2][0] = 0;
	t2.matriz[2][1] = 0;
	t2.matriz[2][2] = 1;



	Matrix3 v;
	t = t.multiplicacionM(t2,r);
	
	for (int i = 0; i < vertex.size();i++)
	{
		for (int j = 0; j < vertex.at(i).size(); j++)
		{
			vertex.at(i).at(j) = multiplicacionM2(t, vertex.at(i).at(j));
		}
	}
	angulo =  (angulo + 1 ) %360;

	
	
}

void Application::draw()
{
	clearScreen();
	for (int j = 0; j < vertex.size(); ++j)
	{
		for (int i = 0; i < vertex.at(j).size(); ++i)
		{
			moveTo(vertex.at(j).at(i).ver[0], vertex.at(j).at(i).ver[1]);
			lineTo(vertex.at(j).at((i + 1) % vertex.at(j).size()).ver[0], vertex.at(j).at((i + 1) % vertex.at(j).size()).ver[1]);
		}
	}
}

std::vector<Vect3> Application::vertices2(int l, int r)
{

	int lados = l, angulo = 0, radio = r;
	int incremento = 360 / lados;
	Vect3 mv;
	
	mv.ver[0]  = x0;
	mv.ver[1] = y0;
	mv.ver[2] = 0;
	for (int i = 0; i < lados; ++i)
	{
		mv.ver[0] += radio * cos(angulo * PI / 180);
		mv.ver[1] += radio * sin(angulo * PI / 180);
		vertices.push_back(mv);
		angulo += incremento;
	}

	return vertices;

}

Vect3 Application::middlePoint(Vect3 o, Vect3 p)
{
	Vect3 result;

	result.ver[0] = (o.ver[0] + p.ver[0]) / 2;
	result.ver[1] = (o.ver[1]+ p.ver[1]) / 2;
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

//Matrix3 &Matrix3::rotation(int& ang)
//{
//	Matrix3 t;
//
//
//	t.matriz[0][0] = cos((ang)*deg);
//	t.matriz[0][1] = -sin((ang)*deg);
//	t.matriz[0][2] = 0;
//
//	t.matriz[1][0] = sin((ang)*deg);
//	t.matriz[1][1] = cos((ang)*deg);
//	t.matriz[1][2] = 0;
//
//	t.matriz[2][0] = 0;
//	t.matriz[2][1] = 0;
//	t.matriz[2][2] = 1;
//
//	return t;
//}

//Matrix3 &Matrix3::Translation(int& x, int& y)
//{
//	Matrix3 r;
//
//	r.matriz[0][0] = 0;
//	r.matriz[0][1] = 0;
//	r.matriz[0][2] = x;
//
//	r.matriz[1][0] = 0;
//	r.matriz[1][1] = 0;
//	r.matriz[1][2] = y;
//
//	r.matriz[2][0] = 0;
//	r.matriz[2][1] = 0;
//	r.matriz[2][2] = 1;
//
//	return r;
//}

Matrix3 Matrix3::multiplicacionM(Matrix3 a, Matrix3 b)
{
	Matrix3 m;

	m.matriz[0][0] = a.matriz[0][0] * b.matriz[0][0] + (a.matriz[0][1] * b.matriz[1][0] + (a.matriz[0][2] * b.matriz[2][0]));
	m.matriz[0][1] = a.matriz[0][0] * b.matriz[0][1] + (a.matriz[0][1] * b.matriz[1][1] + (a.matriz[0][2] * b.matriz[2][1]));
	m.matriz[0][2] = a.matriz[0][0] * b.matriz[0][2] + (a.matriz[0][1] * b.matriz[1][2] + (a.matriz[0][2] * b.matriz[2][2]));

	m.matriz[1][0] = a.matriz[1][0] * b.matriz[0][0] + (a.matriz[1][1] * b.matriz[1][0] + (a.matriz[1][2] * b.matriz[2][0]));
	m.matriz[1][1] = a.matriz[1][0] * b.matriz[0][1] + (a.matriz[1][1] * b.matriz[1][1] + (a.matriz[1][2] * b.matriz[2][1]));
	m.matriz[1][2] = a.matriz[1][0] * b.matriz[0][2] + (a.matriz[1][1] * b.matriz[1][2] + (a.matriz[1][2] * b.matriz[2][2]));

	m.matriz[2][0] = a.matriz[2][0] * b.matriz[0][0] + (a.matriz[2][1] * b.matriz[1][0] + (a.matriz[2][2] * b.matriz[2][0]));
	m.matriz[2][1] = a.matriz[2][0] * b.matriz[0][1] + (a.matriz[2][1] * b.matriz[1][1] + (a.matriz[2][2] * b.matriz[2][1]));
	m.matriz[2][2] = a.matriz[2][0] * b.matriz[0][2] + (a.matriz[2][1] * b.matriz[1][2] + (a.matriz[2][2] * b.matriz[2][2]));
	return m;

}

Vect3 Application::multiplicacionM2(Matrix3 a, Vect3 b)
{
	Vect3 r;

	r.ver[0] = a.matriz[0][0] * b.ver[0] + (a.matriz[0][1] * b.ver[1] + (a.matriz[0][2] * b.ver[2]));
	r.ver[1] = a.matriz[1][0] * b.ver[0] + (a.matriz[1][1] * b.ver[1] + (a.matriz[1][2] * b.ver[2]));
	r.ver[2] = a.matriz[2][0] * b.ver[0] + (a.matriz[2][1] * b.ver[1] + (a.matriz[2][2] * b.ver[2]));
	return r;
}



