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
 * @file  next_graphics.c
 * @brief ZX Spectrum Next graphics functions.
 */

#include "graphics.h"
#include "system_constants.h"
#include <arch/zxn.h>


// This function:
// Fills the layer 2 screen with the given colour.
// Uses Bank 3 to access the layer 2 memory.
// Uses DMA for speed.
void ClearTextScreen(uint8_t backgroundColor) {
    uint8_t bank;
    uint8_t *bank3StartAddress = (uint8_t *) BANK_3_START_ADDRESS; 
    uint8_t currentBank1 = ZXN_READ_MMU6();
    uint8_t currentBank2 = ZXN_READ_MMU7();
    
    for (bank = 9; bank < 14; ++bank) {
        uint8_t page = bank << 1;
        
        ZXN_WRITE_MMU6(page);
        ZXN_WRITE_MMU7(page + 1);
        
// Set the first byte in the bank to the color.
        *bank3StartAddress = backgroundColor;

// Use DMA to copy the first byte to the rest of the bank.
		IO_DMA = D_DISABLE_DMA;

// Set WR0 to specify transfer from A to B with A having a 16 bit start address 
// and a 16 bit length. 
		IO_DMA = D_WR0 | D_WR0_TRANSFER_A_TO_B | D_WR0_X34_A_START | D_WR0_X56_LEN;
		IO_DMA = BANK_3_START_ADDRESS & 0xFF;
		IO_DMA = BANK_3_START_ADDRESS >> 8;
		IO_DMA = BANK_LENGTH - 1 & 0xFF;
		IO_DMA = BANK_LENGTH - 1 >> 8;

// Set WR1 to specify A is a fixed memory location.
		IO_DMA = D_WR1 | D_WR1_A_IS_MEM | D_WR1_A_FIX; 
		IO_DMA = D_WR1X6_A_CLEN_4;

// Set WR2 to specify B is a memory location that increments.
		IO_DMA = D_WR2 | D_WR2_B_IS_MEM | D_WR2_B_INC;
// Set WR4 to specify that B has a 16 bit start address.
// Continuious mode
		IO_DMA = D_WR4 | D_WR4_CONT | D_WR4_X23_B_START;
		IO_DMA = BANK_3_START_ADDRESS + 1 & 0xFF;
		IO_DMA = BANK_3_START_ADDRESS + 1 >> 8;
		
// Set WR5 to specify that DMA will stop when the end of the block is reached.
		IO_DMA = D_WR5 | D_WR5_STOP;

// Set WR6 to load the adresses of A and B.
		IO_DMA = D_LOAD;

// Set WR6 to enable the DMA and execute the transfer.
		IO_DMA = D_ENABLE_DMA;
    } 

    ZXN_WRITE_MMU6(currentBank1);
    ZXN_WRITE_MMU7(currentBank2);
}

