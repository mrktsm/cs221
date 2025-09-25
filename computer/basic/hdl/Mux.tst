load Mux.hdl,
output-file Mux.out,
compare-to Mux.cmp,
output-list a%B2.1.2 b%B2.1.2 sel%B2.1.2 out%B2.1.2;

set a 0,
set b 0,
set sel 0,
eval,
output;

set a 0,
set b 0,
set sel 1,
eval,
output;

set a 0,
set b 1,
set sel 0,
eval,
output;

set a 0,
set b 1,
set sel 1,
eval,
output;

set a 1,
set b 0,
set sel 0,
eval,
output;

set a 1,
set b 0,
set sel 1,
eval,
output;

set a 1,
set b 1,
set sel 0,
eval,
output;

set a 1,
set b 1,
set sel 1,
eval,
output;
