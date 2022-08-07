#include QMK_KEYBOARD_H
// https://docs.qmk.fm/#/newbs
// AltGr + W+I+N - turns on WIN Keyboard, Default layer 0
// AltGr + W+A+C - turns on MAC Keyboard, Default layer 1
// TapDance combinations not in use
// AltGR + D + S - Delete to Word Start
// AltGR + D + E - Delete to Word End
//  AltGR + D + D - Delete entire line
//  AltGR + D + S + S- Delete to Line Start
//  AltGR + D + E + E - Delete to Line End

enum alt_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout
};
enum layers
{
    _WIN = 0,
    _MAC,
    _NAV,
    _SYS
};

// Tap Dance declarations
enum tapkeys{
    TD_C_CP,
    TD_V_PS,
    TD_Z_CC,
    TD_X_CR,
    // TD_L1
};

// C - Copy
void dance_c_ctrl_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_C);
    } else {
        register_code16(C(KC_C));
    }
}

void dance_c_ctrl_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_C);
    } else {
        unregister_code16(C(KC_C));
    }
}

// V - Paste
void dance_v_paste_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_V);
    } else {
        register_code16(C(KC_V));
    }
}

void dance_v_paste_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_V);
    } else {
        unregister_code16(C(KC_V));
    }
}


// Z - Cancel
void dance_z_cancel_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_Z);
    } else {
        register_code16(C(KC_Z));
    }
}

void dance_z_cancel_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_Z);
    } else {
        unregister_code16(C(KC_Z));
    }
}

// X - Crop
void dance_x_crop_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_X);
    } else {
        register_code16(C(KC_X));
    }
}

void dance_x_crop_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_X);
    } else {
        unregister_code16(C(KC_X));
    }
}

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_C_CP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_c_ctrl_finished, dance_c_ctrl_reset),
    [TD_V_PS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_v_paste_finished, dance_v_paste_reset),
    [TD_Z_CC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_z_cancel_finished, dance_z_cancel_reset),
    [TD_X_CR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_x_crop_finished, dance_x_crop_reset),
};

/* physical layout
 * [ ` ]  [ 1 ]  [ 2 ]  [ 3 ]  [ 4 ]  [ 5 ]  [ 6 ]  [ 7 ]  [ 8 ]  [ 9 ]  [ 0 ]  [ - ]  [ = ]  [ bksp ] [ del ]
 * [ tab* ]  [ q ]  [ w ]  [ e ]  [ r ]  [ t ]  [ y ]  [ u ]  [ i ]  [ o ]  [ p ]  [ [ ]  [ ] ]  [ home ]
 * [ ctrl* ]  [ a ]  [ s ]  [ d ]  [ f ]  [ g ]  [ h ]  [ j ]  [ k ]  [ l ]  [ ; ]  [ ' ]  [ enter ]  [ PgUp ]
 * [ lshift* ]  [ z ]  [ x ]  [ c ]  [ v ]  [ b ]  [ n ]  [ m ]  [ , ]  [ . ]  [ / ]  [ rshift* ] ]   [ ↑ ]  [ PgDn ]
 * [ ctrl ]  [ alt ]  [ meta ]  [              spaaaaaaaace             ]  [ meta ]  [ alt ]  [ ← ]  [ ↓ ]  [ → ]
 */



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Original layout
    // Capsloc - using TapDancing, Holding and double click - shitching to layer 1
    //Windows
    [_WIN] = LAYOUT_65_ansi_blocker(
        KC_ESC,  KC_1,    KC_2,    KC_3,   KC_4,     KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,     KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_INS,
        TT(_NAV),KC_A,    KC_S,    KC_D,   KC_F,     KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  XXXXXXX,
        KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,     KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   XXXXXXX,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                                      KC_LEAD, MO(_SYS),KC_LEFT, KC_DOWN, KC_RGHT
    ),
    // Mac OS 
    [_MAC] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME,
        TT(_NAV),KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_LEAD, MO(_SYS),KC_LEFT, KC_DOWN, KC_RGHT
    ),
    // Esc - Tilda, 
    // Digits - Fn row
    // Y - Home, U - One word left (Ctrl+Left), I - wone word right (Ctrl + Right), O - End
    [_NAV] = LAYOUT_65_ansi_blocker(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,      KC_F8,      KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, C(KC_LEFT), C(KC_RGHT), KC_END,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        TG(2) ,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN,    KC_UP  ,    KC_RGHT, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, C(KC_DOWN), C(KC_UP),   XXXXXXX, XXXXXXX, KC_RCTL,          XXXXXXX, XXXXXXX,
        _______, _______, _______,                            XXXXXXX,                         _______, KC_APP,           XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_SYS] = LAYOUT_65_ansi_blocker(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, KC_MUTE,
        XXXXXXX, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, XXXXXXX, U_T_AUTO,U_T_AGCR,XXXXXXX, KC_PSCR, KC_SLCK, KC_PAUS, XXXXXXX, XXXXXXX,
        XXXXXXX, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,
        KC_LSFT, RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, MD_BOOT, NK_TOGG, DBG_TOG, XXXXXXX, XXXXXXX, XXXXXXX, KC_RCTL,          KC_VOLU, KC_MPLY,
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, XXXXXXX, KC_MPRV, KC_VOLD, KC_MNXT
    ),
    /* 
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______
    ),
    */
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case (LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR): {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();
    
        //Switch to WIN layput
        SEQ_THREE_KEYS(KC_W, KC_I, KC_N) {
            set_single_persistent_default_layer(_WIN);
        }

        // Switch to MAC layout
        SEQ_THREE_KEYS(KC_M, KC_A, KC_C) {
            set_single_persistent_default_layer(_MAC);
        }

        //  AltGR + D + S - Delete to Word Start
        SEQ_TWO_KEYS(KC_D, KC_S) {
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            tap_code(KC_LEFT);
            unregister_code(KC_LCTL);
            unregister_code(KC_LSFT);
            tap_code(KC_DEL);
        }

        //  AltGR + D + E - Delete to Word End
        SEQ_TWO_KEYS(KC_D, KC_E) {
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            tap_code(KC_RGHT);
            unregister_code(KC_LCTL);
            unregister_code(KC_LSFT);
            tap_coddde(KC_DEL);
        }

        //  AltGR + D + D - Delete entire line
        SEQ_TWO_KEYS(KC_D, KC_D) {
            tap_code(KC_HOME);

            register_code(KC_LSFT);
            tap_code(KC_END);
            unregister_code(KC_LSFT);
            
            tap_code(KC_DEL);
            tap_code(KC_DEL);
        }

        //  AltGR + D + S + S- Delete to Line Start
        SEQ_THREE_KEYS(KC_D, KC_S, KC_S) {
            register_code(KC_LSFT);
            tap_code(KC_HOME);
            unregister_code(KC_LSFT);
            tap_code(KC_DEL);
        }

        //  AltGR + D + E + E - Delete to Line End
        SEQ_THREE_KEYS(KC_D, KC_E, KC_E) {
            register_code(KC_LSFT);
            tap_code(KC_END);
            unregister_code(KC_LSFT);
            tap_code(KC_DEL);
        }
  }
}


void leader_start(void) {
  //backlight_enable();
}

void leader_end(void) {
  //backlight_disable();
}
