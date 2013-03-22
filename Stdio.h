/*
 * Stdio.h - c-lib's stdio with Arduino's streams
 * Easiest way to use: just call stdioInit(9600) to redirect stdin, stdout and stderr to the Serial stream.
 * Created by Janosch Gräf, March 22, 2012.
 * Released into public domain.
 */

#ifndef _ARDUINO_STDIO_H_
#define _ARDUINO_STDIO_H_

#include <stdio.h>

#include "Arduino.h"

FILE *stdioOpenStream(Stream *stream, boolean r, boolean w);
void stdioInitExt(Stream *stdinStream, Stream *stdoutStream, Stream *stderrStream);
void stdioInit(unsigned long baud);

#endif /* _ARDUINO_STDIO_H_ */
