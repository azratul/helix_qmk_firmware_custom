My Custom Helix Keyboard Layout
===

![Helix](https://i.imgur.com/XBAmynN.jpg)

## Layout

Home row mods: `A` Alt, `S` Shift, `F` GUI, `J` GUI, `L` Shift, `Ñ` AltGr.
Hold `D` for Raise, hold `K` for Lower.

`Layer` key: tap = Raise (locked), hold 1s = Lower (locked), tap again = back to Qwerty.

### Qwerty Layer (Base)
```
,-----------------------------------------.             ,-----------------------------------------.
| Esc  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |   ^  |
|------+------+------+------+------+------|             |------+------+------+------+------+------|
| Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | Bksp |
|------+------+------+------+------+------|             |------+------+------+------+------+------|
|  °   |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   Ñ  |Enter |
|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
| CAPS |   <  |   Z  |   X  |   C  |   V  |   `  |   +  |   B  |   N  |   M  |   ,  |   .  |   -  |
|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
| Ctrl |Adjust|Layer | Print|   ¿  |   '  |   ´  |Space | Ins  |  _ ! | Left | Down |  Up  |Right |
`-------------------------------------------------------------------------------------------------'
```

### Lower Layer (numpad)
```
,-----------------------------------------.             ,-----------------------------------------.
|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
|------+------+------+------+------+------|             |------+------+------+------+------+------|
|      | KP 7 | KP 8 | KP 9 | KP / |      |             |      |      |      |      |      | Del  |
|------+------+------+------+------+------|             |------+------+------+------+------+------|
|      | KP 4 | KP 5 | KP 6 | KP * |      |             |      |      |      |      |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
|      | KP 1 | KP 2 | KP 3 | KP - |      |      |      |      |      |      |      |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
|      | KP 0 |Layer | KP . | KP + | NumLk| Back | Fwd  |      |   !  | Home | PgDn | PgUp | End  |
`-------------------------------------------------------------------------------------------------'
```

### Raise Layer
```
,-----------------------------------------.             ,-----------------------------------------.
|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
|------+------+------+------+------+------|             |------+------+------+------+------+------|
|      |      |      |      |      |      |             |      |      |      |      |      | Del  |
|------+------+------+------+------+------|             |------+------+------+------+------+------|
|      |      |      |      |      |      |             |      | Left | Down |  Up  |Right |      |
|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      |      |      |      |      |      |      |      |      |      |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      |      |   ¡  |      | Back | Fwd  |      |   !  | Home | PgDn | PgUp | End  |
`-------------------------------------------------------------------------------------------------'
```

### Adjust Layer (Lower + Raise)
```
,-----------------------------------------.             ,-----------------------------------------.
|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
|------+------+------+------+------+------|             |------+------+------+------+------+------|
|      | Reset|RGBRST|EEPRST|      |      |             |      |RGB ON| HUE+ | SAT+ | VAL+ |  Del |
|------+------+------+------+------+------|             |------+------+------+------+------+------|
|      |      |      |      |      | Mac  |             | Win  | MODE | HUE- | SAT- | VAL- |      |
|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      |      |      |      |      |      |      |      |      |      |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      |      |      |      |      |      |      |      |      |      |      |      |
`-------------------------------------------------------------------------------------------------'
```

### Encoders
| Layer  | Left              | Right             |
|--------|-------------------|-------------------|
| Qwerty | Mouse wheel       | Volume            |
| Lower  | PgUp / PgDn       | Home / End        |
| Raise  | RGB brightness    | RGB speed         |
| Adjust | RGB mode          | Right / Left      |

## OLED Screen


![Live Share Preview](https://raw.githubusercontent.com/azratul/azratul/511051744799ebacea2a74a19bfd91d8ec413003/unnerv.png)


## Commands

Keymap: `rev3/keymaps/custom` (`rev3_5rows` was merged into `rev3` upstream).

```
qmk compile -kb helix/rev3 -km custom
qmk flash -kb helix/rev3 -km custom
```

## Helix

A compact split ortholinear keyboard.

Keyboard Maintainer: [Makoto Kurauchi](https://github.com/MakotoKurauchi/) [@pluis9](https://twitter.com/pluis9) [yushakobo](https://github.com/yushakobo)
Hardware Supported: Helix Pico, Beta, Rev3, Pro Micro  
Hardware Availability: [PCB & Case Data](https://github.com/MakotoKurauchi/helix), [Yushakobo Shop](https://yushakobo.jp/shop/), [Little Keyboards](https://littlekeyboards.com/collections/helix)

See [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) then the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information.
