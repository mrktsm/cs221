// Test file for Jumper chip

load Jumper.hdl,
output-file Jumper.out,
compare-to Jumper.cmp,
output-list zr%B3.1.3 ng%B3.1.3 opcode%B3.3.3 jump%B3.1.3;

// Test 000 - no jump (should always be 0)
set zr 0,
set ng 0,
set opcode %B000,
eval,
output;

set zr 1,
set ng 0,
set opcode %B000,
eval,
output;

set zr 0,
set ng 1,
set opcode %B000,
eval,
output;

// Test 001 - BGT (jump if positive: zr=0, ng=0)
set zr 0,
set ng 0,
set opcode %B001,
eval,
output;

set zr 1,
set ng 0,
set opcode %B001,
eval,
output;

set zr 0,
set ng 1,
set opcode %B001,
eval,
output;

// Test 010 - BEQ (jump if zero: zr=1)
set zr 1,
set ng 0,
set opcode %B010,
eval,
output;

set zr 0,
set ng 0,
set opcode %B010,
eval,
output;

set zr 0,
set ng 1,
set opcode %B010,
eval,
output;

// Test 011 - BGE (jump if not negative: ng=0)
set zr 0,
set ng 0,
set opcode %B011,
eval,
output;

set zr 1,
set ng 0,
set opcode %B011,
eval,
output;

set zr 0,
set ng 1,
set opcode %B011,
eval,
output;

// Test 100 - BLT (jump if negative: ng=1)
set zr 0,
set ng 1,
set opcode %B100,
eval,
output;

set zr 0,
set ng 0,
set opcode %B100,
eval,
output;

set zr 1,
set ng 0,
set opcode %B100,
eval,
output;

// Test 101 - BNE (jump if not zero: zr=0)
set zr 0,
set ng 0,
set opcode %B101,
eval,
output;

set zr 0,
set ng 1,
set opcode %B101,
eval,
output;

set zr 1,
set ng 0,
set opcode %B101,
eval,
output;

// Test 110 - BLE (jump if negative or zero: ng=1 OR zr=1)
set zr 0,
set ng 1,
set opcode %B110,
eval,
output;

set zr 1,
set ng 0,
set opcode %B110,
eval,
output;

set zr 0,
set ng 0,
set opcode %B110,
eval,
output;

// Test 111 - BAL (always jump)
set zr 0,
set ng 0,
set opcode %B111,
eval,
output;

set zr 1,
set ng 0,
set opcode %B111,
eval,
output;

set zr 0,
set ng 1,
set opcode %B111,
eval,
output;

