/*
 * MainPage.hpp
 *
 *  Created on: Mar 3, 2021
 *      Author: Tyler
 */

#ifndef INC_PAGES_MAINPAGE_HPP_
#define INC_PAGES_MAINPAGE_HPP_


#include <pages/Page.hpp>

class MainPage : public Page {
public:
	MainPage(char* name);

	virtual void make_active(Employee* e = nullptr);

	virtual void render();

	virtual void up_button_handler();

	virtual void down_button_handler();

	virtual void left_button_handler();

	virtual void right_button_handler();

	virtual void center_button_handler();

	virtual void increment_selection();

	virtual void decrement_selection();

	virtual void make_selection();

private:

	void render_highlighted_selection();

	void clear_highlighted_selection();
};


#endif /* INC_PAGES_MAINPAGE_HPP_ */
