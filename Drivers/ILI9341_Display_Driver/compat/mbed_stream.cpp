#include <../../../Drivers/ILI9341_Display_Driver/compat/mbed.hpp>

#include "../../../Drivers/ILI9341_Display_Driver/compat/platform.h"

namespace mbed {

void mbed_set_unbuffered_stream(FILE *_file)
{
}

int mbed_getc(FILE *_file)
{
	return 0;
}

char* mbed_gets(char *s, int size, FILE *_file)
{
	return 0;
}

};

