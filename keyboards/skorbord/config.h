// Copyright 2023 Per (@defsax)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
// #define NO_ACTION_LAYER
// #define NO_ACTION_TAPPING
// #define NO_ACTION_ONESHOT

#define MASTER_LEFT
// #define USE_I2C
// #define DIODE_DIRECTION COL2ROW

/*
    CONVERSION CHART

    Pro Micro  ATMEGA32U4  Pro Micro  ATMEGA32U4
    TX0        D3          RAW
    RX1        D2          GND
    GND                    RST
    GND                    VCC
    2          D1          A3         F4
    3          D0          A2         F5
    4          D4          A1         F6
    5          C6          A0         F7
    6          D7          15         B1
    7          E6          14         B3
    8          B4          16         B2
    9          B5          10         B6
*/

// #define MATRIX_ROWS 5
// #define MATRIX_COLS 6
// #define MATRIX_ROW_PINS  { C6, D7, E6, B4, B5 }
// #define MATRIX_COL_PINS  { F6, F7, B1, B3, B2, B6 }