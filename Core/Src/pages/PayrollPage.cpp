/*
 * PayrollPage.cpp
 *
 *  Created on: Mar 3, 2021
 *      Author: Tyler
 */

#include <pages/PayrollPage.hpp>
#include "lcd.hpp"


PayrollPage::PayrollPage(char* page_name) : Page() {
	strcpy(name, page_name);
	selection_num = 0;
}

void PayrollPage::make_active(Employee* e) {
	active_page = this;
	render();
}

void PayrollPage::render() {
	// INITIALIZATION
	lcd->background(BG);  		// Set background to BG color
	lcd->foreground(White);    	// Set text color to white
	lcd->cls();                	// Clear screen
	lcd->set_orientation(0);

	// PAGE TITLE
	lcd->fillrect(0, 0, W, 40, ACCENT);
	lcd->background(ACCENT);
	lcd->print_text((char*) "<", 5, 10, ARIAL24);
	lcd->print_text((char*) "Payroll", 25, 10, ARIAL24);

	// TABLE HEADERS
	lcd->fillrect(0, 40, W, 80, BG);
	lcd->background(BG);
	lcd->print_text((char*) "[name]", 10, 50, ARIAL12);
	lcd->print_text((char*) "[hours]", 100, 50, ARIAL12);
	lcd->print_text((char*) "[pay]", 180, 50, ARIAL12);
	lcd->line(0, 70, W, 70, White);

	// TABLE ROWS
	Employee* e;
	char hours[6], pay[8];
	double pay_val = 0.0, sum = 0.0;

	for (int i = 0; i < num_employees; i++) {
		e = employees[i];

		lcd->fillrect(0, 80 + 30 * i, W, 80 + 30 * (i + 1), BG);
		lcd->foreground(LightGrey);

		pay_val = calculate_pay(e);
		sum += pay_val;
		sprintf(hours, "%.2f", calculate_hours(e));
		sprintf(pay, "$%.2f", pay_val);
		lcd->print_text(e->name, 10, 80 + 30 * i, ARIAL12);
		lcd->print_text(hours, 100, 80 + 30 * i, ARIAL12);
		lcd->print_text(pay, 180, 80 + 30 * i, ARIAL12);
		lcd->line(0, 70 + 30 * (i + 1), W, 70 + 30 * (i + 1), Black);
	}

	// RESULTS
	lcd->line(0, H - 40, W, H - 40, White);
	lcd->foreground(White);
	sprintf(pay, "$%.2f", sum);
	lcd->print_text((char*) "GRAND TOTAL:", 10, H - 25, ARIAL12);
	lcd->print_text(pay, 180, H - 25, ARIAL12);
}

void PayrollPage::up_button_handler() { get_page((char*) "main")->make_active(); }

void PayrollPage::down_button_handler() { get_page((char*) "main")->make_active(); }

void PayrollPage::left_button_handler() { get_page((char*) "main")->make_active(); }

void PayrollPage::right_button_handler() { get_page((char*) "main")->make_active(); }

void PayrollPage::center_button_handler() { get_page((char*) "main")->make_active(); }


// Not used on this page
void PayrollPage::increment_selection() { return; }
void PayrollPage::decrement_selection() { return; }
void PayrollPage::make_selection() { return; }
void PayrollPage::clear_highlighted_selection() { return; }
void PayrollPage::render_highlighted_selection() { return; }


