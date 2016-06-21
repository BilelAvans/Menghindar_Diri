#include "HighScoreMenuItem.h"
#include "StaticOpenGLFunctions.h"

#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <iostream>
#include <sstream>

void HighscoreMenuItem::Fun() {
		int startX = 365;
		int startY = 475;
		// Allez, Allez, commencons avec le premier
		int position = 1;

		vector<int> scores = hScore.getTopTenScores();
		int score;

		for (int position = 1; position < scores.size(); position++, startY -= 30) {
			score = scores.at(scores.size() - position);
			std::stringstream haha;
			haha << position;
			haha << ". ";
			haha << score;

			drawText(startX, startY, (char*)haha.str().c_str());

			haha.clear();
		}

		

}
