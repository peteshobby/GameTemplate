/*
 * Copyright 2025 Peter Brown
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  	http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @file  frame_sync.h
 * @brief Frame sync API.
 */

#ifndef FRAME_SYNC_H_
#define FRAME_SYNC_H_

#include <stdint.h>

void WaitForFrames(uint8_t count);
void FrameSync(void);

#endif // FRAME_SYNC_H_