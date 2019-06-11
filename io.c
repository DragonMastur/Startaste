// io.c
// by Preston Hager
// for Startaste OS

/* in
 - using the IO ports, we can get a value. */
char in(unsigned short port) {
  unsigned char value;
  __asm__ __volatile__ ("inb %1, %0" // base assembly
          : "=a" (value) // output the value in value.
          : "dN" (port) // inputs
  );
  return value;
}

/* out
 - using the IO ports, we can set a value. */
void out(unsigned short port, unsigned char value) {
  __asm__ __volatile__ ("outb %0, %1" // base assembly
          : // no output.
          : "a" (value), "dN" (port) // inputs
  );
}
