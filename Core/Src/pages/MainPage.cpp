/*
 * MainPage.cpp
 *
 *  Created on: Mar 3, 2021
 *      Author: Tyler
 */

#include <pages/MainPage.hpp>
#include "lcd.hpp"

int num_options = 3;
char* menu_options[] = {(char*) "View Employees", (char*) "Calculate Payroll", (char*) "Help"};
char* menu_links[] = {(char*) "employees", (char*) "payroll", (char*) "help"};

MainPage::MainPage(char* page_name) : Page() {
	strcpy(name, page_name);
	selection_num = 0;
}

void MainPage::make_active(Employee* e) {
	active_page = this;
	render();
}

void MainPage::render() {
	// INITIALIZATION
	lcd->background(BG);  		// Set background to BG color
	lcd->foreground(White);    	// Set text color to white
	lcd->cls();                	// Clear screen
	lcd->set_orientation(0);

	// PAGE TITLE
	lcd->fillrect(0, 0, W, 40, ACCENT);
	lcd->background(ACCENT);
	lcd->print_text((char*) "Time Clock", 40, 10, ARIAL24);

	// TABLE HEADERS
	lcd->fillrect(0, 40, W, 80, BG);
	lcd->background(BG);
	lcd->print_text((char*) "Select a function:", 10, 50, ARIAL12);
	lcd->line(0, 70, W, 70, White);

	// TABLE ROWS
	for (int i = 0; i < num_options; i++) {
		lcd->fillrect(0, 80 + 30 * i, W, 80 + 30 * (i + 1), BG);
		lcd->foreground(LightGrey);

		lcd->print_text(menu_options[i], 10, 80 + 30 * i, ARIAL12);
		lcd->line(0, 70 + 30 * (i + 1), W, 70 + 30 * (i + 1), Black);
	}

	// CREDITS
	lcd->fillrect(0, H - 20, W, H, ACCENT);
	lcd->background(ACCENT);
	lcd->foreground(White);
	lcd->print_text((char*) "Created by Tyler Ekaireb", 25, H - 15, ARIAL12);


	render_highlighted_selection();
}

void MainPage::clear_highlighted_selection() {
	// Replace black lines above and below entry and remove highlight on sides
	lcd->line(0, 70 + 30 * selection_num, W, 70 + 30 * selection_num, Black);
	lcd->line(0, 70 + 30 * (selection_num + 1), W, 70 + 30 * (selection_num + 1), Black);

	lcd->line(0, 70 + 30 * selection_num, 0, 70 + 30 * (selection_num + 1), BG);
	lcd->line(W, 70 + 30 * selection_num, W, 70 + 30 * (selection_num + 1), BG);

	// First entry is preceded by white bar
	if (selection_num == 0)
		lcd->line(0, 70, W, 70, White);
}


void MainPage::render_highlighted_selection() {
	// Draw rectangle around selection
	lcd->rect(0, 70 + 30 * selection_num, W, 70 + 30 * (selection_num + 1), Cyan);
}

void MainPage::up_button_handler() { decrement_selection(); }

void MainPage::down_button_handler() { increment_selection(); }

void MainPage::left_button_handler() { return; }

void MainPage::right_button_handler() { return; }

void MainPage::center_button_handler() { make_selection(); }

void MainPage::increment_selection() {
	if (selection_num < num_employees - 1) {
		clear_highlighted_selection();
		selection_num++;
		render_highlighted_selection();
	}
}

void MainPage::decrement_selection() {
	if (selection_num > 0) {
		clear_highlighted_selection();
		selection_num--;
		render_highlighted_selection();
	}
}

void MainPage::make_selection() {
	get_page(menu_links[selection_num])->make_active();
}


