# cordic
Simple CORDIC in c

## Usage:

    cordic <n>
    
* `n` should be number of bits in a *signed* word to use for computations.

This will output a header file that will perform the CORDIC sin/cos operation. See `cordic-test.c` for an example of using the generated headerfile.

## Precreated
See `generated/` for a set of CORDIC headers for given a few word widths. Note that these are for *signed* word lengths.
