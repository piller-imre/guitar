#include "model.h"
#include "DrawScene.h"
#include <stdio.h>
#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>

// http://www.glfw.org/docs/latest/group__buttons.html
// #include <glfw3.h>
#define GLFW_MOUSE_BUTTON_LEFT 0

using namespace std;
inline float ToRad(float angle_degrees){
	return angle_degrees * M_PI / 180.0f;}

int window;
static GLint fogMode;
int active_quality = 1;
GLuint textures[7];
float xrot = 0, yrot = 180, zrot = 0;
float xpos = 0, ypos = 0, zpos = 0;
float guitar_rot_angle = 0.0f;
double L_door_angle = -90.0f;
double R_door_angle = 90.0f;
int width_global;
int height_global;
float aspect_ratio;
int x_difference = 0;
int y_difference = 0;
float fog_strt = 130.0f, fog_end = 140.0f;
bool clck_start = false, clck_help = false, clck_quit = false, clck_yes = false, clck_no = false, help_back = false, clck_low = false, clck_med = false, clck_hi = false;

//mozgáshoz vagy irányításhoz szüksékes deklarációk
bool go_forward = false, go_backward = false;
bool look_up = false, look_down = false;
bool turn_left = false, turn_right = false;
bool go_left = false, go_right = false;
bool quit_down = false;
bool menu = true;
bool light_up = false, light_down = false;
bool state_of_doors = true;
bool guitar_rot = false; //mozgáshoz vagy irányításhoz szüksékes deklarációk vége

bool help = false, quit1 = false, main_menu = true, openable = false, wait = false;
int light_menu = 0;
float ambientvalue = 1.0f;
GLfloat light_position_front_left[] = { 101.0f, 120.0f, 90.0f, 1.0f };
GLfloat light_position_front_right[] = { 121.0f, 120.0f, 90.0f, 1.0f };
GLfloat light_position_back_left[] = { 101.0f, 120.0f, 120.0f, 1.0f };
GLfloat light_position_back_right[] = { 122.0f, 120.0f, 120.0f, 1.0f };
GLfloat light_position_table[] = { 100.0f, 120.0f, 105.0f, 1.0f };
GLfloat light_ambient_menu[] = { 0.8f,0.8f,0.8f,1.0f };
GLfloat cut[] = { 3.2f };
GLfloat light_ambient[] = { 0.1f,0.1f,0.1f,1.0f };
GLfloat light_diffuse[] = { 0.0f,0.1f,0.1f,1.0f };
GLfloat light_specular[] = { 0.0f,0.0f,0.0f,1.0f };
GLfloat light_direction[] = { -1.0f, -1.0f, -1.0f};
bool light = true;
float fraction = 0.1f;

Model_betolto raptor_model;
Model_betolto house_model;
Model_betolto weapon_model;
Model_betolto tree_model;
Model_betolto rock_model;
Model_betolto mountain_model_small;
Model_betolto mountain_model;
Model_betolto mountain_model_big;
Model_betolto mountain_model_biggest;
DrawScene world;

static void Fog(void)
{
	GLfloat position[] = { 0.5, 0.5, 3.0, 0.0 };
	float fog_r = 0.7f, fog_g = 0.7f, fog_b = 0.7f;
	glEnable(GL_DEPTH_TEST);
	glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	{
		GLfloat mat[3] = { 0.1745f, 0.01175f, 0.01175f };
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
		mat[0] = 0.61424; mat[1] = 0.04136; mat[2] = 0.04136;
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
		mat[0] = 0.727811; mat[1] = 0.626959; mat[2] = 0.626959;
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
		glMaterialf(GL_FRONT, GL_SHININESS, 0.6*128.0);
	}
	glEnable(GL_FOG);
	{
		GLfloat fogColor[4] = { 0.7f, 0.7f, 0.7f, 0.0000001f };
		fogMode = GL_LINEAR;
		glFogi(GL_FOG_MODE, fogMode);
		glFogfv(GL_FOG_COLOR, fogColor);
		glFogf(GL_FOG_DENSITY, 0.0001);
		glHint(GL_FOG_HINT, GL_DONT_CARE);
		glFogf(GL_FOG_START, fog_strt);
		glFogf(GL_FOG_END, fog_end);
	}
	glClearColor(fog_r, fog_g, fog_b, 0.1);  /* fog color */
}

bool Openeable_controller()
{
	if ((xpos >= -4.9f) && (xpos <= 4.9f) && (zpos >= -73.5f) && (zpos <= -65.0f))	{
		return true;
	}
	if ((xpos >= -4.9f) && (xpos <= 4.9f) && (zpos <= -77.5f) && (zpos >= -86.0f))	{
		return true;
	}
	return false;
}

