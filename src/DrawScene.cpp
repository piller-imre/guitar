#include "DrawScene.h"
#include <iostream>
using namespace std;

int quality;
float guitar_rotate_angle;
double left_door_angle = -90.0f;
double right_door_angle = 90.0f;
GLuint texture[31];

void SetQuality(int quality_in)
{
	quality = quality_in;
}

void SetRotation(float guitar_rotateAngle, double left_doorAngle, double right_doorAngle)
{
	guitar_rotate_angle = guitar_rotateAngle;
	left_door_angle = left_doorAngle;
	right_door_angle = right_doorAngle;
}

bool LoadWorldTextures()                                    // Load Bitmaps And Convert To Textures
{
	char *quality_folder[] = { "Data/low/", "Data/medium/", "Data/high/" };
	char *texture_names[31] = { "floor.jpg", "bricks.jpg", "top.jpg", "pillar.jpg", "wood.jpg","mirror.jpg","gitar_back.jpg","gitar_oldala.jpg","gitar_neck_back.jpg","gitar_hurok.jpg",
		"gitar_front.jpg","dirty.jpg","gitar_head_front.jpg","kep1.jpg","help.png","rare.jpg","gitar_back2.jpg","fold.jpg","fu.jpg","viz.jpg","cserep.jpg","rare1.jpg",
		"quit.png","mainmenu.jpg","light_set.png","house_pillar.jpg","door_left.jpg","door_right.jpg","door_front.jpg", "door_back.jpg", "exit.jpg" };
	char location[1024];
	if (quality == 1) {
		for (int i = 0; i < 31; ++i) {
			sprintf(location, "%s%s", quality_folder[0], texture_names[i]);
			texture[i] = SOIL_load_OGL_texture
				(location,
					SOIL_LOAD_AUTO,
					SOIL_CREATE_NEW_ID,
					SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO);
			if (texture[i] == 0) {
				cout << "Not found, or corrupt " << texture_names[i] << " .....\n";
				return false;
			}
			else cout << "Loading " << texture_names[i] << " .....\n";
			glBindTexture(GL_TEXTURE_2D, texture[i]);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}
		return true;
	}
	else if (quality == 2) {
		for (int i = 0; i < 31; ++i) {
			sprintf(location, "%s%s", quality_folder[1], texture_names[i]);
			texture[i] = SOIL_load_OGL_texture
				(location,
					SOIL_LOAD_AUTO,
					SOIL_CREATE_NEW_ID,
					SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO);
			if (texture[i] == 0) {
				cout << "Not found, or corrupt " << texture_names[i] << " .....\n";
				return false;
			}
			else cout << "Loading " << texture_names[i] << " .....\n";
			glBindTexture(GL_TEXTURE_2D, texture[i]);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}
		return true;
	}
	else if (quality == 3) {
		for (int i = 0; i < 31; ++i) {
			sprintf(location, "%s%s", quality_folder[2], texture_names[i]);
			texture[i] = SOIL_load_OGL_texture
				(location,
					SOIL_LOAD_AUTO,
					SOIL_CREATE_NEW_ID,
					SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO);
			if (texture[i] == 0) {
				cout << "Not found, or corrupt " << texture_names[i] << " .....\n";
				return false;
			}
			else cout << "Loading " << texture_names[i] << " .....\n";
			glBindTexture(GL_TEXTURE_2D, texture[i]);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}
		return true;
	}
}

