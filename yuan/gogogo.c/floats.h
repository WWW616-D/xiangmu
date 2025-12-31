/* ----------------------------------------------------------------------- *
 *
 *   Copyright 1996-2020 The NASM Authors - All Rights Reserved
 *   See the file AUTHORS included with the NASM distribution for
 *   the specific copyright holders.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following
 *   conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *
 *     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 *     CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *     INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *     MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 *     CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *     SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 *     NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 *     HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *     CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 *     OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 *     EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ----------------------------------------------------------------------- */

 /*
  * floats.h   header file for the floating-point constant module of
  *	      the Netwide Assembler
  */

#ifndef NASM_FLOATS_H
#define NASM_FLOATS_H


  /* Must match the fp_formats[] array in asm/floats.c */
enum floatize {
    FLOAT_8,  //0
    FLOAT_16,  //1
    FLOAT_B16,  //2 
    FLOAT_32,   //3
    FLOAT_64,   //4
    FLOAT_80M,  //5
    FLOAT_80E,  //6 
    FLOAT_128L, //7
    FLOAT_128H, //8
    FLOAT_ERR   //9                /* Invalid format, MUST BE LAST */
};
enum float_round {
    FLOAT_RC_NEAR,
    FLOAT_RC_ZERO,
    FLOAT_RC_DOWN,
    FLOAT_RC_UP
};
/* Note: enum floatize and FLOAT_ERR are defined in nasm.h */
/* Floating-point format description */
struct ieee_format {
    int bytes;                  /* Total bytes */  //总字节数
    int mantissa;               /* Fractional bits in the mantissa */   //尾数位数   
    int explicit;               /* Explicit integer */  // 显式整数位
    int exponent;               /* Bits in the exponent */   //指数位数
    int offset;                 /* Offset into byte array for floatize op */  //偏移
};
extern const struct ieee_format fp_formats[FLOAT_ERR];  //何意味

int float_const(const char* str, int s, uint8_t* result, enum floatize ffmt);
enum floatize float_deffmt(int bytes);
int float_option(const char* option);

#endif /* NASM_FLOATS_H */
#pragma once