void collision_detector()
{
	if (xpos <= -16.5f) {
		xpos = -16.5f;
	}
	if (xpos >= 16.5f) {
		xpos = 16.5f;
	}
	if (zpos >= 8.5) {
		zpos = 8.5f;
	}
	if (zpos <= -113.5f) {
		zpos = -113.5f;
	}
		if (state_of_doors == true)	{
			if ((xpos <=5.0f) && (xpos >=-5.0f) && (zpos >=-75.5f) && (zpos <= -73.5f))			{
				if (zpos <= -73.5)			{
					zpos = -73.5;
				}
			}

			if ((xpos <= 5.0f) && (xpos >= -5.0f) && (zpos <= -75.5f) && (zpos >= -77.5f))		{
				if (zpos >= -77.5)			{
					zpos = -77.5;
				}
			}
	}
	//híd bal
	if ((zpos <= -68.0f)) {
		if (xpos <= -2.4f) {
			xpos = -2.4f;
		}
	}
	if ((xpos <= -2.5f) && (zpos <= -67.0f)) {
		if ((zpos <= -67.0f)) {
			zpos = -67.0f;
		}
	}
	//híd jobb
	if (zpos <= -68.0f) {
		if (xpos >= 2.4f) {
			xpos = 2.4f;
		}
	}
	if ((xpos >= 2.5f) && (zpos <= -67.0f)) {
		if (zpos <= -67.0f) {
			zpos = -67.0f;
		}
	}
	//asztal
	if ((xpos >= -3.7f) && (xpos <= 3.7f) && (zpos >= -27.1f)) {
		if (zpos <= -25.0f) {
			zpos = -25.0f;
		}
	}
	if ((xpos >= -3.7f) && (xpos <= 3.7f) && (zpos <= -29.3f)) {
		if (zpos >= -31.3f) {
			zpos = -31.3f;
		}
	}
	if ((zpos <= -25.3f) && (zpos >= -31.0f) && (xpos <= 1.5f)) {
		if (xpos >= -4.0f) {
			xpos = -4.0f;
		}
	}
	if ((zpos <= -25.3f) && (zpos >= -31.0f) && (xpos >= -1.5f)) {
		if (xpos <= 4.0f) {
			xpos = 4.0f;
		}
	}
	//bal elsõ oszlop
	if ((xpos >= -12.9f) && (xpos <= -9.1f) && (zpos >= -38.9f)) {
		if (zpos <= -36.9f) {
			zpos = -36.9f;
		}
	}
	if ((xpos >= -12.9f) && (xpos <= -9.1f) && (zpos <= -41.1f)) {
		if (zpos >= -43.1f) {
			zpos = -43.1f;
		}
	}
	if ((zpos <= -37.2f) && (zpos >= -42.9f) && (xpos >= -10.9f)) {
		if (xpos <= -7.9f) {
			xpos = -7.9f;
		}
	}
	if ((zpos <= -37.2f) && (zpos >= -42.9f) && (xpos <= -9.0f)) {
		if (xpos >= -13.9f) {
			xpos = -13.9f;
		}
	}
	//jobb elsõ oszlop
	if ((xpos <= 12.9f) && (xpos >= 9.1f) && (zpos >= -38.9f)) {
		if (zpos <= -36.9f) {
			zpos = -36.9f;
		}
	}
	if ((xpos <= 12.9f) && (xpos >= 9.1f) && (zpos <= -41.1f)) {
		if (zpos >= -43.1f) {
			zpos = -43.1f;
		}
	}
	if ((zpos <= -37.2f) && (zpos >= -42.9f) && (xpos <= 10.9f)) {
		if (xpos >= 7.9f) {
			xpos = 7.8f;
		}
	}
	if ((zpos <= -37.2f) && (zpos >= -42.9f) && (xpos >= 9.0f)) {
		if (xpos <= 13.9f) {
			xpos = 13.9f;
		}
	}
	//bal hátsó oszlop
	if ((xpos >= -13.6f) && (xpos <= -8.2f) && (zpos >= -8.9f)) {
		if (zpos <= -6.9f) {
			zpos = -6.9f;
		}
	}
	if ((xpos >= -13.6f) && (xpos <= -8.2f) && (zpos <= -11.1f)) {
		if (zpos >= -13.1f) {
			zpos = -13.1f;
		}
	}
	if ((zpos <= -7.1f) && (zpos >= -12.9f) && (xpos >= -10.9f)) {
		if (xpos <= -7.9f) {
			xpos = -7.9f;
		}
	}
	if ((zpos <= -7.1f) && (zpos >= -12.9f) && (xpos <= -9.0f)) {
		if (xpos >= -13.9f) {
			xpos = -13.9f;
		}
	}
	//jobb hátsó oszlop
	if ((xpos <= 13.6f) && (xpos >= 8.2f) && (zpos >= -8.9f)) {
		if (zpos <= -6.9f) {
			zpos = -6.9f;
		}
	}
	if ((xpos <= 13.6f) && (xpos >= 8.2f) && (zpos <= -11.1f)) {
		if (zpos >= -13.1f) {
			zpos = -13.1f;
		}
	}
	if ((zpos <= -7.1f) && (zpos >= -12.9f) && (xpos <= 10.9f)) {
		if (xpos >= 7.9f) {
			xpos = 7.8f;
		}
	}
	if ((zpos <= -7.1f) && (zpos >= -12.9f) && (xpos >= 9.0f)) {
		if (xpos <= 13.9f) {
			xpos = 13.9f;
		}
	}
}

