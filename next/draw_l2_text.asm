;  * Copyright 2025 Peter Brown
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License");
;  * you may not use this file except in compliance with the License.
;  * You may obtain a copy of the License at
;  *
;  *  	http://www.apache.org/licenses/LICENSE-2.0
;  *
;  * Unless required by applicable law or agreed to in writing, software
;  * distributed under the License is distributed on an "AS IS" BASIS,
;  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
;  * See the License for the specific language governing permissions and
;  * limitations under the License.

;  * @file  draw_l2_text.asm
;  * @brief ZX Spectrum Next draw characters to the layer 2 screen.
 
SECTION code_user
PUBLIC _DisplayChar

_udg        = 0x3c00

ARG_Y       =   8
ARG_X       =   9
ARG_CHAR    =   10
ARG_COLOR   =   11


fgColor:    defb    0
bgColor:    defb    0
pattern:    defw    0
xOffset:    defb    0
yOffset:    defb    0

_DisplayChar:
    push	bc
	push	de
	push 	hl

; Store colors
    ld      hl, ARG_COLOR
    add     hl, sp
    ld      a, (hl)
    ld      b, a
    and     a, 0x0F
    ld      d, a
    ld      a, b
    srl     a
    srl     a
    srl     a
    srl     a
    ld      e, a

; Store pattern pointer
    ld      hl, ARG_CHAR
    add     hl, sp
    ld      a, (hl)
    ld      c, a
    ld      b, 0
    sla     c
    rl      b
    sla     c
    rl      b
    sla     c
    rl      b

    ld      hl, _udg
    ld      a, l
    add     a, c
    ld      l, a
    ld      a, h
    adc     b
    ld      h, a

    ld      (pattern), hl
; Calculate x offset
    ld      hl, ARG_X
    add     hl, sp
    ld      b, 0
    ld      a, (hl)
    sla     a ; x8
    rl      b
    sla     a 
    rl      b
    sla     a 
    rl      b
; Calculate page
    sla     a 
    rl      b
    sla     a 
    rl      b
    sla     a 
    rl      b
; calculate final x offset
    srl     a
    srl     a
    srl     a
    ld      (xOffset), a
; add y
    ld      hl, ARG_Y
    add     hl, sp
    ld      a, (hl)
    sla     a
    sla     a
    sla     a
    ld      (yOffset), a
; Set page
    ld      a, b
    add     a, 18
    NEXTREG 0x56, a

    ld      a, 8
    ld      b, a


draw_char_loop:

; Load pattern
    ld      hl, (pattern)
    ld      a, (hl)
    inc     hl
    ld      (pattern), hl
    ld      c, a
    ld      a, (yOffset)
    ld      l, a
    ld      a, (xOffset)
    add     a, 0xC0
    ld      h, a

; bit 1
    sla     c
    jr      c, bit_1_foreground
    ld      (hl), e
    jr      bit_1_set
bit_1_foreground:
    ld      (hl), d
bit_1_set:
    inc     h

; bit 2
    sla     c
    jr      c, bit_2_foreground
    ld      (hl), e
    jr      bit_2_set
bit_2_foreground:
    ld      (hl), d
bit_2_set:
    inc     h

; bit 3
    sla     c
    jr      c, bit_3_foreground
    ld      (hl), e
    jr      bit_3_set
bit_3_foreground:
    ld      (hl), d
bit_3_set:
    inc     h

    sla     c
    jr      c, bit_4_foreground
    ld      (hl), e
    jr      bit_4_set
bit_4_foreground:
    ld      (hl), d
bit_4_set:

    inc     h

    sla     c
    jr      c, bit_5_foreground
    ld      (hl), e
    jr      bit_5_set
bit_5_foreground:
    ld      (hl), d
bit_5_set:

    inc     h

    sla     c
    jr      c, bit_6_foreground
    ld      (hl), e
    jr      bit_6_set
bit_6_foreground:
    ld      (hl), d
bit_6_set:
 
    inc     h

    sla     c
    jr      c, bit_7_foreground
    ld      (hl), e
    jr      bit_7_set
bit_7_foreground:
    ld      (hl), d
bit_7_set:

    inc     h

    sla     c
    jr      c, bit_8_foreground
    ld      (hl), e
    jr      bit_8_set
bit_8_foreground:
    ld      (hl), d
bit_8_set:



    ld      a, (yOffset)
    inc     a
    ld      (yOffset), a
    djnz    draw_char_loop
DisplayColorChar_end:
    ld      a, 0
    NEXTREG 0x56, a
    pop		hl
	pop		de
	pop		bc
    ret