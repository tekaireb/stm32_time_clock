/*
 * EmployeeProfilePage.hpp
 *
 *  Created on: Mar 3, 2021
 *      Author: Tyler
 */

#ifndef INC_PAGES_EMPLOYEEPROFILEPAGE_HPP_
#define INC_PAGES_EMPLOYEEPROFILEPAGE_HPP_


#include <pages/Page.hpp>

class EmployeeProfilePage : public Page {
public:
	EmployeeProfilePage(char* name);

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

	Employee* employee;
};


#endif /* INC_PAGES_EMPLOYEEPROFILEPAGE_HPP_ */
