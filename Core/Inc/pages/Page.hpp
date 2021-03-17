/*
 * Page.hpp
 *
 *  Created on: Mar 3, 2021
 *      Author: Tyler
 */

#ifndef INC_PAGES_PAGE_HPP_
#define INC_PAGES_PAGE_HPP_

extern "C" {
	#include "employee.h"
}

class Page {
public:
	Page() {}
	virtual ~Page() {}

	virtual void make_active(Employee* e = nullptr) = 0;

	virtual void render() = 0;

	virtual void up_button_handler() = 0;

	virtual void down_button_handler() = 0;

	virtual void left_button_handler() = 0;

	virtual void right_button_handler() = 0;

	virtual void center_button_handler() = 0;

	virtual void increment_selection() = 0;

	virtual void decrement_selection() = 0;

	virtual void make_selection() = 0;

	int selection_num;
	char name[50];
};




#endif /* INC_PAGES_PAGE_HPP_ */
