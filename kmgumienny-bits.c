/* 
 * CS:APP Data Lab 
 * 
 * Kamil Gumienny kmgumienny
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */

	 
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
    	 //gets bits that are 1s in both numbers to get rid of later 
  int combo = x&y;
  // 0100 & 0101 == 0100
  	  
  	  //flips bits to get rid of ands computed above
  int oppCombo = ~combo;
  // 0100 == 1011
  
  	  //computes the compliments of the ints;
  int compCombo = (~x & ~y);
  //1011 & 1010 == 1010
  
  	  //gets the compliments of bits and then gets compliment of that
  int oppCompCombo = ~compCombo;
  //1010 == 0101
  
  	  //the result is the compliment of combination anded with compliment of
  	  //combination of compliments which gets rid of all the shared 1 bits
  int result = oppCombo & oppCompCombo;
  // 0101 & 1011 == 0001
  return result;
}
     
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
		//define integer as 1;
	int one = 1;
	int result;
	// 00000001
	
		//shift the 1 as far left as possible to get tmin
	one = one << 31;
	// 00000001 << 7 == 10000000
	
		// return compliment of tmin
	result = ~one;
	//10000000 == 01111111
  return result;
}
/* 
 * isNotEqual - return 0 if x == y, and 1 otherwise 
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y) {
		//first xor. If x and y equal you get 0
	int xorXAndY = x ^ y;
	// 01011010 ^ 01011010 == 0
	
		// not twice to turn any non-0 number to a 1 or a 0 back to 0
	int result = !(!xorXAndY);
	//!!0== 0
	//!!31 == 1
	
	return result;
}

/* 
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) {
		//create some variables, you know how this goes
	int result, nByteGone;
		//because we can't use mutiplication, the amount shifted is n*8 or n<<3
	int shift = n << 3;
	//3 << 3 = 24, 2 << 3 = 16...
	
		//the replacement mask is the c byte shifted into it's rightful place
	int replaceMask = c << shift;
	//0100 << 8 = 010000000000
	
		//mask will be used to cover all the values in x except byte being replaced
	int mask = 0xff << shift;
	mask = ~mask;
	// n=2, 000000001111 << shift = ~111100000000 = 000011111111
	
		//gets rid of the byte we don't want in x
	nByteGone = x&mask;
	// 010111000101 & 000011111111 == 000011000101
	
		//ORs x without the byte we are replacing with the byte we want 
	result = nByteGone | replaceMask;
	//010000000000 | 000011000101 = 010011000101
	
	return result;
	
	
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
	int nMinusOne, result, largest;
	
	//first find out if x is negative or positive
	int xSign = x >> 31;
	// 1011 >> 3 == 1111
	// 0111 >> 3 == 0000
	
		//gets the largest value bit
		// if x is negative results in complement - 1, but the position
		//of highest bit is preserved
	largest = (~x & xSign);
	largest += (x & ~xSign);
	// 1011 & 0000 == 0000 // -5
	// 0 + (0100 & 1111) == 0100 // this gives 4, but leftmost bit is in correct place
	
	
		//Cannot supract so have to ~0 to get n-1 to test largest bit
	nMinusOne = n + ~0;
	//4 - 1 == 3
	
		//shifts to see if there are any bits left after shifting size of n
		//only way to do it without overflowing
	result = !(largest >> nMinusOne);
	//!(0100 >> 3) == !0000 == 1
	
	return result;
}
/* 
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateLeft(int x, int n) {
	
  int leftShift, rightBits, mask, leftBits, result;
	  	  
  	  //Gets the bits dropped off when shifting to the left by shifting 
  	  //x 32 - n to the right. Bits are rightmost where they should be
  	  //but this could be negative
  leftBits = (x >> (33 + ~n)); 
  //11001101 >> (9 - 5) = 11111100
  	  	 
  	  //creates an int with a "1" for every bit dropped off shifting left
  mask = ~(~0 << n); 	
  //11111111 << 4 == 11110000
  	  	  
	  //use and to generate positive int of right bits if negative
  rightBits = leftBits & mask;
  //11110000 ^ 11111100 == 00001100
  
  	  //moves the bits over and drops the first n bits
  leftShift = (x << n); 		
  // 11001101 << 4 = 11010000
  	  	  
  	  //result adds left-shifted off bits back, on the right of the int
  result = leftShift | rightBits;
  //11010000 ^ 00001100 = 11011100
  return result;
  
}
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x) {
	
	int isZero, mask, trail, isPower, result;
	
	//check to see if x is 0
	isZero = !x;
	// !0000 == 1
	
		//check if x is negative of positive. Will be 0 if positive
	mask = x >> 31; 
	// 1111 or 0000
		
		//if X is power of 0, it has only one "1" in binary. subracting 1 
		//creates trail of 1s
	trail = x + ~0; 
	// 01000000 - 1 == 00111111;
		
		//get 0 if comparing x to its trail 
	isPower = x & trail; 
	//0100 & 0011 = 0
	
	//ispower, sign, and isZero should all be 0 if x is power2
	result = !(isPower | mask | isZero);
	
  return result;
}
/* 
 * rempwr2 - Compute x%(2^n), for 0 <= n <= 30
 *   Negative arguments should yield negative remainders
 *   Examples: rempwr2(15,2) = 3, rempwr2(-35,3) = -3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int rempwr2(int x, int n) {
	
	int modulo, mask, isModulo, negativeCase;
	
		//modulus using & looks to the right of "n"th bit. Subtract 1 from
		//nth bit and use & to get remainder of x. This will always 
		//produce a positive number 
    modulo = x & ((1 << n) + ~0);
    
    	//generate a mask for x value
    mask = x >> 31;
    
    	//create makeshift boolean for whether there is a remainder
    isModulo = !!modulo;
    
    	//get a mask for negative x value  
    	//generating a 1 if there is a remainder and 0 otherwise
    	//if 1, shift it in n position and negate the number +1
    negativeCase = (~((isModulo) << n)) + 1;
    
    	//this is only necessary in negative case when you have a remainder
    	//ands negative mask against mask to make sure negative x
    negativeCase = negativeCase & mask;
    
    	//returns the remainder or adds the remainder to negative mask
    return modulo + negativeCase;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
	int mask, result;
	
		//first get x as either a 1 or a 0
	x = !!x;
	// -12 = 1, 0 = 1
	 	 
		//create a mask using x;
	mask = (x<<31)>>31;
	// x=1 - 11...111 or x=0 - 00...000
	
		//if x is 1; mask&y will return y. if x is 0, ~mask is all 1s and mask&z
		//returns z
	result = (mask & y) + (~mask & z);
	//1111 & 1010 + 0000 & 1101 == 1010
	
  return result;
}

/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {
	int result, xShift;
	
		//int for storing x after shifting
	xShift = x;
	
		//shifting by half and XORing as a way of adding every bit together 
		//and leaving the sum as the rightmost bit. This is the same way 
		//networks check for corruption
	xShift = (x>>16);
	x = x ^ xShift;
	//0101 ^ 0001 = 0100
	
	xShift = (x>>8);	
	x = x ^ xShift;
	//0100 ^ 0010 = 1010
	
	xShift = (x>>4);	
	x = x ^ xShift;
	
	
	xShift = (x>>2);	
	x = x ^ xShift;

	xShift = (x>>1);	
	x = x ^ xShift;
	
	result = x & 1;
	//1010 & 0001 = 0
	
  return result;
}
/* 
 * greatestBitPos - return a mask that marks the position of the
 *               most significant 1 bit. If x == 0, return 0
 *   Example: greatestBitPos(96) = 0x40
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Rating: 4 
 */
