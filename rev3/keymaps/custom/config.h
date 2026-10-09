#pragma once

#undef OLED_FONT_H
#define OLED_FONT_H "custom_font.c"

#define is_mac_mode() (!keymap_config.swap_lalt_lgui)

#define SPLIT_USB_DETECT
#define SPLIT_WATCHDOG_ENABLE
#define USB_MAX_POWER_CONSUMPTION 100
