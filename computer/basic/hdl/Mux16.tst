load Mux16.hdl,
output-file Mux16.out,
compare-to Mux16.cmp,
output-list a%B1.16.1 b%B1.16.1 sel%B2.1.2 out%B1.16.1;

set a %B0000000000000000,
set b %B0000000000000000,
set sel 0,
eval,
output;

set a %B0000000000000000,
set b %B0000000000000000,
set sel 1,
eval,
output;

set a %B0000000000000000,
set b %B0001001000110100,
set sel 0,
eval,
output;

set a %B0000000000000000,
set b %B0001001000110100,
set sel 1,
eval,
output;

set a %B1001100001110110,
set b %B0000000000000000,
set sel 0,
eval,
output;

set a %B1001100001110110,
set b %B0000000000000000,
set sel 1,
eval,
output;
