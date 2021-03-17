/*
 * EmployeeProfilePage.cpp
 *
 *  Created on: Mar 3, 2021
 *      Author: Tyler
 */

#include <pages/EmployeeProfilePage.hpp>
#include "lcd.hpp"


EmployeeProfilePage::EmployeeProfilePage(char* page_name) : Page() {
	strcpy(name, page_name);
	employee = nullptr;
}

void EmployeeProfilePage::make_active(Employee* e) {
	active_page = this;
	employee = e;
	render();
}

void EmployeeProfilePage::render() {
	// INITIALIZATION
	lcd->background(BG);  	   // set background to BG color
	lcd->foreground(White);    // set chars to white
	lcd->cls();                // clear the screen
	lcd->set_orientation(0);

	// PAGE TITLE (profile name + status)
	lcd->fillrect(0, 0, W, 40, ACCENT);
	lcd->background(ACCENT);
	lcd->print_text((char*) "<", 5, 10, ARIAL24);
	lcd->print_text(employee->name, 25, 10, ARIAL24);
	if (employee->events[employee->num_events - 1].clock_in) {
		lcd->background(Green);
		lcd->fillrect(W - 40, 10, W - 10, 30, Green);
		lcd->print_text((char*) "IN", W - 35, 15, ARIAL12);
	} else {
		lcd->background(Red);
		lcd->fillrect(W - 60, 10, W - 10, 30, Red);
		lcd->print_text((char*) "OUT", W - 45, 15, ARIAL12);
	}

	// PERSONAL INFORMATION
	lcd->background(BG);
	char id[10], wage[10];

	lcd->rect(0, 41, 70, 90, White);
	lcd->print_text((char*) "Basic", 15, 50, ARIAL12);
	lcd->print_text((char*) "Info:", 20, 70, ARIAL12);

	sprintf(id, "#%d", employee->id);
	lcd->rect(0, 90, 70, 140, White);
	lcd->print_text((char*) "[id]", 25, 100, ARIAL12);
	lcd->print_text(id, 20, 120, ARIAL12);

	sprintf(wage, "%.2f/hr", employee->wage);
	lcd->rect(0, 140, 70, 190, White);
	lcd->print_text((char*) "[wage]", 12, 150, ARIAL12);
	lcd->print_text(wage, 5, 170, ARIAL12);

	lcd->rect(0, 190, 70, 240, White);
	lcd->print_text((char*) "[admin]", 10, 200, ARIAL12);
	lcd->print_text((char*) (employee->admin ? "yes" : " no"), 20, 220, ARIAL12);

	// CLOCK IN/OUT EVENTS
	lcd->print_text((char*) "[events]", 100, 50, ARIAL24);
	for (int i = 0; i < employee->num_events; i++) {
		char t[20], stamp[23];
		strftime(t, sizeof(t), "%H:%M (%m/%d)", &employee->events[i].timestamp);
		sprintf(stamp, "%s @  %s\n", employee->events[i].clock_in ? "IN " : "OUT", t);
		lcd->print_text(stamp, 80, 90 + 30 * i, ARIAL12);
	}


}

void EmployeeProfilePage::up_button_handler() { decrement_selection(); }

void EmployeeProfilePage::down_button_handler() { increment_selection(); }

void EmployeeProfilePage::left_button_handler() { get_page((char*) "employees")->make_active(); }

void EmployeeProfilePage::right_button_handler() { return; }

void EmployeeProfilePage::center_button_handler() { return; }

void EmployeeProfilePage::increment_selection() {
	if (selection_num < num_employees) selection_num++;
}

void EmployeeProfilePage::decrement_selection() {
	if (selection_num > 0) selection_num--;
}

void EmployeeProfilePage::make_selection() {

}




// OLD:

//	// CALENDAR
//	int hour_space = (lcd->height() - 60) / 10;
//	int day_space = (lcd->width() - 20) / 5;
//
//	// Draw hour numbers
//	for (int i = 0; i < 9; i++)
//		lcd->print_text((char*) ((i + 8) % 12), 5, 60 + hour_space * i, (unsigned char*) Arial12x12);
//
//	// Draw day columns
//	char days[] = "MTWTF";
//	for (int i = 0; i < 5; i++)
//		lcd->print_text((char*) days[i], 20 + day_space * i, 60, (unsigned char*) Arial12x12);
