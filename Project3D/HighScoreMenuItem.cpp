#include "HighScoreMenuItem.h"
#include "StaticOpenGLFunctions.h"

#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <iostream>
#include <sstream>

void HighscoreMenuItem::Fun() {
	// Draw scores
	vector<int> scores = vector<int>{ 1, 2, 4 };
	scores.push_back(10);
	scores.push_back(110);
	scores.push_back(120);

	int startX = 350;
	int startY = 500;
	// Allez, Allez, commencons avec le premier
	int position = 1;

	std::stringstream haha;

	for (int score : scores) {
		haha << position;
		drawText(startX, startY, (char*)haha.str().c_str());

		haha.clear();
		startY += 100;

		haha << score;
		char* char_type = (char*)haha.str().c_str();
		// draw 
		drawText(startX, startY, char_type);
		startY += 40;

		// Reset
		startX = 350;
		haha.clear();
	}

}
