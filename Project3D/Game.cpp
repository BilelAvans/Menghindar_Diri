#include "Game.h"

#include "Controls\wiimote\WiiMoteController.h"
#include <iostream>
#include <cstdio>
#include <string.h>

using namespace irrklang;
#define KEY_ESCAPE 27
using namespace std;

SoundPlayer *sound = SoundPlayer::ofThemeSong();
SoundPlayer hitSound(string ("Sounds/Krah.ogg"));

thread logic;
thread control;
Player* player;
bool threadRunning = false;
glutWindow win;
GameController *w;
Node *a;
Node *node;
float lastFrameTime;

bool shouldStop = false;

void EndToHighScores();

void(*endFunc)();
void(*highscoreFunc)(int);

struct Camera
{
	float posX = 10;
	float posY = -170; //-150 default
	float posZ = -10;
	float rotX = 0;
	float rotY = 0;
} camera;

Game::Game(void(*backspacefunc)(), void(*endfunc)(int), GameController *gc, bool running) {
	endFunc = backspacefunc;
	highscoreFunc = endfunc;
	if (!running) {
		w = gc;
	}
	
}

void hud()
{

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0.0, win.width, win.height, 0.0, -1.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glDisable(GL_CULL_FACE);
	glClear(GL_DEPTH_BUFFER_BIT);
	string score_str = "SCORE:" + to_string(player->score);
	char score_char[1024];
#ifdef __APPLE__
	strcpy(score_char, score_str.c_str());
#else
	strcpy_s(score_char, score_str.c_str());
#endif
	string lives_str = "LIVES:" + to_string(player->life);
	char lives_char[1024];
#ifdef __APPLE__
	strcpy(lives_char, lives_str.c_str());
#else
	strcpy_s(lives_char, lives_str.c_str());
#endif
	glPushMatrix();
	glTranslatef(10, 60, 0);
	glScalef(0.2, 0.2, 1);
	glRotatef(180, 1, 0, 0);
	for (char* p = lives_char; *p; p++)
	{
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *p);
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(10, 30, 0);
	glScalef(0.2f, 0.2f, 1);
	glRotatef(180, 1, 0, 0);
	for (char* p = score_char; *p; p++)
	{
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *p);
	}
	glPopMatrix();
	// Making sure we can render 3d again
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	//skybox
	glPushMatrix();
	glRotatef(180, 1, 0, 0);
	drawSkybox(400.0);
	glPopMatrix();
	glTranslatef(camera.posX, camera.posZ, camera.posY);
	glRotatef(camera.rotX, 1, 0, 0);
	glRotatef(camera.rotY, 0, 1, 0);

	for (int i = 0; i < 10; i++)
	{
		if (enemybuffer1[i].powers = true) {
			glPushMatrix();
			//glColor3f(0.5f, 0.5f, 0.5f);
			enemybuffer1[i].Draw();


			glPopMatrix();
		}
		else {
			glPushMatrix();
			enemybuffer1[i].Draw();
			glPopMatrix();
		}
	}

	player->Draw();
	hud();
	node->draw();
	hud();
	glutSwapBuffers();
	
}

void initialize()
{
	init();
	create(10);

	glMatrixMode(GL_PROJECTION);
	glViewport(0, 0, win.width, win.height);
	GLfloat aspect = (GLfloat)win.width / win.height;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(win.field_of_view_angle, aspect, win.z_near, win.z_far);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(0.0f, 0.1f, 0.0f, 0.5f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_TEXTURE_2D);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_FASTEST);
	glutWarpPointer(win.width / 2, win.height / 2);

	node = new Node(new ObjModel("Models/bloemetje/PrimroseP.obj"));
	a = new Node(new ObjModel("Models/bloemetje/PrimroseP.obj"));

	// Light 1
	GLfloat amb_light[] = { (GLfloat)0.1, (GLfloat)0.1, (GLfloat)0.1, (GLfloat)1.0 };
	GLfloat diffuse[] = { (GLfloat)0.6, (GLfloat)0.6, (GLfloat)0.6, (GLfloat)1 };
	GLfloat specular[] = { (GLfloat)0.7,(GLfloat) 0.7,(GLfloat) 0.3, (GLfloat)1 };

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb_light);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glShadeModel(GL_SMOOTH);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	player = new Player(-10, 0, 130, 1, 1, 1, new Node(new ObjModel("Models/lowPolyAirplane/lowPolyAirplane.obj")));
	initSkybox();
	//full screen
	//glutFullScreen();

}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case KEY_ESCAPE:
		EndToHighScores();
		break;
	case 'a':
		//		camera.posX++;
		player->move(-1, 0, 0);
		break;
	case 'd':
		//		camera.posX--;
		player->move(1, 0, 0);
		break;
	default:
		break;
	}
}

void idle() {

	if (player->life == 0 && threadRunning) {
		EndToHighScores();
		return;
	}

	//repaint
	display();
}

void logics() {
	threadRunning = true;
	while (threadRunning)
	{

#ifdef __APPLE__
		usleep(20 * 1000);
#else
		if (player->score < 5000) {
			Sleep(20-(player->score/1000.0));
		}
		else {
			Sleep(20-5);
		}
#endif
		posnextConti();
		if (collisioncheck(player)) {
			hitSound.PlaySoundje();
		}
	}
}
void controls() {
	threadRunning = true;
	double speed = 10;
	while (threadRunning)
	{
		float frameTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
		float deltaTime = frameTime - lastFrameTime;
		lastFrameTime = frameTime;
		
#ifdef __APPLE__
		usleep(20 * 1000);
#else
		Sleep(20);
#endif
		if (threadRunning)
			player->move(-w->leftRightMovement()*deltaTime*speed, 0, 0);
	}
}


void Run()
{
	win.width = 1200;
	win.height = 720;
	win.title = (char *) "Menghindar? DIRI?!?!.";
	win.field_of_view_angle = 45;
	win.z_near = 1.0f;
	win.z_far = 500.0f;

	// initialize and run program
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);  // Display Mode
	//glutInitWindowSize(win.width, win.height);					// set window size
	glutDestroyWindow(glutGetWindow());
	glutCreateWindow("Glut");
	glutDisplayFunc(display);						// register Display Function
	glutIdleFunc(idle);							// register Idle Function
	glutKeyboardFunc(keyboard);						// register Keyboard Handler
	glEnable(GLUT_MULTISAMPLE);									// Enable Multisampling
	initialize();

//	w->connect();
	logic = std::thread(logics);
	control = std::thread(controls);
	// Set Volumes
	sound->setVolume(MusicVolume);
	hitSound.setVolume(EffectVolume);

	sound->PlaySoundje();
	glutFullScreen();
	glutMainLoop();												// run GLUT mainloop
}

void Stop() {
	threadRunning = false;
	sound->Stop();
	logic.detach();
	control.detach();

	endFunc();
}

void EndToHighScores() {
	threadRunning = false;

	sound->Stop();
	logic.detach();
	control.detach();

	highscoreFunc(player->score);
}


Game::~Game() {
	
	delete(sound);
}

