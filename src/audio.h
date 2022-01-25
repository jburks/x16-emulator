// Commander X16 Emulator
// Copyright (c) 2020 Frank van den Hoef
// All rights reserved. License: 2-clause BSD

#pragma once

#include <SDL.h>

void audio_init(const char *dev_name, int num_audio_buffers);
void audio_close(void);
void audio_render(int cpu_clocks);

void audio_usage(void);

#define YM_CLOCK_HZ 3579545
#define YM_WRITE_BUSY_CYCLES 68
#define YM_WRITE_BUSY_TICKS ((YM_WRITE_BUSY_CYCLES * MHZ * 1000000) / YM_CLOCK_HZ)
#define YM_BUSY 0x80

extern uint32_t next_ym_write_valid_tick;
