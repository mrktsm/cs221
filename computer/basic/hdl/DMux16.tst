load DMux16.hdl,
output-file DMux16.out,
compare-to DMux16.cmp,
output-list in%B1.16.1 sel%B2.1.2 a%B1.16.1 b%B1.16.1;

set in %B0000000000000000,
set sel 0,
eval,
output;

set in %B0000000000000000,
set sel 1,
eval,
output;

set in %B1001100001110110,
set sel 0,
eval,
output;

set in %B1001100001110110,
set sel 1,
eval,
output;

set in %B1111111111111111,
set sel 0,
eval,
output;

set in %B1111111111111111,
set sel 1,
eval,
output;
