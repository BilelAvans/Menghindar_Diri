//
// Created by Gilian Joosen on 08/06/16.
//

#include <iostream>
#include <algorithm>
#include <fstream>
#include "Highscore.h"

using namespace std;

void Highscore::readHighscores() {

	ifstream read("highscores.txt");
	int lines;
	read >> lines;

	//read number of lines
	scores = new vector<int>(0);

	//read the lines and add the numbers to the file
	for (int i = 0; i < lines; i++) {
		int num;
		read >> num;
		scores->push_back(num);
	}

	//sort the list
	this->sort();

	//close stream
	read.close();
}

void Highscore::writeScoresToFile() {
	//write the scores to a file

	//open stream
	ofstream writeStream("highscores.txt");

	//write number of scores in vector
	writeStream << scores->size() << endl;

	//write the scores
	for (int i = 0; i < scores->size(); i++) {
		writeStream << (*scores)[i] << endl;
	}

	//close stream
	writeStream.close();
}

void Highscore::addScore(int score) {
	scores->push_back(score);
	this->sort();
	this->writeScoresToFile();
}

void Highscore::printHighscores() {
	cout << "scores: ";
	for (int i = 0; i < scores->size(); i++) {
		cout << (*scores)[i] << " - ";
	}
	cout << endl;
}

void Highscore::sort() {
	std::sort(scores->begin(), scores->end());
}

int Highscore::getHighscoreRank(int score) {
	for (int i = 0; i < scores->size(); i++) {
		if ((*scores)[i] == score) {
			return i + 1;
		}
	}
	return -1;
}

vector<int> Highscore::getTopTenScores() {
	//number of scores in scores vector
	int numberofscores = scores->size();

	if (numberofscores > 10)
		numberofscores = 10;

	vector<int> topscores = vector<int>(numberofscores);

	for (int i = 0; i < numberofscores; i++)
		topscores[i] = (*scores)[i];

	return *scores;
}