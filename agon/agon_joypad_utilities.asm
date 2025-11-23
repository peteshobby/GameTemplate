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
 

;  * @file  agon_joypad_utilities.asm
;  * @brief Agon Light joypad utilitiy functions.

	assume adl=1

	section .text

	public _SetJoyPorts, _ReadDirection, _ReadFire

PC_DR		equ		0x9E ; 158
PC_DDR		equ		0x9F ; 159
PD_DR		equ		0xA2 ; 162
PD_DDR		equ		0xA3 ; 163

_SetJoyPorts:
    ld a, 0xFF
    out0 (PC_DDR), a
    in0 a, (PD_DDR)
    or a, 0xF0
    out0 (PD_DDR), a
	ret

_ReadDirection:
	in0 a, (PC_DR)
	ret

_ReadFire:
	in0 a, (PD_DR)
	ret