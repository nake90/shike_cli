#include "menu_button.h"

menu_button::menu_button(string text, ofPoint pos, ofTrueTypeFont* font)
{
	m_text = text;
	m_anchor = pos;
	m_font = font;
	
	// Defaults
	m_color_on = ofColor(0, 0xFF, 0);
	m_color_off = ofColor(0, 0x80, 0);
}

menu_button::~menu_button()
{
	//dtor
}

void menu_button::update_rect()
{
	m_pos = m_anchor;
	switch(m_anchor_mode)
	{
	case LEFT: break;
	case CENTER:
		if(m_font)
			m_pos.x -= m_font->getStringBoundingBox(m_text, 0, 0).width / 2.0;
		else
			m_pos.x -= ofBitmapStringGetBoundingBox(m_text, 0, 0).width / 2.0;
		break;
	case RIGHT:
		if(m_font)
			m_pos.x -= m_font->getStringBoundingBox(m_text, 0, 0).width;
		else
			m_pos.x -= ofBitmapStringGetBoundingBox(m_text, 0, 0).width;
		break;
	}
	
	if(m_font)
		m_rect = m_font->getStringBoundingBox(m_text, m_pos.x, m_pos.y);
	else
		m_rect = ofBitmapStringGetBoundingBox(m_text, m_pos.x, m_pos.y);
	
	// Padding
	m_rect.x -= 12;
	m_rect.y -= 12;
	m_rect.width += 24;
	m_rect.height += 24;
}

void menu_button::draw()
{
	ofPushStyle();
	
	/*! DEBUG !*/
	//ofNoFill();
	//ofSetColor(0,0,255);
	//ofRect(m_rect);
	/*! DEBUG !*/
	
	if(m_MouseOver)
		ofSetColor(m_color_on);
	else
		ofSetColor(m_color_off);
	
	if(m_font)
		m_font->drawString(m_text, m_pos.x, m_pos.y);
	else
		ofDrawBitmapString(m_text, m_pos.x, m_pos.y);
	
	ofPopStyle();
}