void timer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000 / 100, timer, 0);
	if (go_forward == true)	{
		xpos += (float)sin(yrot*3.14f / 180.0f) * 0.2f;
		zpos += (float)cos(yrot*3.14f / 180.0f) * 0.2f;
		collision_detector();
	}
	if (go_backward == true)	{
		xpos -= (float)sin(yrot*3.14f / 180.0f) * 0.2f;
		zpos -= (float)cos(yrot*3.14f / 180.0f) * 0.2f;
		collision_detector();
	}
	if (go_left == true)	{
		xpos += (float)cos(yrot*3.14f / 180.0f) * 0.15f;
		zpos += (float)sin(yrot*3.14f / 180.0f) * -0.15f;
		collision_detector();
	}
	if (go_right == true)	{
		xpos -= (float)cos(yrot*3.14f / 180.0f) * 0.15f;
		zpos -= (float)sin(yrot*3.14f / 180.0f) * -0.15f;
		collision_detector();
	}
	if (look_up == true)	{
		if (xrot >= 87.0f)	{
			xrot = 87.0f;
		}
		else	{
			xrot += 1.0f;
		}
	}
	if (look_down == true)	{
		if (xrot <= -87.0f)	{
			xrot = -87.0f;
		}
		else		{
			xrot -= 1.0f;
		}
	}
	if (turn_left == true)	{
		yrot += 1.0f;		
	}
	if (turn_right == true)	{
		yrot -= 1.0f;
	}
	if (light == true)	{
		for (int i = 0; i<3; i++) {
			light_ambient_menu[i] = 0.8f;
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			light_ambient_menu[i] = 0.0f;
		}
	}
	if (guitar_rot == false) {
		guitar_rot_angle += 1.5f;
	}
	else {
		guitar_rot_angle -= 1.5f;
	}
	if ((state_of_doors == false)) {

		if (L_door_angle >= 0.0) {
			L_door_angle = 0.0;
		}
		else {
			L_door_angle += 3.0;
		}

		if (R_door_angle <= 0.0) {
			R_door_angle = 0.0;
		}
		else {
			R_door_angle -= 3.0;
		}
	}
	else {
		if (L_door_angle <= -90.0) {
			L_door_angle = -90.0;
		}
		else {
			L_door_angle -= 3.0;
		}

		if (R_door_angle >= 90.0) {
			R_door_angle = 90.0;
		}
		else {
			R_door_angle += 3.0;
		}
	}
}

static void key_down(unsigned char key, int x, int y)
{
	bool openable_door = Openeable_controller();
	if ((main_menu == false) && (quit1 == false))	{
		switch (key)	{
		case 'w':
			go_forward = true;
			break;
		case 'W':
			go_forward = true;
			break;
		case 's':
			go_backward = true;
			break;
		case 'S':
			go_backward = true;
			break;
		case 'd':
			go_right = true;
			break;
		case 'D':
			go_right = true;
			break;
		case 'a':
			go_left = true;
			break;
		case 'A':
			go_left = true;
			break;
		case '8':
			look_up = true;
			break;
		case '5':
			look_down = true;
			break;
		case '4':
			turn_left = true;
			break;
		case '6':
			turn_right = true;
			break;
		case 'f':
			if (openable_door == true)			{
				state_of_doors = !state_of_doors;}
			break;
		case 'F':
			if (openable_door == true)			{
				state_of_doors = !state_of_doors;}
			break;
		case 'r':
			guitar_rot = !guitar_rot;
			break;
		case 'R':
			guitar_rot = !guitar_rot;
			break;	
		}
	}
	if (quit1 == false)
	{
		switch (key)	{
		case 13:
			main_menu = false;
			light = false;
			break;
		}
	}

	if (quit1 == true)
	{
		switch (key)	{
		case 'y':
			glutDestroyWindow(1);
			exit(0);
			break;
		case 'Y':
			glutDestroyWindow(1);
			exit(0);
			break;
		}
	}

	if ((main_menu == false) && (help == false))
	{
		switch (key) {
		case 27:
			main_menu = true;
			light = true;
			break;
		}
	}
	else if (help == true)
	{
		switch (key) {
		case 27:
			help = false;
			if(main_menu == false)
				light = false;
			break;
		}
	}
	else
	{
		switch (key) {
		case 27:
			quit1 = true;
			light = true;
			break;
		}
	}

	if ((main_menu == true) && (help == false) && (quit1 == false))
	{
		switch (key) {
		case 'l':
			wait = true;
			active_quality = 1;
			break;
		case 'm':
			wait = true;
			active_quality = 2;
			break;
		case 'h':
			wait = true;
			active_quality = 3;
			break;
		}
	}

	switch (key)	{
		case 'p':
			main_menu = true;
			light = true;
			break;
		case 'P':
			main_menu = true;
			break;
		case 'n':
			quit1 = false;
			if(main_menu == false)
				light = false;
			break;
		case 'N':
			quit1 = false;
			break;
		case '+':
			if (light_diffuse[1]<1.0f) {
				for (int i = 0; i<3; i++) {
					light_diffuse[i] += 0.1f;
					light_menu++;
				}
				light_diffuse[0] = 0.1f;
			}	
			break;
		case '-':
			if (light_diffuse[1]>0.2) {
				for (int i = 0; i<3; i++) {
					light_diffuse[i] -= 0.1f;
					light_menu--;
				}
				light_diffuse[0] = 0.1f;
			}
			break;
		case 'e':
			if (fog_strt < 170.0f)
			{
				fog_strt += 10.0f;
			}
			else {
				fog_strt = 170.0f;
			}
			if (fog_strt >= 140.0f)
				fog_end += 10.0f;
			Fog();
			break;
		case 'q':
			if (fog_strt > 0.0f) {
				fog_strt -= 10.0f;
			}
			else {
				fog_strt = 0.0f;
			}
			if (fog_strt >= 140.0f)
				fog_end -= 10.0f;
			Fog();
			break;
	}
	glutPostRedisplay();
}