int greatestBitPos(int x) {
	int rightMask;
	int result;
	//shifts everything to the right and generates a mask of 0s trailed by 1s
	int y = x;
			
	y = y | y >> 1;
	y = y | y >> 1;
	y = y | y >> 1;
	y = y | y >> 1;
	y = y | y >> 1;
	y = y | y >> 1;
	y = y | y >> 1;
	y = y | y >> 1;
	y = y | y >> 1;
	y = y | y >> 1;
	y = y | y >> 1;
	y = y | y >> 1;
	y = y | y >> 1;
	y = y | y >> 1;
	y = y | y >> 1;
	y = y | y >> 1;
	y = y | y >> 1;
	y = y | y >> 1;
	y = y | y >> 1;
	y = y | y >> 1;
	y = y | y >> 1;
	y = y | y >> 1;
	y = y | y >> 1;
	y = y | y >> 1;
	y = y | y >> 1;
	y = y | y >> 1;
	y = y | y >> 1;
	y = y | y >> 1;
	y = y | y >> 1;
	y = y | y >> 1;
	y = y | y >> 1;
	//00111111
	
		//generates a right mask by flipping left mask and 
	rightMask = ((~y >> 1) ^ (1 << 31));
	//00111111 -> 11100000 -> 01100000
	//11111111 -> 00000000 -> 00000000
	
		//by anding the right and left masks get the right most bit
	result = y & rightMask;
	//  01100000
	// &00111111
	//  00100000 <- result
			
			
	return result;
}
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
	
		//check x against its negation. If not zero, will get 1 as leftmost bit
	int mask = (~x + 1) | x;
	// 0010 -> 1101 | 0010 = 1111
	// 0000 -> 0000 | 0000 = 0000
	
		//create a mask of 1s if non-zero, mask of 0s if x = 0
		//and create negation of either 1 or 0
	mask = ~(mask >> 31);
	//11..111 or 00..000
	
	
		// and with 1. If mask is -1, get 1 and if mask is 0, get 0
	return mask &1 ;
	//11..111 & 00..001 = 1 
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
		//creates a float with 1 as leftmost bit
	unsigned lmb = 1<<31;
	
		//gets rid of leftmost bit in uf and checks to see if the float 
		//uf is greater than 0
	if ((uf & 0x7FFFFFFF) > 0x7f800000)
		return uf;
	
		//if float isn't greater than 0, returns uf with flipped leftmost bit.
	return uf ^ lmb;
}


