/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#define LAYOUT_UNIV LAYOUT_KYRIA_HALCYON
#include "shared/indianboy42/common.h"
#include "shared/indianboy42/custom_keycodes.h"
#include "shared/indianboy42/tap_dance.h"
#include "shared/indianboy42/keymaps.h"

// Pointing device functionality
void drag_scroll(report_mouse_t *mouse_report) {
#define SCROLL_DIVISOR_V 15.0
#define SCROLL_DIVISOR_H (-SCROLL_DIVISOR_V)
    static float scroll_accumulated_h = 0;
    static float scroll_accumulated_v = 0;
    // Calculate and accumulate scroll values based on mouse movement and divisors
    scroll_accumulated_h += (float)mouse_report->x / SCROLL_DIVISOR_H;
    scroll_accumulated_v += (float)mouse_report->y / SCROLL_DIVISOR_V;

    // Assign integer parts of accumulated scroll values to the mouse report
    mouse_report->h = (int8_t)scroll_accumulated_h;
    mouse_report->v = (int8_t)scroll_accumulated_v;

    // Update accumulated scroll values by subtracting the integer parts
    scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
    scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

    // Clear the X and Y values of the mouse report
    mouse_report->x = 0;
    mouse_report->y = 0;
}

report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
    switch (get_highest_layer(layer_state)) {
        default:
            break;
    }
    report_mouse_t mouse_report = pointing_device_combine_reports(left_report, right_report);
    // TODO:
    // drag scrolling
    // right click
    // cursor movement
    // varying sensitivity
    static bool holding   = false;
    bool        righthand = true;
    switch (get_highest_layer(layer_state)) {
        default:
            break;
        case _SYM:
            righthand = false;
        case _SYMR:
        case _NAV:
            if (mouse_report.h || mouse_report.v) {
                static float amount = 0;
                amount += (float)(mouse_report.h + mouse_report.v);
                while (fabs(amount) > 1) {
                    if (righthand)
                        tap_code16(amount > 0 ? KC_UP : KC_DOWN);
                    else
                        tap_code16(amount > 0 ? CC_LEFT : CC_RIGHT);
                    amount -= amount > 0 ? 1 : -1;
                }
                // TODO: arrow keys
                mouse_report.h = 0;
                mouse_report.v = 0;
            } else {
                drag_scroll(&mouse_report);
            }
            break;
    }
    if (holding) mouse_report.buttons |= MOUSE_BTN1;
    return mouse_report;
}
