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

;  * @file  next_frame_sync.asm
;  * @brief ZX Spectrum Next wait for the next vertical sync.

SECTION code_user
PUBLIC _FrameSync

_FrameSync:
    ld      bc, 0x243B
    ld      a, 0x1F
    out     (bc), a
    
DelayLoop:
    ld      bc, 0x253B
    in      a, (bc)
    cmp     255
   ; ret     z
    jp     z, Delay2
    jp      DelayLoop
Delay2:
    in      a, (bc)
    cmp     0
    ret     z
    jp      Delay2
