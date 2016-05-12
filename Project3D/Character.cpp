#include "Character.h"

Character::Character(ModelObject model, std::string naam): Model(model) {
	Name = naam;
}

ModelObject Character::getModel() {
	return Model;
}

