//
// Created by Gilian Joosen on 17/05/16.
//

#include "WiiMoteController.h"

GameController* GameController::getInstance() {
	return new WiiMoteController();
}