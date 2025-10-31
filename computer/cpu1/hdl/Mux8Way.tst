// Test file for single-bit Mux8Way

load Mux8Way.hdl,
output-file Mux8Way.out,
compare-to Mux8Way.cmp,
output-list a%B3.1.3 b%B3.1.3 c%B3.1.3 d%B3.1.3 e%B3.1.3 f%B3.1.3 g%B3.1.3 h%B3.1.3 sel%B3.3.3 out%B3.1.3;

set a 0,
set b 0,
set c 0,
set d 0,
set e 0,
set f 0,
set g 0,
set h 0,
set sel %B000,
eval,
output;

set sel %B001,
eval,
output;

set sel %B010,
eval,
output;

set sel %B011,
eval,
output;

set sel %B100,
eval,
output;

set sel %B101,
eval,
output;

set sel %B110,
eval,
output;

set sel %B111,
eval,
output;

set a 1,
set sel %B000,
eval,
output;

set b 1,
set sel %B001,
eval,
output;

set c 1,
set sel %B010,
eval,
output;

set d 1,
set sel %B011,
eval,
output;

set e 1,
set sel %B100,
eval,
output;

set f 1,
set sel %B101,
eval,
output;

set g 1,
set sel %B110,
eval,
output;

set h 1,
set sel %B111,
eval,
output;

set a 0,
set b 0,
set c 0,
set d 0,
set e 0,
set f 0,
set g 0,
set h 0,
set sel %B000,
eval,
output;

set a 1,
set b 1,
set c 1,
set d 1,
set e 1,
set f 1,
set g 1,
set h 1,
set sel %B000,
eval,
output;

set sel %B001,
eval,
output;

set sel %B010,
eval,
output;

set sel %B011,
eval,
output;

set sel %B100,
eval,
output;

set sel %B101,
eval,
output;

set sel %B110,
eval,
output;

set sel %B111,
eval,
output;

