load Loader.hdl,
output-file Loader.out,
compare-to Loader.cmp,
output-list ctype%B3.1.3 d1%B1.1.1 d2%B1.1.1 d3%B1.1.1 loadA%B3.1.3 loadD%B3.1.3 loadM%B3.1.3;

set ctype 0, set d1 0, set d2 0, set d3 0, eval, output;
set ctype 0, set d1 0, set d2 0, set d3 1, eval, output;
set ctype 0, set d1 0, set d2 1, set d3 0, eval, output;
set ctype 0, set d1 0, set d2 1, set d3 1, eval, output;
set ctype 0, set d1 1, set d2 0, set d3 0, eval, output;
set ctype 0, set d1 1, set d2 0, set d3 1, eval, output;
set ctype 0, set d1 1, set d2 1, set d3 0, eval, output;
set ctype 0, set d1 1, set d2 1, set d3 1, eval, output;
set ctype 1, set d1 0, set d2 0, set d3 0, eval, output;
set ctype 1, set d1 0, set d2 0, set d3 1, eval, output;
set ctype 1, set d1 0, set d2 1, set d3 0, eval, output;
set ctype 1, set d1 0, set d2 1, set d3 1, eval, output;
set ctype 1, set d1 1, set d2 0, set d3 0, eval, output;
set ctype 1, set d1 1, set d2 0, set d3 1, eval, output;
set ctype 1, set d1 1, set d2 1, set d3 0, eval, output;
set ctype 1, set d1 1, set d2 1, set d3 1, eval, output;
