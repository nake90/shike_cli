#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup()
{
	ofEnableAlphaBlending();
	ofSetLogLevel(OF_LOG_VERBOSE);
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	font.loadFont("fonts/Inconsolata.otf", 18, true,false,false,0.3,90);
	titleFont.loadFont("fonts/Inconsolata.otf", 28, true,false,false,0.3,90);
	
	m_main_menu.set_font(&font);
	
	m_model.load("cache/large.dat");

	m_button_back.set_pos(ofPoint(20, 90));
	m_button_back.set_font(&font);
	m_button_back.set_text("Back");
	m_button_back.set_colors(ofColor(0xFF, 0xFF, 0xFF), ofColor(0x40, 0x40, 0x40));
	m_button_back.update();
	
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

	if(m_current_mode == MAIN_MENU)
		m_main_menu.draw();
	else
		m_button_back.draw();

	if(m_current_mode == VIEW_MODEL)
	{
		m_cam.begin();
		ofDrawAxis(100.0f);
		m_model.draw();
		m_cam.end();
	}
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
	if(m_current_mode == MAIN_MENU)
		m_main_menu.mouse_move(ofPoint(x,y));
	else
		m_button_back.update_mouse(ofPoint(x,y));
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
		if(m_current_mode == MAIN_MENU)
		{
			// Check if a main menu button was hit
			switch(m_main_menu.mouse_click(ofPoint(x,y)))
			{
				case NONE:
					break;
				case NEW_SCAN:
					break;
				case UPDATE_SCAN:
					break;
				case REVIEW_SCAN:
					m_current_mode = VIEW_MODEL;
					m_cam.enableMouseInput();
					m_cam.reset();
					break;
				case EXIT:
					ofExit(0);
					break;
				default:
					ofLogWarning("Unhandled button");
			}
		}
		else // We are not in the main menu
		{
			if(m_button_back.check_mouse(ofPoint(x,y)) == true)
			{
				// Get back to the main menu
				m_current_mode = MAIN_MENU;
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
