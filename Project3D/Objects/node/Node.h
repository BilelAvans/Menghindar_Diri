//
// Created by Gilian Joosen on 13/05/16.
//

#ifndef MOBIELSIMULATIE_NODE_H
#define MOBIELSIMULATIE_NODE_H


#include "../ObjModel.h"

class Node {
	public:
		Node(ObjModel *model);
		Node(ObjModel *model, vector<Node*> subnodes);
		void draw();
		void setRotate(float rotateX, float rotateY, float rotateZ){
			rotate[0] = rotateX;
			rotate[1] = rotateY;
			rotate[2] = rotateZ;
		}
		void setTranslate(float x, float y, float z){
			translate[0] = x;
			translate[1] = y;
			translate[2] = z;
		}
		void addRotation(float rotateX, float rotateY, float rotateZ){
			rotate[0] += rotateX;
			rotate[1] += rotateY;
			rotate[2] += rotateZ;
		}
		void addTranslation(float x, float y, float z){
			translate[0] += x;
			translate[1] += y;
			translate[2] += z;
		}
		vector<Node*> getSubNodes(){
			return this->subnodes;
		}
	protected:

	private:
		float rotate[3] = {0,0,0};
		float translate[3] = {0,0,0};
		ObjModel *model = nullptr;
		vector<Node*> subnodes;
};


#endif //MOBIELSIMULATIE_NODE_H
