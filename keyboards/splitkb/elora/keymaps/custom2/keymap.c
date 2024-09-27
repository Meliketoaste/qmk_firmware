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
#include "keymap_norwegian.h"
#include "sendstring_norwegian.h"
#include "qmk-vim/src/vim.h"
#include "features/custom_shift_keys.h"
#include "features/achordion.h"

const custom_shift_key_t custom_shift_keys[] = {
  //{NO_DOT , KC_QUES}, // Shift . is ?
  //{KC_COMM, KC_EXLM}, // Shift , is !
  //{KC_MINS, KC_EQL }, // Shift - is =
  //{KC_COLN, KC_SCLN}, // Shift : is ;
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

enum layers {
    _QWERTY = 0,
    _DVORAK,
    _COLEMAK_DH,
    _LSALT,
    _RSALT,
    _NORMAL,
    _NAV,
    _SYM,
    _FUNCTION,
    _ADJUST,
};

enum my_keycodes {
  FOO = SAFE_RANGE,

  TOG_VIM,
  BAR
  };



// Aliases for readability
#define QWERTY   DF(_QWERTY)
#define COLEMAK  DF(_COLEMAK_DH)
#define DVORAK   DF(_DVORAK)
#define NORMAL   DF(_NORMAL)

#define CTL_TAP   LCTL_T(KC_BSPC)




#define HOME_SLSH MT(MOD_RGUI, KC_SLSH);
#define HOME_Q MT(MOD_LGUI, KC_Q)
#define HOME_P MT(MOD_LGUI, KC_P)

#define SYM_SCLN LT(_SYM, S(KC_COMM))


#define SYM      MO(_SYM)
#define RSALT      MO(_RSALT)
#define LSALT      MO(_LSALT)
#define SYM      MO(_SYM)

#define NAV      MO(_NAV)
#define FKEYS    MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  LT(LSALT, KC_ENT)



#define SYM_A LT(_SYM, KC_A)
#define LALT_S MT(MOD_LALT, KC_S)
#define LSFT_D MT(MOD_LSFT, KC_D)
#define LCTL_F MT(MOD_LCTL, KC_F)

#define LALT_L MT(MOD_LALT, KC_L)
#define RSFT_K MT(MOD_RSFT, KC_K)
#define LCTL_J MT(MOD_LCTL, KC_J)

#define BACK_CTL LCTL_T(KC_BSPC)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌──────┬────────┬───────────┬───────────┬───────────┬─────────────┐     ┌──────┐   ┌───────┐         ┌──────────────┬───────────┬───────────┬───────────┬──────────┬─────────┐
//    │ esc  │   1    │     2     │     3     │     4     │      5      │     │ lsft │   │ rsft  │         │      6       │     7     │     8     │     9     │    0     │   FOO   │
//    ├──────┼────────┼───────────┼───────────┼───────────┼─────────────┤     ├──────┤   ├───────┤         ├──────────────┼───────────┼───────────┼───────────┼──────────┼─────────┤
//    │ tab  │ HOME_Q │     w     │     e     │     r     │      t      │     │ lctl │   │ rctl  │         │      y       │     u     │     i     │     o     │  HOME_P  │  bspc   │
//    ├──────┼────────┼───────────┼───────────┼───────────┼─────────────┤     ├──────┤   ├───────┤         ├──────────────┼───────────┼───────────┼───────────┼──────────┼─────────┤
//    │ lctl │ SYM_A  │ LALT_T(s) │ LSFT_T(d) │ LCTL_T(f) │      g      │     │ lalt │   │ ralt  │         │      h       │ RCTL_T(j) │ RSFT_T(k) │ LALT_T(l) │ SYM_SCLN │ NO_QUOT │
//    ├──────┼────────┼───────────┼───────────┼───────────┼─────────────┼─────┼──────┤   ├───────┼─────────┼──────────────┼───────────┼───────────┼───────────┼──────────┼─────────┤
//    │ lsft │   z    │     x     │     c     │     v     │      b      │  [  │ caps │   │ FKEYS │    ]    │      n       │     m     │     ,     │     .     │    /     │  rsft   │
//    └──────┴────────┴───────────┼───────────┼───────────┼─────────────┼─────┼──────┤   ├───────┼─────────┼──────────────┼───────────┼───────────┼───────────┴──────────┴─────────┘
//                                │  ADJUST   │   lgui    │ LALT_T(ent) │ spc │ NAV  │   │  SYM  │ CTL_TAP │ LCTL_T(bspc) │   rsft    │    app    │
//                                └───────────┴───────────┴─────────────┴─────┴──────┘   └───────┴─────────┴──────────────┴───────────┴───────────┘
[_QWERTY] = LAYOUT(
  KC_ESC  , KC_1   , KC_2         , KC_3         , KC_4         , KC_5           ,           KC_LSFT ,     KC_RSFT ,           KC_6            , KC_7         , KC_8         , KC_9         , KC_0     , FOO    ,
  KC_TAB  , HOME_Q , KC_W         , KC_E         , KC_R         , KC_T           ,           KC_LCTL ,     KC_RCTL ,           KC_Y            , KC_U         , KC_I         , KC_O         , HOME_P   , KC_BSPC,
  KC_LCTL , SYM_A  , LALT_T(KC_S) , LSFT_T(KC_D) , LCTL_T(KC_F) , KC_G           ,           KC_LALT ,     KC_RALT ,           KC_H            , RCTL_T(KC_J) , RSFT_T(KC_K) , LALT_T(KC_L) , SYM_SCLN , NO_QUOT,
  KC_LSFT , KC_Z   , KC_X         , KC_C         , KC_V         , KC_B           , KC_LBRC , KC_CAPS ,     FKEYS   , KC_RBRC , KC_N            , KC_M         , KC_COMM      , KC_DOT       , KC_SLSH  , KC_RSFT,
                                    ADJUST       , KC_LGUI      , LALT_T(KC_ENT) , KC_SPC  , NAV     ,     SYM     , CTL_TAP , LCTL_T(KC_BSPC) , KC_RSFT      , KC_APP
),

//    ┌─────────┬───┬───┬────────┬──────┬─────────┐     ┌──────┐   ┌───────┐     ┌──────┬──────┬─────┬───┬───┬──────────┐
//    │   esc   │ 1 │ 2 │   3    │  4   │    5    │     │ lsft │   │ rsft  │     │  6   │  7   │  8  │ 9 │ 0 │   esc    │
//    ├─────────┼───┼───┼────────┼──────┼─────────┤     ├──────┤   ├───────┤     ├──────┼──────┼─────┼───┼───┼──────────┤
//    │   tab   │ ' │ , │   .    │  p   │    y    │     │ lctl │   │ rctl  │     │  f   │  g   │  c  │ r │ l │   bspc   │
//    ├─────────┼───┼───┼────────┼──────┼─────────┤     ├──────┤   ├───────┤     ├──────┼──────┼─────┼───┼───┼──────────┤
//    │ CTL_ESC │ a │ o │   e    │  u   │    i    │     │ lalt │   │ ralt  │     │  d   │  h   │  t  │ n │ s │ CTL_MINS │
//    ├─────────┼───┼───┼────────┼──────┼─────────┼─────┼──────┤   ├───────┼─────┼──────┼──────┼─────┼───┼───┼──────────┤
//    │  lsft   │ ; │ q │   j    │  k   │    x    │  [  │ caps │   │ FKEYS │  ]  │  b   │  m   │  w  │ v │ z │   rsft   │
//    └─────────┴───┴───┼────────┼──────┼─────────┼─────┼──────┤   ├───────┼─────┼──────┼──────┼─────┼───┴───┴──────────┘
//                      │ ADJUST │ lgui │ ALT_ENT │ spc │ NAV  │   │  SYM  │ spc │ ralt │ rgui │ app │
//                      └────────┴──────┴─────────┴─────┴──────┘   └───────┴─────┴──────┴──────┴─────┘
[_DVORAK] = LAYOUT(
  KC_ESC  , KC_1     , KC_2    , KC_3   , KC_4    , KC_5    ,           KC_LSFT ,     KC_RSFT ,           KC_6    , KC_7    , KC_8   , KC_9 , KC_0 , KC_ESC  ,
  KC_TAB  , KC_QUOTE , KC_COMM , KC_DOT , KC_P    , KC_Y    ,           KC_LCTL ,     KC_RCTL ,           KC_F    , KC_G    , KC_C   , KC_R , KC_L , KC_BSPC ,
  CTL_ESC , KC_A     , KC_O    , KC_E   , KC_U    , KC_I    ,           KC_LALT ,     KC_RALT ,           KC_D    , KC_H    , KC_T   , KC_N , KC_S , CTL_MINS,
  KC_LSFT , KC_SCLN  , KC_Q    , KC_J   , KC_K    , KC_X    , KC_LBRC , KC_CAPS ,     FKEYS   , KC_RBRC , KC_B    , KC_M    , KC_W   , KC_V , KC_Z , KC_RSFT ,
                                 ADJUST , KC_LGUI , ALT_ENT , KC_SPC  , NAV     ,     SYM     , KC_SPC  , KC_RALT , KC_RGUI , KC_APP
),

//    ┌─────────┬───┬───┬────────┬──────┬─────────┐     ┌──────┐   ┌───────┐     ┌──────┬──────┬─────┬───┬───┬──────────┐
//    │   esc   │ 1 │ 2 │   3    │  4   │    5    │     │ lsft │   │ rsft  │     │  6   │  7   │  8  │ 9 │ 0 │   esc    │
//    ├─────────┼───┼───┼────────┼──────┼─────────┤     ├──────┤   ├───────┤     ├──────┼──────┼─────┼───┼───┼──────────┤
//    │   tab   │ q │ w │   f    │  p   │    b    │     │ lctl │   │ rctl  │     │  j   │  l   │  u  │ y │ ; │   bspc   │
//    ├─────────┼───┼───┼────────┼──────┼─────────┤     ├──────┤   ├───────┤     ├──────┼──────┼─────┼───┼───┼──────────┤
//    │ CTL_ESC │ a │ r │   s    │  t   │    g    │     │ lalt │   │ ralt  │     │  m   │  n   │  e  │ i │ o │ CTL_QUOT │
//    ├─────────┼───┼───┼────────┼──────┼─────────┼─────┼──────┤   ├───────┼─────┼──────┼──────┼─────┼───┼───┼──────────┤
//    │  lsft   │ z │ x │   c    │  d   │    v    │  [  │ caps │   │ FKEYS │  ]  │  k   │  h   │  ,  │ . │ / │   rsft   │
//    └─────────┴───┴───┼────────┼──────┼─────────┼─────┼──────┤   ├───────┼─────┼──────┼──────┼─────┼───┴───┴──────────┘
//                      │ ADJUST │ lgui │ ALT_ENT │ spc │ NAV  │   │  SYM  │ spc │ ralt │ rgui │ app │
//                      └────────┴──────┴─────────┴─────┴──────┘   └───────┴─────┴──────┴──────┴─────┘
[_COLEMAK_DH] = LAYOUT(
  KC_ESC  , KC_1 , KC_2 , KC_3   , KC_4    , KC_5    ,           KC_LSFT ,     KC_RSFT ,           KC_6    , KC_7    , KC_8    , KC_9   , KC_0    , KC_ESC  ,
  KC_TAB  , KC_Q , KC_W , KC_F   , KC_P    , KC_B    ,           KC_LCTL ,     KC_RCTL ,           KC_J    , KC_L    , KC_U    , KC_Y   , KC_SCLN , KC_BSPC ,
  CTL_ESC , KC_A , KC_R , KC_S   , KC_T    , KC_G    ,           KC_LALT ,     KC_RALT ,           KC_M    , KC_N    , KC_E    , KC_I   , KC_O    , CTL_QUOT,
  KC_LSFT , KC_Z , KC_X , KC_C   , KC_D    , KC_V    , KC_LBRC , KC_CAPS ,     FKEYS   , KC_RBRC , KC_K    , KC_H    , KC_COMM , KC_DOT , KC_SLSH , KC_RSFT ,
                          ADJUST , KC_LGUI , ALT_ENT , KC_SPC  , NAV     ,     SYM     , KC_SPC  , KC_RALT , KC_RGUI , KC_APP
),

//    ┌─────┬─────┬─────────┬─────────┬────────┬─────┐     ┌─────┐   ┌─────┐     ┌─────┬───────────────────────┬───────────────────────┬───────────────────────┬──────┬─────┐
//    │     │     │         │         │        │     │     │     │   │     │     │     │                       │                       │                       │      │     │
//    ├─────┼─────┼─────────┼─────────┼────────┼─────┤     ├─────┤   ├─────┤     ├─────┼───────────────────────┼───────────────────────┼───────────────────────┼──────┼─────┤
//    │  `  │  1  │    2    │    3    │   4    │  5  │     │     │   │     │     │  6  │           7           │           8           │           9           │  0   │  =  │
//    ├─────┼─────┼─────────┼─────────┼────────┼─────┤     ├─────┤   ├─────┤     ├─────┼───────────────────────┼───────────────────────┼───────────────────────┼──────┼─────┤
//    │  ~  │  !  │ NO_MINS │ NO_PLUS │ NO_EQL │  %  │     │     │   │     │     │  ^  │ LM(_NORMAL, MOD_LCTL) │ LM(_NORMAL, MOD_LSFT) │ LM(_NORMAL, MOD_RALT) │ lgui │  +  │
//    ├─────┼─────┼─────────┼─────────┼────────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼───────────────────────┼───────────────────────┼───────────────────────┼──────┼─────┤
//    │  |  │  \  │ NO_SLSH │ NO_ASTR │   -    │  [  │  {  │     │   │     │  }  │  ]  │           _           │        NO_LCBR        │        NO_RCBR        │  /   │  ?  │
//    └─────┴─────┴─────────┼─────────┼────────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼───────────────────────┼───────────────────────┼───────────────────────┴──────┴─────┘
//                          │         │        │     │     │     │   │     │     │     │                       │                       │
//                          └─────────┴────────┴─────┴─────┴─────┘   └─────┴─────┴─────┴───────────────────────┴───────────────────────┘
[_RSALT] = LAYOUT(
  _______ , _______ , _______ , _______ , _______ , _______ ,           _______ ,     _______ ,           _______ , _______               , _______               , _______               , _______ , _______,
  KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,           _______ ,     _______ ,           KC_6    , KC_7                  , KC_8                  , KC_9                  , KC_0    , KC_EQL ,
  KC_TILD , KC_EXLM , NO_MINS , NO_PLUS , NO_EQL  , KC_PERC ,           _______ ,     _______ ,           KC_CIRC , LM(_NORMAL, MOD_LCTL) , LM(_NORMAL, MOD_LSFT) , LM(_NORMAL, MOD_RALT) , KC_LGUI , KC_PLUS,
  KC_PIPE , KC_BSLS , NO_SLSH , NO_ASTR , KC_MINS , KC_LBRC , KC_LCBR , _______ ,     _______ , KC_RCBR , KC_RBRC , KC_UNDS               , NO_LCBR               , NO_RCBR               , KC_SLSH , KC_QUES,
                                _______ , _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , _______               , _______
),
//    ┌─────┬──────┬───────────────────────┬───────────────────────┬───────────────────────┬─────┐     ┌─────┐   ┌─────┐     ┌─────────┬─────────┬─────┬───┬─────────┬───────┐
//    │     │      │                       │                       │                       │     │     │     │   │     │     │    6    │    7    │  8  │ 9 │    0    │  FOO  │
//    ├─────┼──────┼───────────────────────┼───────────────────────┼───────────────────────┼─────┤     ├─────┤   ├─────┤     ├─────────┼─────────┼─────┼───┼─────────┼───────┤
//    │  `  │  1   │           2           │           3           │           4           │  5  │     │     │   │     │     │    y    │    u    │  i  │ o │    p    │ bspc  │
//    ├─────┼──────┼───────────────────────┼───────────────────────┼───────────────────────┼─────┤     ├─────┤   ├─────┤     ├─────────┼─────────┼─────┼───┼─────────┼───────┤
//    │  ~  │ lgui │ LM(_NORMAL, MOD_LALT) │ LM(_NORMAL, MOD_LSFT) │ LM(_NORMAL, MOD_LCTL) │  %  │     │     │   │     │     │    h    │    j    │  k  │ l │ NO_OSTR │ NO_AE │
//    ├─────┼──────┼───────────────────────┼───────────────────────┼───────────────────────┼─────┼─────┼─────┤   ├─────┼─────┼─────────┼─────────┼─────┼───┼─────────┼───────┤
//    │  |  │  \   │        NO_SLSH        │        NO_ASTR        │           -           │  [  │  {  │     │   │     │  }  │    n    │    m    │  ,  │ . │    /    │ rsft  │
//    └─────┴──────┴───────────────────────┼───────────────────────┼───────────────────────┼─────┼─────┼─────┤   ├─────┼─────┼─────────┼─────────┼─────┼───┴─────────┴───────┘
//                                         │                       │                       │     │     │     │   │     │ spc │ NO_LABK │ NO_RABK │     │
//                                         └───────────────────────┴───────────────────────┴─────┴─────┴─────┘   └─────┴─────┴─────────┴─────────┴─────┘
[_LSALT] = LAYOUT(
  _______ , _______ , _______               , _______               , _______               , _______ ,           _______ ,     _______ ,           KC_6    , KC_7    , KC_8    , KC_9   , KC_0    , FOO    ,
  KC_GRV  , KC_1    , KC_2                  , KC_3                  , KC_4                  , KC_5    ,           _______ ,     _______ ,           KC_Y    , KC_U    , KC_I    , KC_O   , KC_P    , KC_BSPC,
  KC_TILD , KC_LGUI , LM(_NORMAL, MOD_LALT) , LM(_NORMAL, MOD_LSFT) , LM(_NORMAL, MOD_LCTL) , KC_PERC ,           _______ ,     _______ ,           KC_H    , KC_J    , KC_K    , KC_L   , NO_OSTR , NO_AE  ,
  KC_PIPE , KC_BSLS , NO_SLSH               , NO_ASTR               , KC_MINS               , KC_LBRC , KC_LCBR , _______ ,     _______ , KC_RCBR , KC_N    , KC_M    , KC_COMM , KC_DOT , KC_SLSH , KC_RSFT,
                                              _______               , _______               , _______ , _______ , _______ ,     _______ , KC_SPC  , NO_LABK , NO_RABK , _______
),

//    ┌─────────┬───┬───┬────────┬──────┬─────────┐     ┌──────┐   ┌───────┐     ┌──────┬──────┬─────┬───┬─────────┬───────┐
//    │   esc   │ 1 │ 2 │   3    │  4   │    5    │     │ lsft │   │ rsft  │     │  6   │  7   │  8  │ 9 │    0    │  FOO  │
//    ├─────────┼───┼───┼────────┼──────┼─────────┤     ├──────┤   ├───────┤     ├──────┼──────┼─────┼───┼─────────┼───────┤
//    │   tab   │ q │ w │   e    │  r   │    t    │     │ lctl │   │ rctl  │     │  y   │  u   │  i  │ o │    p    │ bspc  │
//    ├─────────┼───┼───┼────────┼──────┼─────────┤     ├──────┤   ├───────┤     ├──────┼──────┼─────┼───┼─────────┼───────┤
//    │ CTL_ESC │ a │ s │   d    │  f   │    g    │     │ lalt │   │ ralt  │     │  h   │  j   │  k  │ l │ NO_OSTR │ NO_AE │
//    ├─────────┼───┼───┼────────┼──────┼─────────┼─────┼──────┤   ├───────┼─────┼──────┼──────┼─────┼───┼─────────┼───────┤
//    │  lsft   │ z │ x │   c    │  v   │    b    │  [  │ caps │   │ FKEYS │  ]  │  n   │  m   │  ,  │ . │    /    │ rsft  │
//    └─────────┴───┴───┼────────┼──────┼─────────┼─────┼──────┤   ├───────┼─────┼──────┼──────┼─────┼───┴─────────┴───────┘
//                      │ ADJUST │ lgui │ ALT_ENT │ spc │ NAV  │   │  SYM  │ spc │ ralt │ rgui │ app │
//                      └────────┴──────┴─────────┴─────┴──────┘   └───────┴─────┴──────┴──────┴─────┘
[_NORMAL] = LAYOUT(
  KC_ESC  , KC_1 , KC_2 , KC_3   , KC_4    , KC_5    ,           KC_LSFT ,     KC_RSFT ,           KC_6    , KC_7    , KC_8    , KC_9   , KC_0    , FOO    ,
  KC_TAB  , KC_Q , KC_W , KC_E   , KC_R    , KC_T    ,           KC_LCTL ,     KC_RCTL ,           KC_Y    , KC_U    , KC_I    , KC_O   , KC_P    , KC_BSPC,
  CTL_ESC , KC_A , KC_S , KC_D   , KC_F    , KC_G    ,           KC_LALT ,     KC_RALT ,           KC_H    , KC_J    , KC_K    , KC_L   , NO_OSTR , NO_AE  ,
  KC_LSFT , KC_Z , KC_X , KC_C   , KC_V    , KC_B    , KC_LBRC , KC_CAPS ,     FKEYS   , KC_RBRC , KC_N    , KC_M    , KC_COMM , KC_DOT , KC_SLSH , KC_RSFT,
                          ADJUST , KC_LGUI , ALT_ENT , KC_SPC  , NAV     ,     SYM     , KC_SPC  , KC_RALT , KC_RGUI , KC_APP
),

//    ┌─────┬──────┬──────┬────────────────────┬──────┬─────┐     ┌──────┐   ┌─────────┐      ┌──────┬──────┬──────┬──────┬──────┬──────┐
//    │     │      │      │                    │      │     │     │      │   │         │      │      │      │      │      │      │      │
//    ├─────┼──────┼──────┼────────────────────┼──────┼─────┤     ├──────┤   ├─────────┤      ├──────┼──────┼──────┼──────┼──────┼──────┤
//    │     │      │      │                    │      │     │     │      │   │         │      │ pgdn │ home │ pgup │ end  │ volu │ del  │
//    ├─────┼──────┼──────┼────────────────────┼──────┼─────┤     ├──────┤   ├─────────┤      ├──────┼──────┼──────┼──────┼──────┼──────┤
//    │     │ lgui │ lalt │        lctl        │ lsft │     │     │      │   │         │      │ left │ down │  up  │ rght │ vold │ ins  │
//    ├─────┼──────┼──────┼────────────────────┼──────┼─────┼─────┼──────┤   ├─────────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
//    │     │      │      │                    │      │     │     │ sCRL │   │ QK_REP  │      │ paus │ mprv │ mply │ mnxt │ mute │ pscr │
//    └─────┴──────┴──────┼────────────────────┼──────┼─────┼─────┼──────┤   ├─────────┼──────┼──────┼──────┼──────┼──────┴──────┴──────┘
//                        │ LM(_SYM, MOD_LGUI) │      │     │     │      │   │ QK_LEAD │ bspc │      │      │      │
//                        └────────────────────┴──────┴─────┴─────┴──────┘   └─────────┴──────┴──────┴──────┴──────┘
[_NAV] = LAYOUT(
  _______ , _______ , _______ , _______            , _______ , _______ ,           _______ ,     _______ ,           _______  , _______ , _______ , _______ , _______ , _______,
  _______ , _______ , _______ , _______            , _______ , _______ ,           _______ ,     _______ ,           KC_PGDN  , KC_HOME , KC_PGUP , KC_END  , KC_VOLU , KC_DEL ,
  _______ , KC_LGUI , KC_LALT , KC_LCTL            , KC_LSFT , _______ ,           _______ ,     _______ ,           KC_LEFT  , KC_DOWN , KC_UP   , KC_RGHT , KC_VOLD , KC_INS ,
  _______ , _______ , _______ , _______            , _______ , _______ , _______ , KC_SCRL ,     QK_REP  , _______ , KC_PAUSE , KC_MPRV , KC_MPLY , KC_MNXT , KC_MUTE , KC_PSCR,
                                LM(_SYM, MOD_LGUI) , _______ , _______ , _______ , _______ ,     QK_LEAD , KC_BSPC , _______  , _______ , _______
),

//    ┌─────┬─────────┬─────────┬─────────┬─────────┬─────────┐     ┌─────┐   ┌─────┐     ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────┐
//    │     │         │         │         │         │         │     │     │   │     │     │         │         │         │         │         │     │
//    ├─────┼─────────┼─────────┼─────────┼─────────┼─────────┤     ├─────┤   ├─────┤     ├─────────┼─────────┼─────────┼─────────┼─────────┼─────┤
//    │  `  │ NO_COMM │ NO_LABK │ NO_RABK │ NO_DQUO │ NO_DOT  │     │     │   │     │     │ NO_AMPR │    7    │ NO_LBRC │ NO_RBRC │ NO_PERC │  =  │
//    ├─────┼─────────┼─────────┼─────────┼─────────┼─────────┤     ├─────┤   ├─────┤     ├─────────┼─────────┼─────────┼─────────┼─────────┼─────┤
//    │  ~  │    !    │ NO_MINS │ NO_PLUS │ NO_EQL  │ NO_HASH │     │     │   │     │     │ NO_PIPE │ NO_COLN │ NO_LPRN │ NO_RPRN │ NO_QUES │  +  │
//    ├─────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────┼─────┤   ├─────┼─────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────┤
//    │  |  │ NO_CIRC │ NO_SLSH │ NO_ASTR │ NO_BSLS │    [    │  {  │     │   │     │  }  │ NO_TILD │ NO_DLR  │ NO_LCBR │ NO_RCBR │  NO_AT  │  ?  │
//    └─────┴─────────┴─────────┼─────────┼─────────┼─────────┼─────┼─────┤   ├─────┼─────┼─────────┼─────────┼─────────┼─────────┴─────────┴─────┘
//                              │         │         │         │     │     │   │     │     │         │         │         │
//                              └─────────┴─────────┴─────────┴─────┴─────┘   └─────┴─────┴─────────┴─────────┴─────────┘
[_SYM] = LAYOUT(
  _______ , _______ , _______ , _______ , _______ , _______ ,           _______ ,     _______ ,           _______ , _______ , _______ , _______ , _______ , _______,
  KC_GRV  , NO_COMM , NO_LABK , NO_RABK , NO_DQUO , NO_DOT  ,           _______ ,     _______ ,           NO_AMPR , KC_7    , NO_LBRC , NO_RBRC , NO_PERC , KC_EQL ,
  KC_TILD , KC_EXLM , NO_MINS , NO_PLUS , NO_EQL  , NO_HASH ,           _______ ,     _______ ,           NO_PIPE , NO_COLN , NO_LPRN , NO_RPRN , NO_QUES , KC_PLUS,
  KC_PIPE , NO_CIRC , NO_SLSH , NO_ASTR , NO_BSLS , KC_LBRC , KC_LCBR , _______ ,     _______ , KC_RCBR , NO_TILD , NO_DLR  , NO_LCBR , NO_RCBR , NO_AT   , KC_QUES,
                                _______ , _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , _______ , _______
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
//                      └─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴──────┴──────┘
[_FUNCTION] = LAYOUT(
  _______ , _______ , _______ , _______ , _______ , _______ ,           _______ ,     _______ ,           _______ , _______ , _______ , _______ , _______ , _______,
  _______ , KC_F9   , KC_F10  , KC_F11  , KC_F12  , _______ ,           _______ ,     _______ ,           _______ , _______ , _______ , _______ , _______ , _______,
  _______ , KC_F5   , KC_F6   , KC_F7   , KC_F8   , _______ ,           _______ ,     _______ ,           _______ , KC_RSFT , KC_RCTL , KC_LALT , KC_RGUI , _______,
  _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , _______ , _______ , _______ ,     _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______,
                                _______ , _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , _______ , _______
),

//    ┌─────┬─────┬─────┬─────────┬─────┬─────┐     ┌─────┐   ┌─────┐     ┌─────────┬─────────┬─────────┬─────────┬──────────┬─────┐
//    │     │     │     │ NORMAL  │     │     │     │     │   │     │     │         │         │         │         │          │     │
//    ├─────┼─────┼─────┼─────────┼─────┼─────┤     ├─────┤   ├─────┤     ├─────────┼─────────┼─────────┼─────────┼──────────┼─────┤
//    │     │     │     │ QWERTY  │     │     │     │     │   │     │     │         │         │         │         │          │     │
//    ├─────┼─────┼─────┼─────────┼─────┼─────┤     ├─────┤   ├─────┤     ├─────────┼─────────┼─────────┼─────────┼──────────┼─────┤
//    │     │     │     │ DVORAK  │     │     │     │     │   │     │     │ RGB_TOG │ RGB_SAI │ RGB_HUI │ RGB_VAI │ RGB_MOD  │     │
//    ├─────┼─────┼─────┼─────────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────────┼─────────┼─────────┼─────────┼──────────┼─────┤
//    │     │     │     │ COLEMAK │     │     │     │     │   │     │     │         │ RGB_SAD │ RGB_HUD │ RGB_VAD │ RGB_RMOD │     │
//    └─────┴─────┴─────┼─────────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────────┼─────────┼─────────┼─────────┴──────────┴─────┘
//                      │         │     │     │     │     │   │     │     │         │         │         │
//                      └─────────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────────┴─────────┴─────────┘
[_ADJUST] = LAYOUT(
  _______ , _______ , _______ , NORMAL  , _______ , _______ ,           _______ ,     _______ ,           _______ , _______ , _______ , _______ , _______  , _______,
  _______ , _______ , _______ , QWERTY  , _______ , _______ ,           _______ ,     _______ ,           _______ , _______ , _______ , _______ , _______  , _______,
  _______ , _______ , _______ , DVORAK  , _______ , _______ ,           _______ ,     _______ ,           RGB_TOG , RGB_SAI , RGB_HUI , RGB_VAI , RGB_MOD  , _______,
  _______ , _______ , _______ , COLEMAK , _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , RGB_SAD , RGB_HUD , RGB_VAD , RGB_RMOD , _______,
                                _______ , _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , _______ , _______
)
};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/elora/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_vim_mode(keycode, record)) {
        return false;
    }
    if (!process_custom_shift_keys(keycode, record)) {
        return false;
    }
    if (!process_achordion(keycode, record)) { return false; }

  switch (keycode) {

    case FOO:
      if (record->event.pressed) {
        // Do something when pressed

                toggle_vim_mode();
      } else {
        // Do something else when release
      }
      return false; // Skip all further processing of this key
        //
     case SYM_SCLN:
        if (record->tap.count && record->event.pressed) {
            tap_code16(S(KC_COMM)); // Intercept hold function to send Ctrl-X
            return false;             // Return true for normal processing of tap keycode
            }
        break;
    default:
      return true; // Process all other keycodes normally
  }
    return true;
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  // Also allow same-hand holds when the other key is in the rows outside the
  // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboards are split.
    //
  uint8_t row = other_record->event.key.row % (MATRIX_ROWS / 2);
  if (!(1 <= row && row <= 3)) { return true; }





  switch (tap_hold_keycode) {
    // Exceptionally allow symbol layer LTs + row 0 in same-hand chords.


    case SYM_A:
    case SYM_SCLN:
      if (row == 0) { return true; }
      break;
    case CTL_TAP:
      // Assuming you want to allow this key to work on the same hand.
      return true;
    case HOME_Q :
        if (other_keycode >= KC_1 && other_keycode <= KC_5) {return true;}

    case HOME_P :
        if (other_keycode >= KC_6 && other_keycode <= KC_0) {return true;}

    // Exceptionally allow G + J as a same-hand chord.
  }

  return achordion_opposite_hands(tap_hold_record, other_record);
}

//uint16_t achordion_streak_chord_timeout(uint16_t tap_hold_keycode, uint16_t next_keycode) {
//  return 0;  // Default of 100 ms.
//}

//leader
void leader_start_user(void) {
    // Do something when the leader key is pressed
}
void leader_end_user(void) {
    if (leader_sequence_one_key(KC_F)) {
        // Leader, f => Types the below string
        SEND_STRING("QMK is awesome.");
    } else if (leader_sequence_two_keys(KC_D, KC_D)) {
        // Leader, d, d => Ctrl+A, Ctrl+C
        SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    } else if (leader_sequence_three_keys(KC_D, KC_D, KC_S)) {
        // Leader, d, d, s => Types the below string
        SEND_STRING("https://start.duckduckgo.com\n");
    } else if (leader_sequence_two_keys(KC_A, KC_S)) {
        // Leader, a, s => GUI+S
        tap_code16(LGUI(KC_S));

    }
}

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
