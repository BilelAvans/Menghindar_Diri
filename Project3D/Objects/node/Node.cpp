//
// Created by Gilian Joosen on 13/05/16.
//

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>

#else
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#include "Node.h"
#include "../ObjModel.h"

Node::Node(ObjModel *model) {
	this->model = model;
}

void Node::draw() {
	//translate
	glTranslatef(translate[0], translate[1], translate[2]);

	//rotate
	glRotatef(rotate[0], 1, 0, 0);
	glRotatef(rotate[1], 0, 1, 0);
	glRotatef(rotate[2], 0, 0, 1);



	//teken het model
	if(this->model != nullptr)
		this->model->draw();

	//tekenen de sub models
	for(Node* n: this->subnodes)
		n->draw();

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

Node::Node(ObjModel *model, vector<Node *> subnodes) {
	this->model = model;
	this->subnodes = subnodes;
}

