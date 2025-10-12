#ifndef FRAME_CONTROL_H_
#define FRAME_CONTROL_H_

#include <stdint.h>

void WaitForFrames(uint8_t count);
void FrameSync(void);

#endif // FRAME_CONTROL_H_