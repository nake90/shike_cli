#include "ofApp.h"

enum e_button_id
{
	NEW_SCAN,
	UPDATE_SCAN,
	REVIEW_SCAN,
	EXIT
};

//--------------------------------------------------------------
void ofApp::setup()
{
	menu_button button;
	ofPoint pos;
	
	ofEnableAlphaBlending();
	ofSetLogLevel(OF_LOG_VERBOSE);
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	font.loadFont("fonts/Inconsolata.otf", 14, true,false,false,0.3,90);
	titleFont.loadFont("fonts/Inconsolata.otf", 28, true,false,false,0.3,90);
	
	
	
	pos.x = ofGetWidth()/2;
	pos.y = 80;
	button.set_text("New scan");
	button.set_id(NEW_SCAN);
	button.set_pos(pos);
	button.set_font(&font);
	button.set_anchor_mode(CENTER);
	button.update();
	main_menu.push_back(button);
	
	pos.y += 40;
	button.set_text("Update scan");
	button.set_id(UPDATE_SCAN);
	button.set_pos(pos);
	button.set_font(&font);
	button.set_anchor_mode(CENTER);
	button.update();
	main_menu.push_back(button);
	
	pos.y += 40;
	button.set_text("Review scan");
	button.set_id(REVIEW_SCAN);
	button.set_pos(pos);
	button.set_font(&font);
	button.set_anchor_mode(CENTER);
	button.update();
	main_menu.push_back(button);
	
	pos.y += 60;
	button.set_text("Exit");
	button.set_id(EXIT);
	button.set_pos(pos);
	button.set_font(&font);
	button.set_anchor_mode(CENTER);
	button.update();
	main_menu.push_back(button);
}

//--------------------------------------------------------------
void ofApp::update()
{
	
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofSetColor(0x20, 0x20, 0x20);
	titleFont.drawString("shike client", 20, 60);
	
	for(unsigned int i = 0; i < main_menu.size(); i++)
		main_menu[i].draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
	
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{
	for(unsigned int i = 0; i < main_menu.size(); i++)
		main_menu[i].update_mouse(ofPoint(x,y));
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
	
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
	if(button == 0)
	{
		for(unsigned int i = 0; i < main_menu.size(); i++)
		{
			if(main_menu[i].check_mouse(ofPoint(x,y)) == true)
			{
				printf("Click %d!\n", main_menu[i].get_id());
				
				if(main_menu[i].get_id() == EXIT)
					ofExit(0);
				
				break; // Only one button can be clicked at once!
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
	
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
	
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
	
}
