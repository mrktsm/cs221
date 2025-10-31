// Test file for single-bit Mux4Way

load Mux4Way.hdl,
output-file Mux4Way.out,
compare-to Mux4Way.cmp,
output-list a%B3.1.3 b%B3.1.3 c%B3.1.3 d%B3.1.3 sel%B3.2.3 out%B3.1.3;

set a 0,
set b 0,
set c 0,
set d 0,
set sel %B00,
eval,
output;

set sel %B01,
eval,
output;

set sel %B10,
eval,
output;

set sel %B11,
eval,
output;

set a 1,
set sel %B00,
eval,
output;

set b 1,
set sel %B01,
eval,
output;

set c 1,
set sel %B10,
eval,
output;

set d 1,
set sel %B11,
eval,
output;

set a 0,
set b 0,
set c 0,
set d 0,
set sel %B00,
eval,
output;

set a 1,
set b 1,
set c 1,
set d 1,
set sel %B00,
eval,
output;

set sel %B01,
eval,
output;

set sel %B10,
eval,
output;

set sel %B11,
eval,
output;
