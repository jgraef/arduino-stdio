arduino-stdio
=============

Wrapping clib's stdio onto Arduino streams.

Example:

	#include <Stdio.h>

	void setup() {
	  stdioInit(9600);
	  printf("Hello World: %d 0x%08x %s\n", 42, 0xDEADBEEF, "foobar");

	  // Do something here
	}

	void loop() {
	  // Do something here
	}
