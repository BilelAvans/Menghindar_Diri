//
// Created by Gilian Joosen on 17/05/16.
//

#ifndef MENGHINDAR_DIRI_GAMECONTROLLER_H
#define MENGHINDAR_DIRI_GAMECONTROLLER_H


class GameController {
	public:
		static GameController* getInstance();
		virtual void init() = 0;
		virtual int leftRightMovement() = 0;
		virtual void connect() = 0;
	protected:
	private:
};


#endif //MENGHINDAR_DIRI_GAMECONTROLLER_H
