load DMux.hdl,
output-file DMux.out,
compare-to DMux.cmp,
output-list in%B2.1.2 sel%B2.1.2 a%B2.1.2 b%B2.1.2;

set in 0,
set sel 0,
eval,
output;

set in 0,
set sel 1,
eval,
output;

set in 1,
set sel 0,
eval,
output;

set in 1,
set sel 1,
eval,
output;
