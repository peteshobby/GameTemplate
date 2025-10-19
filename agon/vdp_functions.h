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
 * @file  vdp_functions.h
 * @brief Agon Light VDP wrapper functions.
 */

#ifndef VDP_FUNCTIONS_H_
#define VDP_FUNCTIONS_H_

#include <stdint.h>

// Scroll protection
void EnableScrollProtection(void);

// Buffer
void ClearBuffer(uint16_t bufferId);
void WriteBuffer(uint16_t bufferId, uint16_t width, uint16_t height, const uint8_t *source);
void WriteMultipleBuffer(uint16_t bufferId, uint16_t width, uint16_t height, uint8_t rows, uint8_t columns, const uint8_t *source);

void ConsolidateBuffer(uint16_t bufferId);

// Bitmaps
void CreateBitmap(uint16_t width, uint16_t height, uint8_t format);
void CreateSolidBitmap(uint16_t width, uint16_t height, uint16_t col1, uint16_t col2);
void DrawBitmap(uint16_t x, uint16_t y);
void SelectBitmap(uint16_t bitmapId);

// Sprites
void SelectSprite( uint8_t spriteId);
void ClearSprite(void);
void AddSpriteFrame(uint16_t bitmapId);
void SelectNthFrame(uint8_t frame);
void ShowSprite(void);
void MoveSprite(int16_t x, int16_t y);
void SetHardwareSprite(void);
void SetSoftwareSprite(void);
void UpdateSprites(void);
void ActivateSprites(uint8_t count);
void EnableHardwareSprites(void);

void EnableTilemap(void);
void SwapScreen(void);

#endif // VDP_FUNCTIONS_H_
