#ifndef DRAWSCENE_H
#define DRAWSCENE_H
#include "Model_drawer.h"
#include <stdio.h>
#include <SOIL.h>
#include <stdlib.h>
// #include <GLUT.h>
// #include <GL/GLU.h>
#include <glut.h>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>

// átadja a külön osztálynak a felhasználó által választott minõséget
void SetQuality(int quality_in);

//átadja a tárgyak forgásait a külön osztálynak
void SetRotation(float guitar_rotateAngle, double left_doorAngle, double right_doorAngle);

//betölti a környezet textúráit
bool LoadWorldTextures();

//a környezet textúrái kirajzolásának kezdete
void LoadModel();
void Table();
void Door_left();
void Door_right();
void Guitar();
void Draw_World();
//a környezet textúrái kirajzolásának vége

class DrawScene
{

public:

	void LoadModels()
	{
		LoadModel();
	}

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