static void key_up(unsigned char key, int x, int y)
{
	if ((main_menu == false) && (quit1 == false))	{
		switch (key)		{
		case 'w':
			go_forward = false;
			break;
		case 'W':
			go_forward = false;
			break;
		case 's':
			go_backward = false;
			break;
		case 'S':
			go_backward = false;
			break;
		case 'd':
			go_right = false;
			break;
		case 'D':
			go_right = false;
			break;
		case 'a':
			go_left = false;
			break;
		case 'A':
			go_left = false;
			break;
		case '8':
			look_up = false;
			break;
		case '5':
			look_down = false;
			break;
		case '4':
			turn_left = false;
			break;
		case '6':
			turn_right = false;
			break;
		}
	}
	if ((main_menu == true) && (help == false) && (quit1 == false))
	{
		bool loaded = false;
		switch (key) {
		case 'l':
			world.LoadTextures(1);		
			wait = false;
			active_quality = 1;
			break;
		case 'm':
			world.LoadTextures(2);		
			wait = false;
			active_quality = 2;
			break;
		case 'h':
			world.LoadTextures(3);		
			wait = false;
			active_quality = 3;
			break;
		}
	}

	glutPostRedisplay();
}

void LoadModel()
{
	raptor_model.load("Data/raptor.obj", 0.2f, "Data/raptor.png");
	house_model.load("Data/house.obj", 0.2f, "Data/house.png");
	weapon_model.load("Data/weapon.obj", 0.2f, "Data/weapon.png");
	rock_model.load("Data/Rock1.obj", 0.15f, "Data/Rock1.png");
	mountain_model_small.load("Data/mountain.obj", 1.0f, "Data/mountain.png");
	mountain_model.load("Data/mountain.obj",1.8f, "Data/mountain.png");
	mountain_model_big.load("Data/mountain.obj", 3.8f, "Data/mountain.png");
	mountain_model_biggest.load("Data/mountain.obj", 6.8f, "Data/mountain.png");
	tree_model.load("Data/lowpolytree.obj", 0.6f, "Data/lowpolytree.png");
}

bool LoadGUITextures()                                    // Load Bitmaps And Convert To Textures
{
	char *texture_names[7] = { "Data/help.png","Data/quit.png","Data/mainmenu.jpg","Data/light_set.png","Data/back.png","Data/active_quality.png","Data/wait.jpg" };
		for (int i = 0; i < 7; ++i) {
			textures[i] = SOIL_load_OGL_texture
				(texture_names[i],
					SOIL_LOAD_AUTO,
					SOIL_CREATE_NEW_ID,
					SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO);
			if (textures[i] == 0) {
				cout << "Not found, or corrupt " << texture_names[i] << " .....\n";
				return false;
			}
			else cout << "Loading " << texture_names[i] << " .....\n";
			glBindTexture(GL_TEXTURE_2D, textures[i]);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}	return true;
}

static int Width(char resolution_in)
{
	int width;
	switch (resolution_in){
	case '1':
		width = 640;
		return width;
		break;
	case '2':
		width = 800;
		return width;
		break;
	case '3':
		width = 960;
		return width;
		break;
	case '4':
		width = 1280;
		return width;
		break;
	default:
		return 0;
		break;	}
}

static int Height(char resolution_in)
{
	int height;
	switch (resolution_in)	{
	case '1':
		height = 360;
		return height;
		break;
	case '2':
		height = 450;
		return height;
		break;
	case '3':
		height = 540;
		return height;
		break;
	case '4':
		height = 720;
		return height;
		break;
	default:
		return 0;
		break;	}
}

static void spec(int key, int x, int y) {
	switch (key) {
	case  GLUT_KEY_F1:
		help = !help;
		if ((main_menu == false) && (quit1 == false))
			light = !light;
		break;}
	glutPostRedisplay();
}

static void resize(int width, int height)
{
	aspect_ratio = (float)width / (float)height;
	if (aspect_ratio < 1.77778)	{
		height = (width / 16.0) * 9.0;
		y_difference = ((width / aspect_ratio) - (width / 1.77778)) / 2;
	}
	else if (aspect_ratio > 1.77778)	{
		width = (height / 9.0) * 16.0;
		x_difference = ((height * aspect_ratio) - (height * 1.77778)) / 2;
	}
	glViewport(x_difference, y_difference, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 500.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Startgame()
{
	glLoadIdentity();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[3]);
	glBegin(GL_QUADS);

	glColor4f(1.0f, 1.0f, 1.0f, 0.5f);

	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.4f, 0.07f, -1.3f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.4f, 0.07f, -1.3f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.4f, 0.18f, -1.3f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.4f, 0.18f, -1.3f);

	glEnd();
}

