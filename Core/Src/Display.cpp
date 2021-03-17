/*
 * Display.cpp
 *
 *  Created on: Mar 2, 2021
 *      Author: Tyler
 */

#include <Display.hpp>
#include <lcd.hpp>

Display::Display(PinName mosi, PinName miso, PinName sclk, PinName cs, PinName reset, PinName dc, const char *name)
	: SPI_TFT_ILI9341(mosi, miso, sclk, cs, reset, dc, name) {
}

void Display::print_text(char* text, int x, int y, unsigned char* font) {
	int i = 0;
	char * less_space = (char*) "fijlrtI1.[/";
	char * more_space = (char*) "mwMWP";

	int less = font[1] * 0.5;
	int norm = font[1] * 0.7;
	int more = font[1];

	set_font(font);

	do {
		locate(x, y);
		character(0, 0, text[i]);

		if (strchr(less_space, text[i])) x += less;
		else if (strchr(more_space, text[i])) x += more;
		else x += norm;

	} while (text[i++]);
}
