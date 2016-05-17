//
// Created by Gilian Joosen on 17/05/16.
//

#include "KeyboardController.h"

GameController* GameController::getInstance() {
	return new KeyboardController();
}