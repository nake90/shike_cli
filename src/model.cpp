#include "model.h"

#include <cstdio>

model::model()
{

}

model::~model()
{

}

bool model::load(string filename)
{
	ofVec3f point;
	string path = "data/" + filename;

	FILE *f = fopen(path.c_str(), "r");
	if(!f)return false;
	
	while(!feof(f))
	{
		if(fscanf(f, "%f %f %f\n", &point.x, &point.z, &point.y) == 3)
		{
			point = point * 50.0f;
			addVertex(point);
		}
	}
	
	setMode(OF_PRIMITIVE_POINTS);
	enableColors();

	fclose(f);

	return true;
}

void model::draw()
{
	ofPushStyle();

	ofSetColor(0x00, 0x00, 0x80);

	glPointSize(4);
	ofMesh::draw();

	ofPopStyle();
}