void Low()
{
	glLoadIdentity();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[3]);
	glBegin(GL_QUADS);

	glColor4f(1.0f, 1.0f, 1.0f, 0.5f);

	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.75f, -0.54f, -1.3f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.23f, -0.54f, -1.3f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.23f, -0.445f, -1.3f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.75f, -0.445f, -1.3f);

	glEnd();
}

void Medium()
{
	glLoadIdentity();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[3]);
	glBegin(GL_QUADS);

	glColor4f(1.0f, 1.0f, 1.0f, 0.5f);

	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.23f, -0.54f, -1.3f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.32f, -0.54f, -1.3f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.32f, -0.445f, -1.3f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.23f, -0.445f, -1.3f);

	glEnd();
}

void High()
{
	glLoadIdentity();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[3]);
	glBegin(GL_QUADS);

	glColor4f(1.0f, 1.0f, 1.0f, 0.5f);

	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.32f, -0.54f, -1.3f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.75f, -0.54f, -1.3f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.75f, -0.445f, -1.3f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.32f, -0.445f, -1.3f);

	glEnd();
}

void Active_quality()
{
	float a, b;
	if (active_quality == 1)
		a = -0.75f, b = -0.23f;
	else if (active_quality == 2)
		a = -0.23f, b = 0.32f;
	else if (active_quality == 3)
		a = 0.32f, b = 0.75f;
	glLoadIdentity();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[5]);
	glBegin(GL_QUADS);

	glColor4f(1.0f, 1.0f, 1.0f, 0.2f);

	glTexCoord2f(1.0f, 0.0f); glVertex3f(a, -0.54f, -1.3f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(b, -0.54f, -1.3f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(b, -0.445f, -1.3f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(a, -0.445f, -1.3f);

	glEnd();
}

void Wait()
{
	if (wait == true)
	{
		glLoadIdentity();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textures[6]);
		glBegin(GL_QUADS);

		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

		glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.3f, -0.15f, -1.2f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.3f, -0.15f, -1.2f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.3f, 0.15f, -1.2f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.3f, 0.15f, -1.2f);

		glEnd();
	}
}

void Help()
{
	glLoadIdentity();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[3]);
	glBegin(GL_QUADS);
	glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.4f, -0.09f, -1.3f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.4f, -0.09f, -1.3f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.4f, 0.02f, -1.3f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.4f, 0.02f, -1.3f);
	glEnd();
}

void Exit()
{
	glLoadIdentity();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[3]);
	glBegin(GL_QUADS);
	glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.4f, -0.26f, -1.3f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.4f, -0.26f, -1.3f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.4f, -0.15f, -1.3f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.4f, -0.15f, -1.3f);
	glEnd();
}

void Exit_yes() {
	glLoadIdentity();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[3]);
	glBegin(GL_QUADS);
	glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.238f, -0.092f, -1.1f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, -0.092f, -1.1f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.0f, -1.1f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.238f, 0.0f, -1.1f);
	glEnd();
}
void Exit_no() {
	glLoadIdentity();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[3]);
	glBegin(GL_QUADS);
	glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, -0.092f, -1.1f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.238f, -0.092f, -1.1f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.238f, 0.0f, -1.1f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, 0.0f, -1.1f);
	glEnd();
}

void Help_back()
{
	glLoadIdentity();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[4]);
	glBegin(GL_QUADS);
	glColor4f(1.0f, 1.0f, 1.0f, 0.9f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, -0.52f, -1.15f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.8f, -0.52f, -1.15f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.8f, -0.25f, -1.15f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, -0.25f, -1.15f);
	glEnd();

}

