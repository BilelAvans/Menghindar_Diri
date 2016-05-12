#pragma once

#include <iostream>
#include "ModelObject.h"

class Character {
	// Our model
	ModelObject Model;
	std::string Name;

	public:
		Character(ModelObject model, std::string naam);
		ModelObject getModel();

};