#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxNetwork.h"
#include "ofxXmlSettings.h"
#include "main_menu.h"
#include "menu_button.h"
#include "model.h"

enum e_prog_mode
{
	MAIN_MENU,
	VIEW_MODEL
};

class ofApp : public ofBaseApp
{

public:
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
private:
	ofTrueTypeFont font;
	ofTrueTypeFont titleFont;
	
	main_menu m_main_menu;
	menu_button m_button_back;

	model m_model;
	ofEasyCam m_cam;


	e_prog_mode m_current_mode = MAIN_MENU;
};
