#ifndef MENU_BUTTON_H
#define MENU_BUTTON_H

#include "ofMain.h"
#include "ofBitmapFont.h"

enum e_anchor_mode
{
	LEFT,
	CENTER,
	RIGHT
};

class menu_button
{
public:
	menu_button(string text = "", ofPoint pos = ofPoint(0,0), ofTrueTypeFont* font = NULL);
	virtual ~menu_button();
	
	void set_pos(ofPoint pos){m_anchor = pos;} // Sets the position (upper left corner of the text)
	void set_font(ofTrueTypeFont *font){m_font = font;} // Sets the font to use or NULL for bitmap font
	void set_text(string text){m_text = text;} // Label of the button
	void set_colors(ofColor on, ofColor off) // Changes the colors of the text (on == selected, off == normal)
	{
		m_color_on = on;
		m_color_off = off;
	}
	void set_anchor_mode(e_anchor_mode mode){m_anchor_mode = mode;}
	
	
	void update_mouse(ofPoint mouse) // Checks and updates colors accordingly
	{
		if(m_rect.inside(mouse))m_MouseOver = true;
		else m_MouseOver = false;
	}
	
	bool check_mouse(ofPoint mouse) // True if the mouse is over the button
	{
		update_mouse(mouse);
		return m_MouseOver;
	}
	
	
	void update(){update_rect();} // Update the button
	void draw(); // Draw the button
	
	void set_id(unsigned int id){m_id = id;}
	unsigned int get_id(){return m_id;}
	
protected:
private:
	void update_rect(void); // Updates the selection rectangle
	
	ofPoint m_anchor; // Anchor position (defined by the user)
	ofPoint m_pos; // Upper left corner (depends of m_anchor and m_anchor_mode)
	e_anchor_mode m_anchor_mode;
	
	string m_text; // Label
	ofTrueTypeFont *m_font = NULL; // Font
	ofRectangle m_rect; // Used for mouse checks
    
	bool m_MouseOver = false; // True if the mouse is inside the button
	ofColor m_color_on; // Color of the text if the mouse is over the button
	ofColor m_color_off; // Default color of the text
	
	unsigned int m_id; // For identification uses
};

#endif // MENU_BUTTON_H
