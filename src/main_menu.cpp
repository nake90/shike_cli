#include "main_menu.h"

main_menu::main_menu()
{
	ofPoint pos;
	menu_button button;
	
	pos.x = ofGetWidth()/2;
	pos.y = 140;
	button.set_text("New scan");
	button.set_id(NEW_SCAN);
	button.set_pos(pos);
	button.set_font(m_font);
	button.set_anchor_mode(CENTER);
	button.update();
	m_buttons.push_back(button);
	
	pos.y += 40;
	button.set_text("Update scan");
	button.set_id(UPDATE_SCAN);
	button.set_pos(pos);
	button.set_font(m_font);
	button.set_anchor_mode(CENTER);
	button.update();
	m_buttons.push_back(button);
	
	pos.y += 40;
	button.set_text("Review scan");
	button.set_id(REVIEW_SCAN);
	button.set_pos(pos);
	button.set_font(m_font);
	button.set_anchor_mode(CENTER);
	button.update();
	m_buttons.push_back(button);
	
	pos.y += 60;
	button.set_text("Exit");
	button.set_id(EXIT);
	button.set_pos(pos);
	button.set_font(m_font);
	button.set_anchor_mode(CENTER);
	button.update();
	m_buttons.push_back(button);

}

main_menu::~main_menu()
{

}

void main_menu::set_font(ofTrueTypeFont* font)
{
	m_font = font;
	
	for(unsigned int i = 0; i < m_buttons.size(); i++)
		m_buttons[i].set_font(m_font);

	update();
}

void main_menu::draw()
{
	for(unsigned int i = 0; i < m_buttons.size(); i++)
		m_buttons[i].draw();
}

void main_menu::update()
{
	for(unsigned int i = 0; i < m_buttons.size(); i++)
		m_buttons[i].update();
}

void main_menu::mouse_move(ofPoint mouse)
{
	for(unsigned int i = 0; i < m_buttons.size(); i++)
		m_buttons[i].update_mouse(mouse);
}

e_button_id main_menu::mouse_click(ofPoint mouse)
{
	for(unsigned int i = 0; i < m_buttons.size(); i++)
	{
		if(m_buttons[i].check_mouse(mouse) == true)
		{
			return (e_button_id)m_buttons[i].get_id();
		}
	}
	return NONE;
}



