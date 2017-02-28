# cordic
Simple CORDIC in c

## Usage:

    gentable <n> > cordic-<n>.h
    
* `n` should be number of bits in a *signed* word to use for computations.

Example:

    gentable 24 > cordic-24-bit.h

This will output a header file that will perform the CORDIC sin/cos operation in 24 bit signed fixed point. See `cordic-test.c` for an example of using the generated headerfile.

Note that the generator is hardcoded to use a 2.[n-2] fixed point format, so `n=16` will create code for 2.14 fixed point precision. 

## Precreated
See `generated/` for a set of CORDIC headers for given a few word widths. 
