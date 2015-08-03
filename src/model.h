#ifndef MODEL_H
#define MODEL_H

#include "ofMain.h"

// This class stores the model data to be displayed

class model : public ofMesh
{
public:
	model();
	virtual ~model();
	bool load(string filename); // Loads the point data from that file
	void draw(); // Draw the model

private:
};


#endif // MODEL_H