static void display(void)
{
	//glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
	glLoadIdentity();
	/*mozgás, forgás*/glMatrixMode(GL_MODELVIEW);
	float verticalAngle = ToRad(xrot);
	float horizontalAngle = ToRad(yrot);

	float dx = cos(verticalAngle) * sin(horizontalAngle);
	float dy = sin(verticalAngle);
	float dz = cos(verticalAngle) * cos(horizontalAngle);

	float cx = xpos + dx, cy = ypos + dy, cz = zpos + dz;
	gluLookAt(xpos, ypos, zpos, cx, cy, cz, 0, 1, 0);/*mozgás, forgás vége*/

	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient_menu);

	glPushMatrix();
	glTranslatef(8.0f, 1.0f, -10.0f);
	glLightfv(GL_LIGHT5, GL_AMBIENT, light_ambient);

	glLightfv(GL_LIGHT0, GL_POSITION, light_position_front_left);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light_direction);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPOT_CUTOFF, cut);

	glLightfv(GL_LIGHT2, GL_POSITION, light_position_front_right);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, light_direction);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT2, GL_SPOT_CUTOFF, cut);

	glLightfv(GL_LIGHT3, GL_POSITION, light_position_back_left);
	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, light_direction);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT3, GL_SPOT_CUTOFF, cut);

	glLightfv(GL_LIGHT4, GL_POSITION, light_position_back_right);
	glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, light_direction);
	glLightfv(GL_LIGHT4, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT4, GL_SPOT_CUTOFF, cut);

	glPopMatrix();

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_LINE_SMOOTH);
	//modellek kirajzolása/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    house_model.draw(-30, 2.5, -120);
	raptor_model.draw(100, 0, -80);
	raptor_model.draw(70, 0, -130);
	weapon_model.draw(-15, 1.5, 8.0);
	rock_model.draw(2.5, -1.1, -81);
	rock_model.draw(-2.5, -1.1, -106);
	rock_model.draw(0.5, -1.1, -113);
	rock_model.draw(-0.8, -1.1, -93);
	mountain_model_small.draw(30,-1,-130);
	mountain_model_small.draw(40, 0, -120);
	mountain_model.draw(40, -2, -150);
	mountain_model.draw(-30, -2, -190);
	mountain_model.draw(50, -1.5, -105);
	mountain_model_big.draw(-70, -2, -180);
	mountain_model_big.draw(80, -5, -40);
	mountain_model_big.draw(-50, -16, -90);
	mountain_model_big.draw(-52, -15, -65);
	mountain_model_biggest.draw(-100,-15,-70);
	mountain_model_biggest.draw(-140, -6,-10);
	tree_model.draw(15,-2,-120);
	//modell kirajzolás vége/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	world.Draw_World_Pub(guitar_rot_angle, L_door_angle, R_door_angle);

	glDisable(GL_TEXTURE_2D);
	//segítség menü textúra
	if (help) {
		glLoadIdentity();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textures[0]);
		glBegin(GL_QUADS);
		glColor4f(1.0f, 1.0f, 1.0f, 0.9f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -0.55f, -1.3f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -0.55f, -1.3f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 0.55f, -1.3f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 0.55f, -1.3f);
		glEnd();
	}
	// kilepes menu textúra
	if (quit1 == true) {
		glLoadIdentity();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textures[1]);
		glBegin(GL_QUADS);
		glColor4f(1.0f, 1.0f, 1.0f, 0.9f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -0.55f, -1.2f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -0.55f, -1.2f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 0.55f, -1.2f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 0.55f, -1.2f);
		glEnd();
	}
	// fõmenu textúra
	if (main_menu == true) {
		glLoadIdentity();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textures[2]);
		glBegin(GL_QUADS);
		glColor4f(1.0f, 1.0f, 1.0f, 0.9f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.05f, -0.6f, -1.4f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(1.05f, -0.6f, -1.4f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(1.05f, 0.6f, -1.4f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.05f, 0.6f, -1.4f);
		glEnd();
		//hangerõ csúszka
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		if (light_menu == 0)		{
			glLoadIdentity();
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, textures[3]);
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(0.815f, -0.27f, -1.3f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(0.87f, -0.27f, -1.3f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(0.87f, -0.24f, -1.3f);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(0.815f, -0.24f, -1.3f);
			glEnd();
		}
		if (light_menu == 3)		{
			glLoadIdentity();
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, textures[3]);
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(0.815f, -0.23f, -1.3f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(0.87f, -0.23f, -1.3f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(0.87f, -0.20f, -1.3f);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(0.815f, -0.20f, -1.3f);
			glEnd();
		}
		if (light_menu == 6)		{
			glLoadIdentity();
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, textures[3]);
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(0.815f, -0.19f, -1.3f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(0.87f, -0.19f, -1.3f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(0.87f, -0.16f, -1.3f);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(0.815f, -0.16f, -1.3f);
			glEnd();
		}
		if (light_menu == 9)		{
			glLoadIdentity();
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, textures[3]);
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(0.815f, -0.145f, -1.3f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(0.87f, -0.145f, -1.3f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(0.87f, -0.115f, -1.3f);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(0.815f, -0.115f, -1.3f);
			glEnd();
		}
		if (light_menu == 12)		{
			glLoadIdentity();
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, textures[3]);
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(0.815f, -0.10f, -1.3f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(0.87f, -0.10f, -1.3f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(0.87f, -0.07f, -1.3f);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(0.815f, -0.07f, -1.3f);
			glEnd();
		}
		if (light_menu == 15)	{
			glLoadIdentity();
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, textures[3]);
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(0.815f, -0.055f, -1.3f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(0.87f, -0.055f, -1.3f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(0.87f, -0.025f, -1.3f);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(0.815f, -0.025f, -1.3f);
			glEnd();
		}
		if (light_menu == 18)	    {
			glLoadIdentity();
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, textures[3]);
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(0.815f, -0.005f, -1.3f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(0.87f, -0.005f, -1.3f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(0.87f, 0.025f, -1.3f);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(0.815f, 0.025f, -1.3f);
			glEnd();
		}
		if (light_menu == 21)		{
			glLoadIdentity();
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, textures[3]);
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(0.815f, 0.045f, -1.3f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(0.87f, 0.045f, -1.3f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(0.87f, 0.075f, -1.3f);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(0.815f, 0.075f, -1.3f);
			glEnd();
		}
		if (light_menu == 24)		{
			glLoadIdentity();
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, textures[3]);
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(0.815f, 0.11f, -1.3f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(0.87f, 0.11f, -1.3f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(0.87f, 0.14f, -1.3f);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(0.815f, 0.14f, -1.3f);
			glEnd();
		}
		if (light_menu == 27)		{
			glLoadIdentity();
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, textures[3]);
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(0.815f, 0.16f, -1.3f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(0.87f, 0.16f, -1.3f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(0.87f, 0.19f, -1.3f);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(0.815f, 0.19f, -1.3f);
			glEnd();
		}
		if (clck_start == true)
		{
			Startgame();
		}
		if (clck_help == true)
		{
			Help();
		}
		if (clck_low == true)
		{
			Low();
		}
		if (clck_med == true)
		{
			Medium();
		}
		if (clck_hi == true)
		{
			High();
		}
		if (clck_quit == true)
		{
			Exit();
		}
		Active_quality();
		Wait();
	}	
	if (clck_yes == true)
	{
		Exit_yes();
	}
	if (clck_no == true)
	{
		Exit_no();
	}
	if (help_back == true)
	{
		Help_back();
	}
	glutSwapBuffers();
}

void MouseClicks(int button, int state, int x, int y)
{

	if (aspect_ratio > 1.77778)
	{
		// fõmenü start gomb
		if ((quit1 == false) && (help == false) && (main_menu == true))
		{
			if ((y >= (height_global / 3) - y_difference) && (y <= (height_global / 2.3) - y_difference) && (x >= (width_global / 4) + x_difference) && (x <= ((width_global / 4) * 3) + x_difference)) {
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_UP))
				{
					main_menu = false;
					light = false;
				}
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_DOWN))
				{
					clck_start = true;
				}
			}
			// fõmenü help gomb
			if ((y >= (height_global / 2.1) - y_difference) && (y <= (height_global / 1.8) - y_difference) && (x >= (width_global / 4) + x_difference) && (x <= ((width_global / 4) * 3) + x_difference))
			{
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_UP))
				{
					help = true;
				}
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_DOWN))
				{
					clck_help = true;
				}
			}
			// fõmenü kilépés gomb
			if ((y >= ((height_global / 3) * 1.9) - y_difference) && (y <= (height_global / 1.385) - y_difference) && (x >= (width_global / 4) + x_difference) && (x <= ((width_global / 4) * 3) + x_difference))
			{
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_UP))
				{
					quit1 = true;
				}
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_DOWN))
				{
					clck_quit = true;
				}
			}
			// fõmenü alacsony gomb
			if ((y >= (height_global / 1.11) - y_difference) && (y <= height_global - y_difference) && (x >= (width_global / 8.53) + x_difference) && (x <= (width_global / 2.56) + x_difference))
			{
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_UP))
				{
					world.LoadTextures(1);
					active_quality = 1;
				}
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_DOWN))
				{
					clck_low = true;
					wait = true;
				}
			}
			// fõmenü közepes gomb
			if ((y >= (height_global / 1.11) - y_difference) && (y <= height_global - y_difference) && (x >= (width_global / 2.56) + x_difference) && (x <= (width_global / 1.515) + x_difference))
			{
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_UP))
				{
					world.LoadTextures(2);
					active_quality = 2;
				}
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_DOWN))
				{
					clck_med = true;
					wait = true;
				}
			}
			// fõmenü magas gomb
			if ((y >= (height_global / 1.11) - y_difference) && (y <= height_global - y_difference) && (x >= (width_global / 1.515) + x_difference) && (x <= (width_global / 1.155) + x_difference))
			{
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_UP))
				{
					world.LoadTextures(3);
					active_quality = 3;
				}
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_DOWN))
				{
					clck_hi = true;
					wait = true;
				}
			}
		}
		if (quit1 == true)
		{
			if ((y >= (height_global / 2.05)) && (y <= height_global / 1.65) && (x >= (width_global / 3) + x_difference) && (x <= ((width_global / 2)) + x_difference))
			{
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_UP))
				{
					glutDestroyWindow(1);
					exit(0);
				}
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_DOWN))
				{
					clck_yes = true;
				}
			}
			if ((y >= (height_global / 2.05)) && (y <= height_global / 1.65) && (x <= ((width_global / 3)*2) + x_difference) && (x >= ((width_global / 2)) + x_difference))
			{
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_UP))
				{
					quit1 = false;
					if (main_menu == false)
						light = false;
				}
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_DOWN))
				{
					clck_no = true;
				}
			}
		}
		if (help == true)
		{
			if ((y >= ((height_global / 5) * 4)) && (y <= (height_global)) && (x >= ((width_global / 6) * 5) + x_difference) && (x <= ((width_global / 32) * 31)) + x_difference)
			{
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_UP))
				{
					help = false;
					if (main_menu == false)
						light = false;
				}
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_DOWN))
				{
					help_back = true;
				}
			}
		}
	}
	else
	{
		// fõmenü start gomb
		if ((quit1 == false) && (help == false) && (main_menu == true))
		{
			if ((y >= (height_global / 3) + y_difference) && (y <= (height_global / 2.3) + y_difference) && (x >= (width_global / 4) - x_difference) && (x <= ((width_global / 4) * 3) - x_difference)) {
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_UP))
				{
					main_menu = false;
					light = false;
				}
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_DOWN))
				{
					clck_start = true;
				}
			}
			// fõmenü help gomb
			if ((y >= (height_global / 2.1) + y_difference) && (y <= (height_global / 1.8) + y_difference) && (x >= (width_global / 4) - x_difference) && (x <= ((width_global / 4) * 3) - x_difference))
			{
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_UP))
				{
					help = true;
				}
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_DOWN))
				{
					clck_help = true;
				}
			}
			// fõmenü kilépés gomb
			if ((y >= ((height_global / 3) * 1.9) + y_difference) && (y <= (height_global / 1.385) + y_difference) && (x >= (width_global / 4) - x_difference) && (x <= ((width_global / 4) * 3) - x_difference))
			{
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_UP))
				{
					quit1 = true;
				}
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_DOWN))
				{
					clck_quit = true;
				}
			}
			// fõmenü alacsony gomb
			if ((y >= (height_global / 1.11) + y_difference) && (y <= height_global + y_difference) && (x >= (width_global / 8.53) - x_difference) && (x <= (width_global / 2.56) - x_difference))
			{
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_UP))
				{
					world.LoadTextures(1);
					active_quality = 1;
				}
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_DOWN))
				{
					clck_low = true;
					wait = true;
				}
			}
			// fõmenü közepes gomb
			if ((y >= (height_global / 1.11) + y_difference) && (y <= height_global + y_difference) && (x >= (width_global / 2.56) - x_difference) && (x <= (width_global / 1.515) - x_difference))
			{
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_UP))
				{
					world.LoadTextures(2);
					active_quality = 2;
				}
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_DOWN))
				{
					clck_med = true;
					wait = true;
				}
			}
			// fõmenü magas gomb
			if ((y >= (height_global / 1.11) + y_difference) && (y <= height_global + y_difference) && (x >= (width_global / 1.515) - x_difference) && (x <= (width_global / 1.155) - x_difference))
			{
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_UP))
				{
					world.LoadTextures(3);
					active_quality = 3;
				}
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_DOWN))
				{
					clck_hi = true;
					wait = true;
				}
			}
		}
		if (quit1 == true)
		{
			if ((y >= ((height_global / 2.05)) + y_difference) && (y <= (height_global / 1.65) + y_difference) && (x >= (width_global / 3)) && (x <= ((width_global / 2))))
			{
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_UP))
				{
					glutDestroyWindow(1);
					exit(0);
				}
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_DOWN))
				{
					clck_yes = true;
				}
			}
			if ((y >= ((height_global / 2.05)) + y_difference) && (y <= (height_global / 1.65) + y_difference) && (x <= ((width_global / 3) * 2)) && (x >= ((width_global / 2))))
			{
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_UP))
				{
					quit1 = false;
					if (main_menu == false)
						light = false;
				}
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_DOWN))
				{
					clck_no = true;
				}
			}
		}
		if (help == true)
		{
			if ((y >= ((height_global / 5)*4) + y_difference) && (y <= (height_global) + y_difference) && (x >= (width_global / 6)*5) && (x <= (width_global/32)*31))
			{
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_UP))
				{
					help = false;
					if (main_menu == false)
						light = false;
				}
				if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_DOWN))
				{
					help_back = true;
				}
			}
		}
	}
	if ((button == GLFW_MOUSE_BUTTON_LEFT) && (state == GLUT_UP))
	{
		clck_start = false;
		clck_help = false;
		clck_quit = false;
		clck_low = false;
		clck_med = false;
		clck_hi = false;
		clck_yes = false;
		clck_no = false;
		wait = false;
		help_back = false;
	}
}
 
