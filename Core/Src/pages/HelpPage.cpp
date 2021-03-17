/*
 * HelpPage.cpp
 *
 *  Created on: Mar 3, 2021
 *      Author: Tyler
 */

#include <pages/HelpPage.hpp>
#include "lcd.hpp"


HelpPage::HelpPage(char* page_name) : Page() {
	strcpy(name, page_name);
	selection_num = 0;
}

void HelpPage::make_active(Employee* e) {
	active_page = this;
	render();
}

void HelpPage::render() {
	// INITIALIZATION
	lcd->background(BG);  		// Set background to BG color
	lcd->foreground(White);    	// Set text color to white
	lcd->cls();                	// Clear screen
	lcd->set_orientation(0);

	// PAGE TITLE
	lcd->fillrect(0, 0, W, 40, ACCENT);
	lcd->background(ACCENT);
	lcd->print_text((char*) "Time Clock", 40, 10, ARIAL24);

	// HELP CONTENT
	lcd->background(BG);
	lcd->print_text((char*) "This system allows users to:", 10, 50, ARIAL12);
	lcd->print_text((char*) "- Clock in/out via Bluetooth", 10, 80, ARIAL12);
	lcd->print_text((char*) "- Track employee work hours", 10, 100, ARIAL12);
	lcd->print_text((char*) "- Calculate payroll", 10, 120, ARIAL12);
	lcd->print_text((char*) "Use the joystick to navigate.", 10, 150, ARIAL12);
	lcd->print_text((char*) "Press any button to return.", 10, 170, ARIAL12);
	lcd->print_text((char*) "Have fun!", 80, 230, ARIAL12);

	// CREDITS
	lcd->fillrect(0, H - 20, W, H, ACCENT);
	lcd->background(ACCENT);
	lcd->foreground(White);
	lcd->print_text((char*) "Created by Tyler Ekaireb", 25, H - 15, ARIAL12);


	render_highlighted_selection();
}

void HelpPage::up_button_handler() { get_page((char*) "main")->make_active(); }

void HelpPage::down_button_handler() { get_page((char*) "main")->make_active(); }

void HelpPage::left_button_handler() { get_page((char*) "main")->make_active(); }

void HelpPage::right_button_handler() { get_page((char*) "main")->make_active(); }

void HelpPage::center_button_handler() { get_page((char*) "main")->make_active(); }


// Not used on this page
void HelpPage::increment_selection() { return; }
void HelpPage::decrement_selection() { return; }
void HelpPage::make_selection() { return; }
void HelpPage::clear_highlighted_selection() { return; }
void HelpPage::render_highlighted_selection() { return; }

