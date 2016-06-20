//
// Created by Gilian Joosen on 17/05/16.
//

#ifndef MENGHINDAR_DIRI_WIIMOTECONTROLLER_H
#define MENGHINDAR_DIRI_WIIMOTECONTROLLER_H

#include "../GameController.h"
#include "wiimote.h"
#include <iostream>
using namespace std;
class WiiMoteController: public GameController {
	public:


		void init(){
			w.CalibrateAtRest();
		}

		void connect(){
			cout << w.Connect() << endl;
		}

		int leftRightMovement(){
			double offset = 0;
			w.RefreshState();
			double weightL = w.BalanceBoard.Kg.BottomL + w.BalanceBoard.Kg.TopL;
			double weightR = w.BalanceBoard.Kg.BottomR + w.BalanceBoard.Kg.TopR;
			printf("%d", weightR);
			if (weightR + 10 < weightL) {
				printf("Going left");
				offset++;
			}
			if (weightL + 10 < weightR) {
				printf("going right");
				offset--;
			}
			return offset;
		}

	protected:
	private:
		wiimote w;
};


#endif //MENGHINDAR_DIRI_WIIMOTECONTROLLER_H
