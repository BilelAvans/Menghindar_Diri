#include "HighScoreMenuItem.h"
#include "StaticOpenGLFunctions.h"

#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <iostream>
#include <sstream>

void HighscoreMenuItem::Fun() {
		int startX = 350;
		int startY = 500;
		// Allez, Allez, commencons avec le premier
		int position = 1;

		std::stringstream haha;

		for (int score : hScore.getTopTenScores()) {
			haha << position;
			haha << ". ";
			haha << score;

			drawText(startX, startY, (char*)haha.str().c_str());

			haha.clear();
			startY -= 50;


			// Reset
			startX = 350;
			haha.clear();
			position++;
		}

		

}
