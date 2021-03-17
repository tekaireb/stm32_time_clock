/*
 * EmployeeListPage.cpp
 *
 *  Created on: Mar 3, 2021
 *      Author: Tyler
 */

#include <pages/EmployeeListPage.hpp>
#include "lcd.hpp"


EmployeeListPage::EmployeeListPage(char* page_name) : Page() {
	strcpy(name, page_name);
	selection_num = 0;
}

void EmployeeListPage::make_active(Employee* e) {
	active_page = this;
	render();
}

void EmployeeListPage::render() {
	// INITIALIZATION
	lcd->background(BG);  		// Set background to BG color
	lcd->foreground(White);    	// Set text color to white
	lcd->cls();                	// Clear screen
	lcd->set_orientation(0);

	// PAGE TITLE
	lcd->fillrect(0, 0, W, 40, ACCENT);
	lcd->background(ACCENT);
	lcd->print_text((char*) "<", 5, 10, ARIAL24);
	lcd->print_text((char*) "Employees", 25, 10, ARIAL24);

	// TABLE HEADERS
	lcd->fillrect(0, 40, W, 80, BG);
	lcd->background(BG);
	lcd->print_text((char*) "[name]", 10, 50, ARIAL12);
	lcd->print_text((char*) "[id]", 100, 50, ARIAL12);
	lcd->print_text((char*) "[wage]", 170, 50, ARIAL12);
	lcd->line(0, 70, W, 70, White);

	// TABLE ROWS
	Employee* e;
	char id[10], wage[10];

	for (int i = 0; i < num_employees; i++) {
		e = employees[i];

		lcd->fillrect(0, 80 + 30 * i, W, 80 + 30 * (i + 1), BG);
		lcd->foreground(LightGrey);

		sprintf(id, "#%d", e->id);
		sprintf(wage, "%.2f/hr", e->wage);
		lcd->print_text(e->name, 10, 80 + 30 * i, ARIAL12);
		lcd->print_text(id, 100, 80 + 30 * i, ARIAL12);
		lcd->print_text(wage, 170, 80 + 30 * i, ARIAL12);
		lcd->line(0, 70 + 30 * (i + 1), W, 70 + 30 * (i + 1), Black);
	}

	render_highlighted_selection();
}

void EmployeeListPage::clear_highlighted_selection() {
	// Replace black lines above and below entry and remove highlight on sides
	lcd->line(0, 70 + 30 * selection_num, W, 70 + 30 * selection_num, Black);
	lcd->line(0, 70 + 30 * (selection_num + 1), W, 70 + 30 * (selection_num + 1), Black);

	lcd->line(0, 70 + 30 * selection_num, 0, 70 + 30 * (selection_num + 1), BG);
	lcd->line(W, 70 + 30 * selection_num, W, 70 + 30 * (selection_num + 1), BG);

	// First entry is preceded by white bar
	if (selection_num == 0)
		lcd->line(0, 70, W, 70, White);
}


void EmployeeListPage::render_highlighted_selection() {
	// Draw rectangle around selection
	lcd->rect(0, 70 + 30 * selection_num, W, 70 + 30 * (selection_num + 1), Cyan);
}

void EmployeeListPage::up_button_handler() { decrement_selection(); }

void EmployeeListPage::down_button_handler() { increment_selection(); }

void EmployeeListPage::left_button_handler() { get_page((char*) "main")->make_active(); }

void EmployeeListPage::right_button_handler() { return; }

void EmployeeListPage::center_button_handler() { make_selection(); }

void EmployeeListPage::increment_selection() {
	if (selection_num < num_employees - 1) {
		clear_highlighted_selection();
		selection_num++;
		render_highlighted_selection();
	}
}

void EmployeeListPage::decrement_selection() {
	if (selection_num > 0) {
		clear_highlighted_selection();
		selection_num--;
		render_highlighted_selection();
	}
}

void EmployeeListPage::make_selection() {
	get_page((char*) "profile")->make_active(employees[selection_num]);
}


