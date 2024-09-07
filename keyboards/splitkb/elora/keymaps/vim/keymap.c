/* Copyright 2023 splitkb.com <support@splitkb.com>
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

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _DVORAK,
    _COLEMAK_DH,
    _NAV,
    _SYM,
    _FUNCTION,
    _ADJUST,
};

// Aliases for readability
#define QWERTY   DF(_QWERTY)
#define COLEMAK  DF(_COLEMAK_DH)
#define DVORAK   DF(_DVORAK)

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define FKEYS    MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌─────────┬──────┬──────┬────────┬──────┬─────────┐     ┌──────┐   ┌───────┐      ┌──────┬──────┬─────┬──────┬───┬──────────┐
//    │   esc   │  1   │  2   │   3    │  4   │    5    │     │ lsft │   │ rsft  │      │  6   │  7   │  8  │  9   │ 0 │   esc    │
//    ├─────────┼──────┼──────┼────────┼──────┼─────────┤     ├──────┤   ├───────┤      ├──────┼──────┼─────┼──────┼───┼──────────┤
//    │   tab   │  q   │  w   │   e    │  r   │    t    │     │ lctl │   │ rctl  │      │  y   │  u   │  i  │  o   │ p │   bspc   │
//    ├─────────┼──────┼──────┼────────┼──────┼─────────┤     ├──────┤   ├───────┤      ├──────┼──────┼─────┼──────┼───┼──────────┤
//    │ CTL_ESC │  a   │  s   │   d    │  f   │    g    │     │ lalt │   │ ralt  │      │  h   │  j   │  k  │  l   │ ; │ CTL_QUOT │
//    ├─────────┼──────┼──────┼────────┼──────┼─────────┼─────┼──────┤   ├───────┼──────┼──────┼──────┼─────┼──────┼───┼──────────┤
//    │  lsft   │  z   │  x   │   c    │  v   │    b    │  [  │ caps │   │ FKEYS │  ]   │  n   │  m   │  ,  │  .   │ / │   rsft   │
//    └─────────┴──────┴──────┼────────┼──────┼─────────┼─────┼──────┤   ├───────┼──────┼──────┼──────┼─────┼──────┴───┴──────────┘
//                            │ ADJUST │ lgui │ ALT_ENT │ spc │ NAV  │   │  SYM  │ spc  │ ralt │ rgui │ app │
//    ┌─────────┬──────┬──────┼────────┼──────┼─────────┼─────┴──────┘   ├───────┼──────┼──────┼──────┼─────┼──────┐
//    │  mprv   │ mnxt │ mply │  mstp  │      │  mute   │                │ mprv  │ mnxt │ mply │ mstp │     │ mute │
//    └─────────┴──────┴──────┴────────┘      └─────────┘                └───────┴──────┴──────┴──────┘     └──────┘
[_QWERTY] = LAYOUT_myr(
  KC_ESC  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,           KC_LSFT ,     KC_RSFT ,           KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_ESC  ,
  KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    ,           KC_LCTL ,     KC_RCTL ,           KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_BSPC ,
  CTL_ESC , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    ,           KC_LALT ,     KC_RALT ,           KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , CTL_QUOT,
  KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_LBRC , KC_CAPS ,     FKEYS   , KC_RBRC , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT ,
                                ADJUST  , KC_LGUI , ALT_ENT , KC_SPC  , NAV     ,     SYM     , KC_SPC  , KC_RALT , KC_RGUI , KC_APP                                ,
  KC_MPRV , KC_MNXT , KC_MPLY , KC_MSTP ,           KC_MUTE ,                         KC_MPRV , KC_MNXT , KC_MPLY , KC_MSTP ,           KC_MUTE
),

//    ┌─────────┬──────┬──────┬────────┬──────┬─────────┐     ┌──────┐   ┌───────┐      ┌──────┬──────┬─────┬──────┬───┬──────────┐
//    │   esc   │  1   │  2   │   3    │  4   │    5    │     │ lsft │   │ rsft  │      │  6   │  7   │  8  │  9   │ 0 │   esc    │
//    ├─────────┼──────┼──────┼────────┼──────┼─────────┤     ├──────┤   ├───────┤      ├──────┼──────┼─────┼──────┼───┼──────────┤
//    │   tab   │  '   │  ,   │   .    │  p   │    y    │     │ lctl │   │ rctl  │      │  f   │  g   │  c  │  r   │ l │   bspc   │
//    ├─────────┼──────┼──────┼────────┼──────┼─────────┤     ├──────┤   ├───────┤      ├──────┼──────┼─────┼──────┼───┼──────────┤
//    │ CTL_ESC │  a   │  o   │   e    │  u   │    i    │     │ lalt │   │ ralt  │      │  d   │  h   │  t  │  n   │ s │ CTL_MINS │
//    ├─────────┼──────┼──────┼────────┼──────┼─────────┼─────┼──────┤   ├───────┼──────┼──────┼──────┼─────┼──────┼───┼──────────┤
//    │  lsft   │  ;   │  q   │   j    │  k   │    x    │  [  │ caps │   │ FKEYS │  ]   │  b   │  m   │  w  │  v   │ z │   rsft   │
//    └─────────┴──────┴──────┼────────┼──────┼─────────┼─────┼──────┤   ├───────┼──────┼──────┼──────┼─────┼──────┴───┴──────────┘
//                            │ ADJUST │ lgui │ ALT_ENT │ spc │ NAV  │   │  SYM  │ spc  │ ralt │ rgui │ app │
//    ┌─────────┬──────┬──────┼────────┼──────┼─────────┼─────┴──────┘   ├───────┼──────┼──────┼──────┼─────┼──────┐
//    │  mprv   │ mnxt │ mply │  mstp  │      │  mute   │                │ mprv  │ mnxt │ mply │ mstp │     │ mute │
//    └─────────┴──────┴──────┴────────┘      └─────────┘                └───────┴──────┴──────┴──────┘     └──────┘
[_DVORAK] = LAYOUT_myr(
  KC_ESC  , KC_1     , KC_2    , KC_3    , KC_4    , KC_5    ,           KC_LSFT ,     KC_RSFT ,           KC_6    , KC_7    , KC_8   , KC_9    , KC_0 , KC_ESC  ,
  KC_TAB  , KC_QUOTE , KC_COMM , KC_DOT  , KC_P    , KC_Y    ,           KC_LCTL ,     KC_RCTL ,           KC_F    , KC_G    , KC_C   , KC_R    , KC_L , KC_BSPC ,
  CTL_ESC , KC_A     , KC_O    , KC_E    , KC_U    , KC_I    ,           KC_LALT ,     KC_RALT ,           KC_D    , KC_H    , KC_T   , KC_N    , KC_S , CTL_MINS,
  KC_LSFT , KC_SCLN  , KC_Q    , KC_J    , KC_K    , KC_X    , KC_LBRC , KC_CAPS ,     FKEYS   , KC_RBRC , KC_B    , KC_M    , KC_W   , KC_V    , KC_Z , KC_RSFT ,
                                 ADJUST  , KC_LGUI , ALT_ENT , KC_SPC  , NAV     ,     SYM     , KC_SPC  , KC_RALT , KC_RGUI , KC_APP                            ,
  KC_MPRV , KC_MNXT  , KC_MPLY , KC_MSTP ,           KC_MUTE ,                         KC_MPRV , KC_MNXT , KC_MPLY , KC_MSTP ,          KC_MUTE
),

//    ┌─────────┬──────┬──────┬────────┬──────┬─────────┐     ┌──────┐   ┌───────┐      ┌──────┬──────┬─────┬──────┬───┬──────────┐
//    │   esc   │  1   │  2   │   3    │  4   │    5    │     │ lsft │   │ rsft  │      │  6   │  7   │  8  │  9   │ 0 │   esc    │
//    ├─────────┼──────┼──────┼────────┼──────┼─────────┤     ├──────┤   ├───────┤      ├──────┼──────┼─────┼──────┼───┼──────────┤
//    │   tab   │  q   │  w   │   f    │  p   │    b    │     │ lctl │   │ rctl  │      │  j   │  l   │  u  │  y   │ ; │   bspc   │
//    ├─────────┼──────┼──────┼────────┼──────┼─────────┤     ├──────┤   ├───────┤      ├──────┼──────┼─────┼──────┼───┼──────────┤
//    │ CTL_ESC │  a   │  r   │   s    │  t   │    g    │     │ lalt │   │ ralt  │      │  m   │  n   │  e  │  i   │ o │ CTL_QUOT │
//    ├─────────┼──────┼──────┼────────┼──────┼─────────┼─────┼──────┤   ├───────┼──────┼──────┼──────┼─────┼──────┼───┼──────────┤
//    │  lsft   │  z   │  x   │   c    │  d   │    v    │  [  │ caps │   │ FKEYS │  ]   │  k   │  h   │  ,  │  .   │ / │   rsft   │
//    └─────────┴──────┴──────┼────────┼──────┼─────────┼─────┼──────┤   ├───────┼──────┼──────┼──────┼─────┼──────┴───┴──────────┘
//                            │ ADJUST │ lgui │ ALT_ENT │ spc │ NAV  │   │  SYM  │ spc  │ ralt │ rgui │ app │
//    ┌─────────┬──────┬──────┼────────┼──────┼─────────┼─────┴──────┘   ├───────┼──────┼──────┼──────┼─────┼──────┐
//    │  mprv   │ mnxt │ mply │  mstp  │      │  mute   │                │ mprv  │ mnxt │ mply │ mstp │     │ mute │
//    └─────────┴──────┴──────┴────────┘      └─────────┘                └───────┴──────┴──────┴──────┘     └──────┘
[_COLEMAK_DH] = LAYOUT_myr(
  KC_ESC  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,           KC_LSFT ,     KC_RSFT ,           KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_ESC  ,
  KC_TAB  , KC_Q    , KC_W    , KC_F    , KC_P    , KC_B    ,           KC_LCTL ,     KC_RCTL ,           KC_J    , KC_L    , KC_U    , KC_Y    , KC_SCLN , KC_BSPC ,
  CTL_ESC , KC_A    , KC_R    , KC_S    , KC_T    , KC_G    ,           KC_LALT ,     KC_RALT ,           KC_M    , KC_N    , KC_E    , KC_I    , KC_O    , CTL_QUOT,
  KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_D    , KC_V    , KC_LBRC , KC_CAPS ,     FKEYS   , KC_RBRC , KC_K    , KC_H    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT ,
                                ADJUST  , KC_LGUI , ALT_ENT , KC_SPC  , NAV     ,     SYM     , KC_SPC  , KC_RALT , KC_RGUI , KC_APP                                ,
  KC_MPRV , KC_MNXT , KC_MPLY , KC_MSTP ,           KC_MUTE ,                         KC_MPRV , KC_MNXT , KC_MPLY , KC_MSTP ,           KC_MUTE
),

//    ┌─────┬──────┬──────┬──────┬──────┬─────┐     ┌──────┐   ┌─────┐     ┌──────┬──────┬──────┬──────┬──────┬──────┐
//    │     │      │      │      │      │     │     │      │   │     │     │ pgup │      │      │      │      │      │
//    ├─────┼──────┼──────┼──────┼──────┼─────┤     ├──────┤   ├─────┤     ├──────┼──────┼──────┼──────┼──────┼──────┤
//    │     │      │      │      │      │     │     │      │   │     │     │ pgdn │ home │  up  │ end  │ volu │ del  │
//    ├─────┼──────┼──────┼──────┼──────┼─────┤     ├──────┤   ├─────┤     ├──────┼──────┼──────┼──────┼──────┼──────┤
//    │     │ lgui │ lalt │ lctl │ lsft │     │     │      │   │     │     │ left │ down │  up  │ rght │ vold │ ins  │
//    ├─────┼──────┼──────┼──────┼──────┼─────┼─────┼──────┤   ├─────┼─────┼──────┼──────┼──────┼──────┼──────┼──────┤
//    │     │      │      │      │      │     │     │ sCRL │   │     │     │ paus │ mprv │ mply │ mnxt │ mute │ pscr │
//    └─────┴──────┴──────┼──────┼──────┼─────┼─────┼──────┤   ├─────┼─────┼──────┼──────┼──────┼──────┴──────┴──────┘
//                        │      │      │     │     │      │   │     │     │      │      │      │
//    ┌─────┬──────┬──────┼──────┼──────┼─────┼─────┴──────┘   ├─────┼─────┼──────┼──────┼──────┼──────┐
//    │     │      │      │      │      │     │                │     │     │      │      │      │      │
//    └─────┴──────┴──────┴──────┘      └─────┘                └─────┴─────┴──────┴──────┘      └──────┘
[_NAV] = LAYOUT_myr(
  _______ , _______ , _______ , _______ , _______ , _______ ,           _______ ,     _______ ,           KC_PGUP  , _______ , _______ , _______ , _______ , _______,
  _______ , _______ , _______ , _______ , _______ , _______ ,           _______ ,     _______ ,           KC_PGDN  , KC_HOME , KC_UP   , KC_END  , KC_VOLU , KC_DEL ,
  _______ , KC_LGUI , KC_LALT , KC_LCTL , KC_LSFT , _______ ,           _______ ,     _______ ,           KC_LEFT  , KC_DOWN , KC_UP   , KC_RGHT , KC_VOLD , KC_INS ,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_SCRL ,     _______ , _______ , KC_PAUSE , KC_MPRV , KC_MPLY , KC_MNXT , KC_MUTE , KC_PSCR,
                                _______ , _______ , _______ , _______ , _______ ,     _______ , _______ , _______  , _______ , _______                              ,
  _______ , _______ , _______ , _______ ,           _______ ,                         _______ , _______ , _______  , _______ ,           _______
),

//    ┌─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┐   ┌─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┐
//    │     │     │     │     │     │     │     │     │   │     │     │     │     │     │     │     │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┤   ├─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │  `  │  1  │  2  │  3  │  4  │  5  │     │     │   │     │     │  6  │  7  │  8  │  9  │  0  │  =  │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┤   ├─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │  ~  │  !  │  @  │  #  │  $  │  %  │     │     │   │     │     │  ^  │  &  │  *  │  (  │  )  │  +  │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
//    │  |  │  \  │  :  │  ;  │  -  │  [  │  {  │     │   │     │  }  │  ]  │  _  │  ,  │  .  │  /  │  ?  │
//    └─────┴─────┴─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┴─────┴─────┘
//                      │     │     │     │     │     │   │     │     │     │     │     │
//    ┌─────┬─────┬─────┼─────┼─────┼─────┼─────┴─────┘   ├─────┼─────┼─────┼─────┼─────┼─────┐
//    │     │     │     │     │     │     │               │     │     │     │     │     │     │
//    └─────┴─────┴─────┴─────┘     └─────┘               └─────┴─────┴─────┴─────┘     └─────┘
[_SYM] = LAYOUT_myr(
  _______ , _______ , _______ , _______ , _______ , _______ ,           _______ ,     _______ ,           _______ , _______ , _______ , _______ , _______ , _______,
  KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,           _______ ,     _______ ,           KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_EQL ,
  KC_TILD , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC ,           _______ ,     _______ ,           KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_PLUS,
  KC_PIPE , KC_BSLS , KC_COLN , KC_SCLN , KC_MINS , KC_LBRC , KC_LCBR , _______ ,     _______ , KC_RCBR , KC_RBRC , KC_UNDS , KC_COMM , KC_DOT  , KC_SLSH , KC_QUES,
                                _______ , _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , _______ , _______                              ,
  _______ , _______ , _______ , _______ ,           _______ ,                         _______ , _______ , _______ , _______ ,           _______
),

//    ┌─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┐   ┌─────┐     ┌─────┬──────┬──────┬──────┬──────┬─────┐
//    │     │     │     │     │     │     │     │     │   │     │     │     │      │      │      │      │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┤   ├─────┤     ├─────┼──────┼──────┼──────┼──────┼─────┤
//    │     │ f9  │ f10 │ f11 │ f12 │     │     │     │   │     │     │     │      │      │      │      │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┤   ├─────┤     ├─────┼──────┼──────┼──────┼──────┼─────┤
//    │     │ f5  │ f6  │ f7  │ f8  │     │     │     │   │     │     │     │ rsft │ rctl │ lalt │ rgui │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼──────┼──────┼──────┼──────┼─────┤
//    │     │ f1  │ f2  │ f3  │ f4  │     │     │     │   │     │     │     │      │      │      │      │     │
//    └─────┴─────┴─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼──────┼──────┼──────┴──────┴─────┘
//                      │     │     │     │     │     │   │     │     │     │      │      │
//    ┌─────┬─────┬─────┼─────┼─────┼─────┼─────┴─────┘   ├─────┼─────┼─────┼──────┼──────┼──────┐
//    │     │     │     │     │     │     │               │     │     │     │      │      │      │
//    └─────┴─────┴─────┴─────┘     └─────┘               └─────┴─────┴─────┴──────┘      └──────┘
[_FUNCTION] = LAYOUT_myr(
  _______ , _______ , _______ , _______ , _______ , _______ ,           _______ ,     _______ ,           _______ , _______ , _______ , _______ , _______ , _______,
  _______ , KC_F9   , KC_F10  , KC_F11  , KC_F12  , _______ ,           _______ ,     _______ ,           _______ , _______ , _______ , _______ , _______ , _______,
  _______ , KC_F5   , KC_F6   , KC_F7   , KC_F8   , _______ ,           _______ ,     _______ ,           _______ , KC_RSFT , KC_RCTL , KC_LALT , KC_RGUI , _______,
  _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , _______ , _______ , _______ ,     _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______,
                                _______ , _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , _______ , _______                              ,
  _______ , _______ , _______ , _______ ,           _______ ,                         _______ , _______ , _______ , _______ ,           _______
),

//    ┌─────┬─────┬─────┬─────────┬─────┬─────┐     ┌─────┐   ┌─────┐     ┌─────────┬─────────┬─────────┬─────────┬──────────┬─────┐
//    │     │     │     │         │     │     │     │     │   │     │     │         │         │         │         │          │     │
//    ├─────┼─────┼─────┼─────────┼─────┼─────┤     ├─────┤   ├─────┤     ├─────────┼─────────┼─────────┼─────────┼──────────┼─────┤
//    │     │     │     │ QWERTY  │     │     │     │     │   │     │     │         │         │         │         │          │     │
//    ├─────┼─────┼─────┼─────────┼─────┼─────┤     ├─────┤   ├─────┤     ├─────────┼─────────┼─────────┼─────────┼──────────┼─────┤
//    │     │     │     │ DVORAK  │     │     │     │     │   │     │     │ RGB_TOG │ RGB_SAI │ RGB_HUI │ RGB_VAI │ RGB_MOD  │     │
//    ├─────┼─────┼─────┼─────────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────────┼─────────┼─────────┼─────────┼──────────┼─────┤
//    │     │     │     │ COLEMAK │     │     │     │     │   │     │     │         │ RGB_SAD │ RGB_HUD │ RGB_VAD │ RGB_RMOD │     │
//    └─────┴─────┴─────┼─────────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────────┼─────────┼─────────┼─────────┴──────────┴─────┘
//                      │         │     │     │     │     │   │     │     │         │         │         │
//    ┌─────┬─────┬─────┼─────────┼─────┼─────┼─────┴─────┘   ├─────┼─────┼─────────┼─────────┼─────────┼─────────┐
//    │     │     │     │         │     │     │               │     │     │         │         │         │         │
//    └─────┴─────┴─────┴─────────┘     └─────┘               └─────┴─────┴─────────┴─────────┘         └─────────┘
[_ADJUST] = LAYOUT_myr(
  _______ , _______ , _______ , _______ , _______ , _______ ,           _______ ,     _______ ,           _______ , _______ , _______ , _______ , _______  , _______,
  _______ , _______ , _______ , QWERTY  , _______ , _______ ,           _______ ,     _______ ,           _______ , _______ , _______ , _______ , _______  , _______,
  _______ , _______ , _______ , DVORAK  , _______ , _______ ,           _______ ,     _______ ,           RGB_TOG , RGB_SAI , RGB_HUI , RGB_VAI , RGB_MOD  , _______,
  _______ , _______ , _______ , COLEMAK , _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , RGB_SAD , RGB_HUD , RGB_VAD , RGB_RMOD , _______,
                                _______ , _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , _______ , _______                               ,
  _______ , _______ , _______ , _______ ,           _______ ,                         _______ , _______ , _______ , _______ ,           _______
)
};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/elora/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

/* DELETE THIS LINE TO UNCOMMENT (1/2)
#ifdef OLED_ENABLE
bool oled_task_user(void) {
  // Your code goes here
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  // Your code goes here
}
#endif
DELETE THIS LINE TO UNCOMMENT (2/2) */
