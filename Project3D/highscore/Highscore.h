//
// Created by Gilian Joosen on 08/06/16.
//

#ifndef MENGHINDAR_DIRI_HIGHSCORE_H
#define MENGHINDAR_DIRI_HIGHSCORE_H

#include <vector>

using namespace std;

class Highscore {
	public:
		void readHighscores();
		void addScore(int score);
		void printHighscores();
		void writeScoresToFile();
		int getHighscoreRank(int score);


	private:
		vector<int> *scores;
		void sort();
};


#endif //MENGHINDAR_DIRI_HIGHSCORE_H
