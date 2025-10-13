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
