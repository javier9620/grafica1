#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <iostream>
#include "Object3D.h"
#include "Plane.h"
#include <stack>
#include "GLFW\glfw3.h"
#include <vector>



class Matrix3;

class Vect3
{
public:
	float ver[3];

};

class Matrix3
{
public:
	float matriz[3][3];
	/*Matrix3 &rotation(int& ang);
	Matrix3 &Translation(int& x, int& y);*/
	Matrix3 multiplicacionM(Matrix3 &a, Matrix3 &b);
	

};
class Application {
public:
	
	
	static const int WIDTH = 512;
	static const int HEIGHT = 512;
	static const int RGB = 3;
	static const int RGBA = 4;

	int x0, y0;
	int angulo = 0;
	int tx, ty;

	Application();
	~Application();

	void init();
	void display();
	void reshape(int w, int h);
	void keyboard(int key, int scancode, int action, int mods);
	void update();
	void swapbuffers();
	void cursor_position(double xpos, double ypos);
	void putPixel(GLubyte *buffer, int x, int y, unsigned char R, unsigned char G, unsigned char B, unsigned char A);
	void putPixel(int x, int y, unsigned char R, unsigned char G, unsigned char B, unsigned char A);
	void draw();
	void seTup();
	void clearScreen();
	void setColor(int r, int g, int b, int a);
	void moveTo(int x, int y);
	void lineTo(int x1, int y1);
	std::vector<std::vector<Vect3>> sierpinky(int ra, int sub);
	Vect3 middlePoint(Vect3 o, Vect3 p);
	std::vector<Vect3> vertices2(int l, int r);

	

	std::stack<glm::mat4> mStack;
	glm::mat4 mProjectionMatrix, mTransform;
	glm::vec3 vEye;
	GLFWwindow* window;
	unsigned char Buffers[2][WIDTH*HEIGHT*RGBA];
	Vect3 multiplicacionM2(Matrix3 a, Vect3 b);

private:	
	GLuint texturesID[2], pboID[2];
	GLuint shaderID;
	GLuint VAO, VBO;
	GLuint sampler;
	GLuint uTransform;
	GLubyte* _screenBuffer;
	int _currentBuffer, 
		_nextBuffer;

	glm::vec3 myLightPosition;
	GLuint uMyLightPosition[2];	

	Plane oPlane;
	float fTime;
	void initTextures();
	void processPBO();
	void initPBOs();
	void updatePixels(GLubyte *buffer);
	int _drawMode,
		shader;
	bool moveLight;

	void fakeBuffers();
	Matrix3 t, z, r, t2;
};

#endif //__APPLICATION_H__