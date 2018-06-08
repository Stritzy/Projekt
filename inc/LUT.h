// =====================================================================
//
//	Exported by Cearn's excellut v1.0
//	(comments, kudos, flames to daytshen@hotmail.com)
//
// =====================================================================
#include "stm32f30x_conf.h" // STM32 config

#ifndef LUT_H
#define LUT_H

// === LUT SIZES ===
#define SIN_SIZE 512
#define COS_SIZE 512

// === LUT DECLARATIONS ===
extern const signed short SIN[512];
extern const signed short COS[512];

#endif	// LUT_H