int main(int argc, char *argv[])
{
	char resolution_in, quality_in;
	bool full_screen = false, wrong = false, wrong_q = false;
	do	{
		if (wrong == true)	{
			cout << "Hibas karaktermegadas, kerem adja meg ujra!\n";	}
		cout << "Valassza ki a felbontast!\n     1-es gomb: 640x360(ablakos)\n     2-es gomb: 800x450(ablakos)\n     3-as gomb: 960x540(ablakos)\n     4-es gomb: 1280x720(ablakos)\n     5-os gomb: Teljes kepernyo\n";
		cin >> resolution_in;
		if (resolution_in == '5')	{
			full_screen = true;
			width_global = 1920;
			height_global = 1080;
			break;
		}
		width_global = Width(resolution_in);
		height_global = Height(resolution_in);
		if ((width_global == 0) || (height_global == 0))
			wrong = true;
	} while ((width_global == 0) || (height_global == 0));
	cout << "Initalize window.....\n";
	glutInit(&argc, argv);
	cout << "Setting up the window size.....\n";
	glutInitWindowSize(width_global, height_global);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_ALPHA);
	int window = glutCreateWindow("Kiallitas");
	glutSetWindow(window);

	cout << "Callbacks.....\n";
	glutTimerFunc(0, timer, 0);
	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutSpecialFunc(spec);
	glutKeyboardFunc(key_down);
	glutKeyboardUpFunc(key_up);
	glutMouseFunc(MouseClicks);

	cout << "Setting up the default color.....\n";
	glClearColor(0.6, 0.9, 1.0, 1); //háttérszín
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);
	glEnable(GL_LIGHT4);
	glEnable(GL_LIGHT5);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glShadeModel(GL_SMOOTH);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDepthFunc(GL_LESS);

	cout << "Turning on the lights.....\n";
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	GLfloat material[] = { 0.5,0.5,0.5,1 };
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, material);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_ambient);
	cout << "Window identifier: " << window << "\n";
	cout << "Initalize fog.....\n";
	if (full_screen == true){
		glutFullScreen();	}
	LoadGUITextures();
	world.LoadTextures(1);
	Fog();
    LoadModel();
	glutMainLoop();
	return 0;
}