void Table()
{
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	//jobb h�ts� l�b
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(2.0f, -1.0f, -29.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(2.0f, -0.4f, -29.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.9f, -0.4f, -29.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.9f, -1.0f, -29.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.9f, -1.0f, -29.1f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.9f, -0.4f, -29.1f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(2.0f, -0.4f, -29.1f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(2.0f, -1.0f, -29.1f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.9f, -1.0f, -29.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.9f, -0.4f, -29.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.9f, -0.4f, -29.1f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.9f, -1.0f, -29.1f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(2.0f, -1.0f, -29.1f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(2.0f, -0.4f, -29.1f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(2.0f, -0.4f, -29.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(2.0f, -1.0f, -29.0f);
	glEnd();
	//jobb els� l�b
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(2.0f, -1.0f, -27.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(2.0f, -0.4f, -27.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.9f, -0.4f, -27.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.9f, -1.0f, -27.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.9f, -1.0f, -27.1f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.9f, -0.4f, -27.1f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(2.0f, -0.4f, -27.1f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(2.0f, -1.0f, -27.1f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.9f, -1.0f, -27.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.9f, -0.4f, -27.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.9f, -0.4f, -27.1f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.9f, -1.0f, -27.1f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(2.0f, -1.0f, -27.1f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(2.0f, -0.4f, -27.1f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(2.0f, -0.4f, -27.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(2.0f, -1.0f, -27.0f);
	glEnd();
	//bal els� l�b
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.9f, -1.0f, -27.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.9f, -0.4f, -27.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-2.0f, -0.4f, -27.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-2.0f, -1.0f, -27.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-2.0f, -1.0f, -27.1f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-2.0f, -0.4f, -27.1f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.9f, -0.4f, -27.1f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.9f, -1.0f, -27.1f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-2.0f, -1.0f, -27.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-2.0f, -0.4f, -27.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-2.0f, -0.4f, -27.1f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-2.0f, -1.0f, -27.1f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.9f, -1.0f, -27.1f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.9f, -0.4f, -27.1f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.9f, -0.4f, -27.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.9f, -1.0f, -27.0f);
	glEnd();
	//bal h�ts� l�b
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.9f, -1.0f, -29.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.9f, -0.4f, -29.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-2.0f, -0.4f, -29.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-2.0f, -1.0f, -29.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-2.0f, -1.0f, -29.1f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-2.0f, -0.4f, -29.1f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.9f, -0.4f, -29.1f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.9f, -1.0f, -29.1f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-2.0f, -1.0f, -29.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-2.0f, -0.4f, -29.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-2.0f, -0.4f, -29.1f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-2.0f, -1.0f, -29.1f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.9f, -1.0f, -29.1f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.9f, -0.4f, -29.1f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.9f, -0.4f, -29.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.9f, -1.0f, -29.0f);
	glEnd();
	//asztallap
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(2.3f, -0.4f, -26.8f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(2.3f, -0.3f, -26.8f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-2.3f, -0.3f, -26.8f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-2.3f, -0.4f, -26.8f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-2.3f, -0.4f, -29.3f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-2.3f, -0.3f, -29.3f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(2.3f, -0.3f, -29.3f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(2.3f, -0.4f, -29.3f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-2.3f, -0.4f, -29.3f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-2.3f, -0.4f, -26.8f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-2.3f, -0.3f, -26.8f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-2.3f, -0.3f, -29.3f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(2.3f, -0.4f, -29.3f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(2.3f, -0.3f, -29.3f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(2.3f, -0.3f, -26.8f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(2.3f, -0.4f, -26.8f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(2.3f, -0.3f, -29.3f);
	glTexCoord2f(1.0f, 2.0f); glVertex3f(-2.3f, -0.3f, -29.3f);
	glTexCoord2f(0.0f, 2.0f); glVertex3f(-2.3f, -0.3f, -26.8f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(2.3f, -0.3f, -26.8f);
	glEnd();
}

void Guitar()
{
	glPushMatrix();
	glTranslatef(0.0f, 1.0f, -28.0f);
	glRotatef(guitar_rotate_angle, 0.0f, 1.0f, 0.0f);
	//front
	glBindTexture(GL_TEXTURE_2D, texture[6]);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.4f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, 0.6f, 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.4f, 0.0f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.4f, -0.8f, 0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.4f, -0.8f, 0.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[10]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.4f, -0.8f, 0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.4f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.4f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.4f, -0.8f, 0.0f);
	glEnd();
	//back
	glBindTexture(GL_TEXTURE_2D, texture[6]);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.4f, 0.0f, -0.2f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, 0.6f, -0.2f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.4f, 0.0f, -0.2f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.4f, -0.8f, -0.2f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, -1.0f, -0.2f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.4f, -0.8f, -0.2f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[16]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.4f, -0.8f, -0.2f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.4f, 0.0f, -0.2f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.4f, 0.0f, -0.2f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.4f, -0.8f, -0.2f);
	glEnd();
	//right side
	glBindTexture(GL_TEXTURE_2D, texture[7]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.4f, -0.8f, -0.2f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.4f, 0.0f, -0.2f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.4f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.4f, -0.8f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, -1.0f, -0.2f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.4f, -0.8f, -0.2f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.4f, -0.8f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, -1.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.4f, 0.0f, -0.2f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, 0.6f, -0.2f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.6f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.4f, 0.0f, 0.0f);
	glEnd();
	//left side
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.4f, 0.0f, -0.2f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.4f, -0.8f, -0.2f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.4f, -0.8f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.4f, 0.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.4f, -0.8f, 0.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.4f, -0.8f, -0.2f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, -1.0f, -0.2f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.4f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, 0.6f, 0.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.6f, -0.2f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.4f, 0.0f, -0.2f);
	glEnd();
	//neck
	glBindTexture(GL_TEXTURE_2D, texture[9]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.1f, -0.1f, 0.01f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.1f, 2.0f, 0.01f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.1f, 2.0f, 0.01f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.1f, -0.1f, 0.01f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[8]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.1f, 0.3f, -0.1f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.1f, 2.0f, -0.1f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.1f, 2.0f, -0.1f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.1f, 0.3f, -0.1f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.1f, -0.1f, 0.01f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.1f, 2.0f, 0.01f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.1f, 2.0f, -0.1f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.1f, -0.1f, -0.1f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.1f, -0.1f, -0.1f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.1f, 2.0f, -0.1f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.1f, 2.0f, 0.01f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.1f, -0.1f, 0.01f);
	glEnd();	//neck end
				//head
	glBindTexture(GL_TEXTURE_2D, texture[12]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.15f, 2.0f, 0.02f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.15f, 2.3f, 0.02f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.1f, 2.3f, 0.02f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.1f, 2.0f, 0.02f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[8]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.1f, 2.0f, -0.15f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.1f, 2.3f, -0.15f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.15f, 2.3f, -0.15f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.15f, 2.0f, -0.15f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.1f, 2.0f, 0.02f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.1f, 2.3f, 0.02f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.1f, 2.3f, -0.15f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.1f, 2.0f, -0.15f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.15f, 2.0f, -0.15f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.15f, 2.3f, -0.15f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.15f, 2.3f, 0.02f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.15f, 2.0f, 0.02f);
	glEnd();
	// right bottom
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.1f, 1.7f, -0.15f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.15f, 2.0f, -0.15f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.15f, 2.0f, 0.02f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.1f, 1.7f, 0.02f);
	glEnd();
	// back bottom
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.1f, 1.7f, -0.1f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.1f, 2.0f, -0.15f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.15f, 2.0f, -0.15f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.1f, 1.7f, -0.1f);
	glEnd();
	// front bottom
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.1f, 1.7f, 0.02f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.15f, 2.0f, 0.02f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.1f, 2.0f, 0.02f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.1f, 1.7f, 0.02f);
	glEnd();
	// left bottom
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.1f, 1.7f, -0.1f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.1f, 2.0f, -0.1f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.1f, 2.0f, -0.15f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.1f, 1.7f, -0.1f);
	glEnd();
	glPopMatrix();	//head end
}

void Door_left()
{
	glPushMatrix();
	glTranslatef(-3.9f, 0.0f, -75.5f);
	glRotatef(left_door_angle, 0.0f, 1.0f, 0.0f);
	// bal ajt� eleje
	glBindTexture(GL_TEXTURE_2D, texture[26]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, -1.0f, 0.1f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, -1.0f, -3.9f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, 4.0f, -3.9f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 4.0f, 0.1f);
	glEnd();

	// bal ajt� h�ta
	glBindTexture(GL_TEXTURE_2D, texture[27]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.1f, -1.0f, -3.9f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.1f, -1.0f, 0.1f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.1f, 4.0f, 0.1f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.1f, 4.0f, -3.9f);
	glEnd();

	// bal ajt� szemben lev� �le
	glBindTexture(GL_TEXTURE_2D, texture[28]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.1f, -1.0f, 0.1f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, -1.0f, 0.1f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, 4.0f, 0.1f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.1f, 4.0f, 0.1f);
	glEnd();

	// bal ajt� h�ts� �le
	glBindTexture(GL_TEXTURE_2D, texture[29]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, -1.0f, -3.9f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.1f, -1.0f, -3.9f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.1f, 4.0f, -3.9f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 4.0f, -3.9f);
	glEnd();

	glutPostRedisplay();
	glPopMatrix();

}

void Door_right()
{
	glPushMatrix();
	glTranslatef(3.9f, 0.0f, -75.5f);
	glRotatef(right_door_angle, 0.0f, 1.0f, 0.0f);
	// jobb ajt� eleje
	glBindTexture(GL_TEXTURE_2D, texture[27]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, -1.0f, -3.9f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, -1.0f, 0.1f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, 4.0f, 0.1f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 4.0f, -3.9f);
	glEnd();

	// jobb ajt� h�ta
	glBindTexture(GL_TEXTURE_2D, texture[26]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.1f, -1.0f, 0.1f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.1f, -1.0f, -3.9f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.1f, 4.0f, -3.9f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.1f, 4.0f, 0.1f);
	glEnd();

	// jobb ajt� szemben lev� �le
	glBindTexture(GL_TEXTURE_2D, texture[28]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, -1.0f, 0.1f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.1f, -1.0f, 0.1f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.1f, 4.0f, 0.1f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 4.0f, 0.1f);
	glEnd();

	// jobb ajt� h�ts� �le
	glBindTexture(GL_TEXTURE_2D, texture[29]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.1f, -1.0f, -3.9f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, -1.0f, -3.9f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, 4.0f, -3.9f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.1f, 4.0f, -3.9f);
	glEnd();

	glutPostRedisplay();
	glPopMatrix();

}

void Draw_World()
{
	// floor
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	for (float i = -10.00f; i < 75.00f; i = i + 26.16f)
	{
		for (float j = -18.00f; j < 18.00f; j = j + 11.04f)
		{
			glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-(j + 11.04f), -1.01f, -i);
			glTexCoord2f(15.0f, 0.0f); glVertex3f(-j, -1.01f, -i);
			glTexCoord2f(15.0f, 35.0f); glVertex3f(-j, -1.01f, -(i + 26.16f));
			glTexCoord2f(0.0f, 35.0f); glVertex3f(-(j + 11.04f), -1.01f, -(i + 26.16f));
			glEnd();
		}
	}
	// h�d
	glBindTexture(GL_TEXTURE_2D, texture[17]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-4.0f, -1.0f, -75.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(4.0f, -1.0f, -75.0f);
	glTexCoord2f(1.0f, 3.0f); glVertex3f(4.0f, -1.0f, -115.0f);
	glTexCoord2f(0.0f, 3.0f); glVertex3f(-4.0f, -1.0f, -115.0f);
	glEnd();
	// h�d bal fal
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-4.0f, -1.0f, -76.0f);
	glTexCoord2f(5.0f, 0.0f); glVertex3f(-4.0f, -1.0f, -115.0f);
	glTexCoord2f(5.0f, 0.2f); glVertex3f(-4.0f, 0.1f, -115.0f);
	glTexCoord2f(0.0f, 0.2f); glVertex3f(-4.0f, 0.1f, -76.0f);
	glEnd();
	// h�d jobb fal
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(4.0f, -1.0f, -115.0f);
	glTexCoord2f(5.0f, 0.0f); glVertex3f(4.0f, -1.0f, -76.0f);
	glTexCoord2f(5.0f, 0.2f); glVertex3f(4.0f, 0.1f, -76.0f);
	glTexCoord2f(0.0f, 0.2f); glVertex3f(4.0f, 0.1f, -115.0f);
	glEnd();
	// h�d els�
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-4.0f, -1.0f, -115.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(4.0f, -1.0f, -115.0f);
	glTexCoord2f(1.0f, 0.145f); glVertex3f(4.0f, -0.3f, -115.0f);
	glTexCoord2f(0.0f, 0.145f); glVertex3f(-4.0f, -0.3f, -115.0f);
	glEnd();
	// h�d els� teteje
	glBindTexture(GL_TEXTURE_2D, texture[11]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-9.3f, -0.3f, -115.0f);
	glTexCoord2f(11.92f, 0.0f); glVertex3f(10.0f, -0.3f, -115.0f);
	glTexCoord2f(11.92f, 1.0f); glVertex3f(10.0f, -0.3f, -116.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-9.3f, -0.3f, -116.0f);
	glEnd();  //h�d v�ge
	//plafon
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	for (float i = -10.00f; i < 65.00f; i = i + 26.16f)
	{
		for (float j = -18.00f; j < 18.00f; j = j + 11.04f)
		{
			glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-(j+11.04f), 7.0f, -(i + 26.16f));
			glTexCoord2f(8.0f, 0.0f); glVertex3f(-j, 7.0f, -(i + 26.16f));
			glTexCoord2f(8.0f, 8.0f); glVertex3f(-j, 7.0f, -i);
			glTexCoord2f(0.f, 8.0f); glVertex3f(-(j + 11.04f), 7.0f, -i);
			glEnd();
		}
	}
	//plafon ajt� el�tt
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-4.0f, 4.0f, -75.0f);
	glTexCoord2f(5.0f, 0.0f); glVertex3f(4.0f, 4.0f, -75.0f);
	glTexCoord2f(5.0f, 3.0f); glVertex3f(4.0f, 4.0f, -68.48f);
	glTexCoord2f(0.f, 3.0f); glVertex3f(-4.0f, 4.0f, -68.48);
	glEnd();
	Table();
	//walls //bal
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	for (float i = -10.00f; i < 75.00f; i = i + 21.25f)
	{
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-18.0f, -1.01f, -i);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-18.0f, -1.01f, -(i+21.25f));
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-18.0f, 7.1f, -(i+21.25f));
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-18.0f, 7.1f, -i);
		glEnd();
	}
	//jobb
	for (float i = -10.00f; i < 75.00f; i = i + 21.25f)
	{
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(18.0f, -1.01f, -(i + 21.25f));
		glTexCoord2f(1.0f, 0.0f); glVertex3f(18.0f, -1.01f, -i);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(18.0f, 7.1f, -i);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(18.0f, 7.1f, -(i + 21.25f));
		glEnd();
	}
	//ajt� el�tt jobb fal
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(4.0f, -1.0f, -75.0f);
	glTexCoord2f(0.25f, 0.0f); glVertex3f(4.0f, -1.0f, -68.48f);
	glTexCoord2f(0.25f, 0.62f); glVertex3f(4.0f, 4.0f, -68.48f);
	glTexCoord2f(0.0f, 0.62f); glVertex3f(4.0f, 4.0f, -75.0f);
	glEnd();
	//ajt� el�tt bal fal
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-4.0f, -1.0f, -68.48f);
	glTexCoord2f(0.25f, 0.0f); glVertex3f(-4.0f, -1.0f, -75.0f);
	glTexCoord2f(0.25f, 0.62f); glVertex3f(-4.0f, 4.0f, -75.0f);
	glTexCoord2f(0.0f, 0.62f); glVertex3f(-4.0f, 4.0f, -68.48f);
	glEnd();
	//els� teteje
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-18.0f, 4.0f, -68.48);
	glTexCoord2f(2.0f, 0.0f); glVertex3f(18.0f, 4.0f, -68.48);
	glTexCoord2f(2.0f, 0.37f); glVertex3f(18.0f, 7.1f, -68.48);
	glTexCoord2f(0.0f, 0.37f); glVertex3f(-18.0f, 7.1f, -68.48);
	glEnd();
	//h�ts�
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(18.0f, -1.01f, 10.0f);
	glTexCoord2f(3.0f, 0.0f); glVertex3f(-18.0f, -1.01f, 10.0f);
	glTexCoord2f(3.0f, 1.0f); glVertex3f(-18.0f, 7.1f, 10.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(18.0f, 7.1f, 10.0f);
	glEnd();
	// els�1
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-18.0f, -1.01f, -68.48);
	glTexCoord2f(0.75f, 0.0f); glVertex3f(-4.0f, -1.01f, -68.48);
	glTexCoord2f(0.75f, 0.62f); glVertex3f(-4.0f, 4.0f, -68.48);
	glTexCoord2f(0.0f, 0.62f); glVertex3f(-18.0f, 4.0f, -68.48);
	glEnd();
	// els�2
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(4.0f, -1.01f, -68.48);
	glTexCoord2f(0.75f, 0.0f); glVertex3f(18.0f, -1.01f, -68.48);
	glTexCoord2f(0.75f, 0.62f); glVertex3f(18.0f, 4.0f, -68.48);
	glTexCoord2f(0.0f, 0.62f); glVertex3f(4.0f, 4.0f, -68.48);
	glEnd();
	//k�ls� fal teteje
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(24.0f, 4.0f, -76.0f);
	glTexCoord2f(2.5f, 0.0f); glVertex3f(-24.0f, 4.0f, -76.0f);
	glTexCoord2f(2.5f, 0.37f); glVertex3f(-24.0f, 7.1f, -76.0f);
	glTexCoord2f(0.0f, 0.37f); glVertex3f(24.0f, 7.1f, -76.0f);
	glEnd();
	//exit felirat
	glBindTexture(GL_TEXTURE_2D, texture[30]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.5f, 4.3f, -68.43f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.5f, 4.3f, -68.43f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.5f, 5.3f, -68.43f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.5f, 5.3f, -68.43f);
	glEnd();
	//tet�(cser�p)
	glBindTexture(GL_TEXTURE_2D, texture[20]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(24.0f, 6.8f, -76.5f);
	glTexCoord2f(10.0f, 0.0f); glVertex3f(-24.0f, 6.8f, -76.5f);
	glTexCoord2f(10.0f, 10.0f); glVertex3f(-24.0f, 25.1f, -46.0f);
	glTexCoord2f(0.0f, 10.0f); glVertex3f(24.0f, 25.1f, -46.0f);
	glEnd();
	//k�ls� fal bal
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(24.0f, -1.0f, -76.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(4.0f, -1.0f, -76.0f);
	glTexCoord2f(1.0f, 0.62f); glVertex3f(4.0f, 4.0f, -76.0f);
	glTexCoord2f(0.0f, 0.62f); glVertex3f(24.0f, 4.0f, -76.0f);
	glEnd();
	//k�ls� fal jobb
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-4.0f, -1.0f, -76.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-24.0f, -1.0f, -76.0f);
	glTexCoord2f(1.0f, 0.62f); glVertex3f(-24.0f, 4.0f, -76.0f);
	glTexCoord2f(0.0f, 0.62f); glVertex3f(-4.0f, 4.0f, -76.0f);
	glEnd();
	//ajt�keret teteje
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-4.0f, 4.0f, -76.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(4.0f, 4.0f, -76.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(4.0f, 4.0f, -75.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-4.0f, 4.0f, -75.0f);
	glEnd();
	//jobb ajt�f�lfa
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(4.0f, -1.0f, -76.0f);
	glTexCoord2f(0.5f, 0.0f); glVertex3f(4.0f, -1.0f, -75.0f);
	glTexCoord2f(0.5f, 2.0f); glVertex3f(4.0f, 7.0f, -75.0f);
	glTexCoord2f(0.0f, 2.0f); glVertex3f(4.0f, 7.0f, -76.0f);
	glEnd();
	//bal ajt�f�lfa
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-4.0f, -1.0f, -75.0f);
	glTexCoord2f(0.5f, 0.0f); glVertex3f(-4.0f, -1.0f, -76.0f);
	glTexCoord2f(0.5f, 2.0f); glVertex3f(-4.0f, 7.0f, -76.0f);
	glTexCoord2f(0.0f, 2.0f); glVertex3f(-4.0f, 7.0f, -75.0f);
	glEnd();
	//mez�
	glBindTexture(GL_TEXTURE_2D, texture[18]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(18.0f, -1.0f, -175.0f);
	glTexCoord2f(12.0f, 0.0f); glVertex3f(18.0f, -1.0f, -25.0f);
	glTexCoord2f(12.0f, 3.0f); glVertex3f(40.0f, 5.0f, -25.0f);
	glTexCoord2f(0.0f, 3.0f); glVertex3f(40.0f, 5.0f, -175.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-18.0f, -1.0f, -90.0f);
	glTexCoord2f(12.0f, 0.0f); glVertex3f(-18.0f, -1.0f, -175.0f);
	glTexCoord2f(12.0f, 3.0f); glVertex3f(-40.0f, 5.0f, -175.0f);
	glTexCoord2f(0.0f, 3.0f); glVertex3f(-40.0f, 5.1f, -90.0f);
	glEnd();
	// v�z alatti f�ld
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-60.0f, -1.5f, -45.0f);
	glTexCoord2f(5.0f, 0.0f); glVertex3f(60.0f, -1.5f, -45.0f);
	glTexCoord2f(5.0f, 5.0f); glVertex3f(60.0f, -1.5f, -185.0f);
	glTexCoord2f(0.0f, 5.0f); glVertex3f(-60.0f, -1.5f, -185.0f);
	glEnd();
	// v�z
	glBindTexture(GL_TEXTURE_2D, texture[19]);
	glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-180.0f, -1.1f, -75.0f);
	glTexCoord2f(50.0f, 0.0f); glVertex3f(180.0f, -1.1f, -75.0f);
	glTexCoord2f(50.0f, 50.0f); glVertex3f(180.0f, -1.1f, -275.0f);
	glTexCoord2f(0.0f, 50.0f); glVertex3f(-180.0f, -1.1f, -275.0f);
	glEnd();
	//els� kinti h�z tart�
	glBindTexture(GL_TEXTURE_2D, texture[25]);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-24.0f, 0.5f, -110.8f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-24.0f, 2.5f, -110.8f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-24.8f, 2.5f, -110.8f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-24.8f, 0.5f, -110.8f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-24.8f, 0.5f, -111.6f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-24.8f, 2.5f, -111.6f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-24.0f, 2.5f, -111.6f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-24.0f, 0.5f, -111.6f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-24.0f, 0.5f, -111.6f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-24.0f, 2.5f, -111.6f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-24.0f, 2.5f, -110.8f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-24.0f, 0.5f, -110.8f);
	glEnd();
	//h�ts� kinti h�z tart�
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-24.0f, 0.5f, -130.8f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-24.0f, 2.5f, -130.8f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-24.8f, 2.5f, -130.8f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-24.8f, 0.5f, -130.8f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-24.0f, 0.5f, -131.6f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-24.0f, 2.5f, -131.6f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-24.0f, 2.5f, -130.8f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-24.0f, 0.5f, -130.8f);
	glEnd();
	// k�z�ps� kinti h�z tart�
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-24.0f, 0.5f, -120.8f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-24.0f, 2.5f, -120.8f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-24.8f, 2.5f, -120.8f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-24.8f, 0.5f, -120.8f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-24.0f, 0.5f, -121.6f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-24.0f, 2.5f, -121.6f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-24.0f, 2.5f, -120.8f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-24.0f, 0.5f, -120.8f);
	glEnd();
	//oszlop1
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glBegin(GL_QUADS);

	glTexCoord2f(1.0f, 0.0f); glVertex3f(11.9f, -1.0f, -39.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(11.9f, 7.1f, -39.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(10.1f, 7.1f, -39.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(10.1f, -1.0f, -39.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.1f, -1.0f, -41.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.1f, 7.1f, -41.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(11.9f, 7.1f, -41.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(11.9f, -1.0f, -41.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.1f, -1.0f, -39.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.1f, 7.1f, -39.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(10.1f, 7.1f, -41.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(10.1f, -1.0f, -41.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(11.9f, -1.0f, -41.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(11.9f, 7.1f, -41.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(11.9f, 7.1f, -39.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(11.9f, -1.0f, -39.0f);
	glEnd();  //oszlop1 v�ge
			  //oszlop2
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(11.9f, -1.0f, -9.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(11.9f, 7.1f, -9.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(10.1f, 7.1f, -9.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(10.1f, -1.0f, -9.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.1f, -1.0f, -11.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.1f, 7.1f, -11.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(11.9f, 7.1f, -11.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(11.9f, -1.0f, -11.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.1f, -1.0f, -9.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.1f, 7.1f, -9.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(10.1f, 7.1f, -11.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(10.1f, -1.0f, -11.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(11.9f, -1.0f, -11.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(11.9f, 7.1f, -11.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(11.9f, 7.1f, -9.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(11.9f, -1.0f, -9.0f);
	glEnd();  //oszlop2 v�ge
			  //oszlop3
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.1f, -1.0f, -9.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-10.1f, 7.1f, -9.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-11.9f, 7.1f, -9.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-11.9f, -1.0f, -9.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-11.9f, -1.0f, -11.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-11.9f, 7.1f, -11.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.1f, 7.1f, -11.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.1f, -1.0f, -11.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-11.9f, -1.0f, -9.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-11.9f, 7.1f, -9.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-11.9f, 7.1f, -11.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-11.9f, -1.0f, -11.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.1f, -1.0f, -11.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-10.1f, 7.1f, -11.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.1f, 7.1f, -9.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.1f, -1.0f, -9.0f);
	glEnd();  //oszlop3 v�ge
			  //oszlop4
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.1f, -1.0f, -39.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-10.1f, 7.1f, -39.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-11.9f, 7.1f, -39.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-11.9f, -1.0f, -39.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-11.9f, -1.0f, -41.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-11.9f, 7.1f, -41.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.1f, 7.1f, -41.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.1f, -1.0f, -41.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-11.9f, -1.0f, -39.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-11.9f, 7.1f, -39.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-11.9f, 7.1f, -41.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-11.9f, -1.0f, -41.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.1f, -1.0f, -41.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-10.1f, 7.1f, -41.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.1f, 7.1f, -39.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.1f, -1.0f, -39.0f);
	glEnd();  //oszlop4 v�ge
			  //pic left
	glBindTexture(GL_TEXTURE_2D, texture[15]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-17.9f, -0.5f, -40.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-17.9f, -0.5f, -45.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-17.9f, 5.5f, -45.0f);
	glTexCoord2f(0.f, 0.0f); glVertex3f(-17.9f, 5.5f, -40.0f);
	glEnd();
	//pic2 left
	glBindTexture(GL_TEXTURE_2D, texture[13]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-17.9f, 0.5f, 3.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-17.9f, 0.5f, -3.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-17.9f, 6.5f, -3.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-17.9f, 6.5f, 3.0f);
	glEnd();
	//pic3 right
	glBindTexture(GL_TEXTURE_2D, texture[21]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(17.9f, 0.5f, -34.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(17.9f, 0.5f, -30.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(17.9f, 6.5f, -30.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(17.9f, 6.5f, -34.0f);
	glEnd();
	//t�k�r
	glBindTexture(GL_TEXTURE_2D, texture[5]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(6.0f, 0.0f, 9.9f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-6.0f, 0.0f, 9.9f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-6.0f, 5.8f, 9.9f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(6.0f, 5.8f, 9.9f);
	glEnd();

	Guitar();
	Door_left();
	Door_right();
}

DrawScene::DrawScene()
{
}

DrawScene::~DrawScene()
{
}
