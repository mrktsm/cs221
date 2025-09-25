load And.hdl,
output-file And.out,
compare-to And.cmp,
output-list a%B2.1.2 b%B2.1.2 out%B2.1.2;

set a 0,
set b 0,
eval,
output;

set a 0,
set b 1,
eval,
output;

set a 1,
set b 0,
eval,
output;

set a 1,
set b 1,
eval,
output;
