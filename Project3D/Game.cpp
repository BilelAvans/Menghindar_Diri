#include "Game.h"

#define KEY_ESCAPE 27

using namespace std;

SoundPlayer sound("Sounds/New2.ogg");
SoundPlayer hitSound("Sounds/Hit.mp3");

thread logic;

Player* player;

bool threadRunning = false;

glutWindow win;
GameController *w;

Node *a;
//= ModelObject((char *) "Models/lowPolyAirplane/lowPolyAirplane.obj");
struct Camera
{
	float posX = 10;
	float posY = -170; //-150 default
	float posZ = -10;
	float rotX = 0;
	float rotY = 0;
} camera;

Node *node;

Game::Game() {

}

Game::Game(void(*backspacefunc)(), void(*endfunc)(char*), GameController *gc) {
	backspaceFunc = backspacefunc;
	endFunc = endfunc;
	w = gc;
}

void hud()
{

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0.0, win.width, win.height, 0.0, -1.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	//glPushMatrix();        ----Not sure if I need this
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
	glScalef(0.2, 0.2, 1);
	glRotatef(180, 1, 0, 0);
	for (char* p = score_char; *p; p++)
	{
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *p);
	}
	glPopMatrix();
	//glutStrokeCharacter(GLUT_STROKE_ROMAN, *score_c);


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

	//glRotatef(g_rotation, 0, 1, 0);
	//g_rotation++;
	glRotatef(camera.rotX, 1, 0, 0);
	glRotatef(camera.rotY, 0, 1, 0);

	for (int i = 0; i < 10; i++)
	{

		glPushMatrix();
		enemybuffer1[i].Draw();
		glPopMatrix();
	}


	player->Draw();
	hud();
	node->draw();

	hud();

	glutSwapBuffers();

}

void Game::mousePassiveMotion(int x, int y)
{
	//	int dx = x - win.width / 2;
	//	int dy = y - win.height / 2;
	//	if ((dx != 0 || dy != 0) && abs(dx) < 400 && abs(dy) < 400)
	//	{
	//		camera.rotY += dx / 10.0f;
	//		camera.rotX += dy / 10.0f;
	//		glutWarpPointer(win.width / 2, win.height / 2);
	//	}
}

void initialize()
{
	init();
	create(10);
	w->connect();
	glMatrixMode(GL_PROJECTION);
	glViewport(0, 0, win.width, win.height);
	GLfloat aspect = (GLfloat)win.width / win.height;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(win.field_of_view_angle, aspect, win.z_near, win.z_far);
	glMatrixMode(GL_MODELVIEW);
	//glShadeModel(GL_SMOOTH);
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
	//	player = new Player(-10,0,130,1,1,1,new Node(new ObjModel("Models/bloemetje/PrimroseP.obj")));

	initSkybox();
	//player = new Player(-10,0,130,1,1,1,new ModelObject("Models/lowPolyAirplane/lowPolyAirplane.obj"));


	//full screen
	glutFullScreen();

}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case KEY_ESCAPE:
		Stop();
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
		Sleep(20);
#endif
		posnextConti();
		if (collisioncheck(player)) {
			hitSound.PlaySoundje();
			if (player->life == 0) { // Out of lives
				threadRunning = false;
				Stop();
			}
		}
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
	//glutInit(&argc, argv);                                      // GLUT initialization
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);  // Display Mode
	//glutInitWindowSize(win.width, win.height);					// set window size
	glutDestroyWindow(glutGetWindow());
	glutCreateWindow("Glut");
	//glutCreateWindow(win.title);								// create Window
	glutDisplayFunc(display);						// register Display Function
	glutIdleFunc(idle);							// register Idle Function
	glutKeyboardFunc(keyboard);						// register Keyboard Handler
	glEnable(GLUT_MULTISAMPLE);									// Enable Multisampling
	initialize();
	w->connect();
	logic = std::thread(logics);
	// Set Volumes
	sound.setVolume((float)MusicVolume / float(100));
	hitSound.setVolume((float)EffectVolume / float(100));

	sound.PlaySoundje();

	glutMainLoop();												// run GLUT mainloop
																//return 0;
}

void Stop() {
	sound.Stop();
	logic.detach();
	threadRunning = false;
	glLoadIdentity();
	glDisable(GL_LIGHTING);

	backspaceFunc();
}

Game::~Game() {
	sound.Stop();
}