/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
	int value;
	//23 mantissa bits
	//8 exponential bits
	//sign * 2^exponent * 1.mantissa
	//sxxxxxxxxmmmmmmmmmmmmmmmmmmmmmmm
	
		//gets the sign of the operator by making a mask and then checking rmb
	int sign = (uf >> 31) & 1;
		//gets the exponent of float by shifting 23 and looking at 8 rightmost bits
	int exponent = (uf >> 23) & 0xff;
		//gets mantissa from uf and normalizes by adding 1 to the front
		//because the equation for floating point #s is 1.mmm...
	int mantissa = (uf & 0x7fffff) | 0x800000;
		// the value of the exponent is on a bias of 127. Normalized by subtracting
	int trueExp = exponent + 1 + ~127;
	
	
		//exponent of 0 is reserved for float 0
	if(!exponent)
		return 0;
	
		//if float is less than one, can not be represented as int
	if(trueExp < 0)
		return 0;
	
		//if exponent is greater than 0, float can not be represented as int 
	if(trueExp > 30)
		return 0x80000000u;
	
		//if exponent is all 1s, value is +/- infinity or Not a Number
	if(exponent == 0xff)
		return 0x80000000u;
	
		//int to hold answer
	value = 0;
	
		//shifting the mantissa is equivalent of multiplying/dividing
		//by 2^n mantissa. if the exponent is smaller than size of mantissa
		//(which is no longer a small decimal #), drop off bits right and vice versa.
	if(trueExp < 23)
		value = mantissa >> (23 - trueExp);
	if(trueExp > 23)
		value = mantissa << (trueExp - 23);
	
		//checks against mask to see if boolean had negative representation.
	if(sign)
		return 1 + ~value;
	return value;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
	unsigned result;
		//gets the sign of the float
	int sign = (uf >> 31);
		//gets the exponent of float by shifting 23 and looking at 8 rightmost bits
	int exponent = (uf >> 23) & 0xff;
		//gets mantissa from uf by looking at 23 rightmost
	int mantissa = uf & 0x7fffff;

		//checks cases for exponent. if it's all 1s, the float is NaN, +/- infinity
		//if adding 1 to exponent turns float to NaN/inf clear the mantissa
		//base case exponent is incremented by 1
	if(exponent == 0xff)
		return uf;
	else if(exponent == 0xfe){
		mantissa = 0;
		exponent++;
	}else if(exponent > 0)
		exponent++;
	
	
		//if uf is 0, return 0
	if(uf == 0)
		return 0;
	
		//if there is no exponent, multiply the number manually 
	if(!exponent)
		 mantissa = mantissa << 1;
	
		//the result is simply the reverse operation from the beginning 
	result = (sign <<31 ) | (exponent << 23) | mantissa;
	
	return result;
}
