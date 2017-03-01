#ifndef DRAWSCENE_H
#define DRAWSCENE_H

#include <stdio.h>
#include <SOIL/SOIL.h>
#include <stdlib.h>
// #include <GLUT.h>
// #include <GL/GLU.h>
#include <GL/glut.h>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>

// �tadja a k�l�n oszt�lynak a felhaszn�l� �ltal v�lasztott min�s�get
void SetQuality(int quality_in);

//�tadja a t�rgyak forg�sait a k�l�n oszt�lynak
void SetRotation(float guitar_rotateAngle, double left_doorAngle, double right_doorAngle);

//bet�lti a k�rnyezet text�r�it
bool LoadWorldTextures();

//a k�rnyezet text�r�i kirajzol�s�nak kezdete
void Table();
void Door_left();
void Door_right();
void Guitar();
void Draw_World();
//a k�rnyezet text�r�i kirajzol�s�nak v�ge

class DrawScene
{
public:

	void LoadTextures(int quality_in)
	{
		SetQuality(quality_in);
		LoadWorldTextures();
	}

	void Draw_World_Pub(float guitar_rotateAngle, double left_doorAngle, double right_doorAngle)
	{
		SetRotation(guitar_rotateAngle, left_doorAngle, right_doorAngle);
		Draw_World();
	}

	DrawScene();
	~DrawScene();
};

#endif 
