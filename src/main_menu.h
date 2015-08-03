#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "ofMain.h"
#include "menu_button.h"


enum e_button_id
{
	NEW_SCAN,
	UPDATE_SCAN,
	REVIEW_SCAN,
	EXIT,

	NONE
};



class main_menu
{
public:
	main_menu();
	~main_menu();

	void set_font(ofTrueTypeFont* font);

	void draw();
	void mouse_move(ofPoint mouse);
	e_button_id mouse_click(ofPoint mouse); // Returns the e_button_id of the pressed button or NONE

private:
	void update(); // Updates the buttons (redraws them)
	vector <menu_button> m_buttons;
	ofTrueTypeFont* m_font;
};


#endif // MAIN_MENU_H
