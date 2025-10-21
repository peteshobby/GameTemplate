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
 * @file  sprites.h
 * @brief Sprite API.
 */

#ifndef SPRITES_H_
#define SPRITES_H_

#include <stdbool.h>
#include <stdint.h>

void Show1616Sprite(uint8_t spriteIndex, uint8_t imageIndex, uint8_t palette, bool flipX, bool flipY, int16_t x, int16_t y);
void Move1616Sprite(uint8_t spriteIndex, int16_t x, int16_t y);
void Hide1616Sprite(uint8_t spriteIndex);
void Show88Sprite(uint8_t spriteIndex, uint8_t imageIndex, uint8_t palette, bool flipX, bool flipY, int16_t x, int16_t y);
void Hide88Sprite(uint8_t spriteIndex);

#endif // SPRITES_H_