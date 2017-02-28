# cordic
Simple fixed-point CORDIC function generator for C. Generates a single header file implementing the CORDIC sin/cos operation.

## Usage:

    gentable <n> > cordic-<n>.h
    
* `n` should be number of bits in a *signed* word to use for computations.

Example:

    gentable 24 > cordic-24-bit.h

This will output a header file that will perform the CORDIC sin/cos operation in 24 bit signed fixed point. See `cordic-test.c` for an example of using the generated headerfile.


### Fixed point format
Note that the generator is hardcoded to use a 2.[n-2] fixed point format, so `n=16` will create code for 2.14 fixed point precision, to accept angle inputs in range [-2.0,2.0]. Angle inputs must be in the range (-pi/2, pi/2). For angle values outside of this range, wrap to [-pi, pi] then:

* `a` in `[pi/2,pi]`: `a_corrected = half_pi-(theta-half_pi)`
* and similarly for values -pi---pi/2

## Precreated
See `generated/` for a set of CORDIC headers for given a few word widths. 
