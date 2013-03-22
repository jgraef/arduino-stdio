/*
 * Stdio.cpp - c-lib's stdio with Arduino's streams
 * Easiest way to use: just call stdioInit(9600) to redirect stdin, stdout and stderr to the Serial stream.
 * Created by Janosch Gräf, March 22, 2012.
 * Released into public domain.
 */

#include <stdio.h>

#include "Arduino.h"
#include "Stdio.h"

#include <stdio.h>


extern struct __file *__iob[];


static int stdioPutChar(char c, FILE *s) {
  Stream *stream = (Stream*)s->udata;
  return stream->write(c) == 1 ? 0 : -1;
}

static int stdioGetChar(FILE *s) {
  Stream *stream = (Stream*)s->udata;
  return stream->read();
}
  
FILE *stdioOpenStream(Stream *stream, boolean r, boolean w) {
  FILE *f;
  
  f = fdevopen(w ? stdioPutChar : NULL, r ? stdioGetChar : NULL);
  f->udata = stream;
  return f;
}

void stdioInitExt(Stream *stdinStream, Stream *stdoutStream, Stream *stderrStream) {
  FILE *_stdin, *_stdout, *_stderr;
  
  _stdin = stdioOpenStream(stdinStream, true, false);
  _stdout = stdioOpenStream(stdoutStream, false, true);
  _stderr = stdioOpenStream(stderrStream, false, true);
  __iob[2] = _stderr;
}

void stdioInit(unsigned long baud) {
  Serial.begin(baud);
  stdioInitExt(&Serial, &Serial, &Serial);
}
