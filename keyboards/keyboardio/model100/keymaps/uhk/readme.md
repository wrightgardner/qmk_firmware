# uhk keymap for the Keyboardio Model 100

My personal keymap. See `MODEL100-NOTES.md` at the repo root for how the fork is
set up, how to update it, and how to go back to Kaleidoscope.

## Layers

| Layer | Name   | How to reach it    | Contents                                         |
|-------|--------|--------------------|--------------------------------------------------|
| 0     | Base   | default            | QWERTY, `QK_BOOT` on the top-left key            |
| 1     | Numpad | `TG(1)`            | Numpad on the right hand                         |
| 2     | Fn     | hold `MO(2)`       | F-keys, mouse keys, media, nav, brackets, RGB    |

## Files

- `keymap.c`: the keymap, generated from the Configurator-style JSON below.
- `keyboardio-model100-uhk.json`: source export. Edit this, then regenerate `keymap.c`
  with `qmk json2c`, or edit `keymap.c` directly and treat the JSON as stale.
- `config.h`: tapping, Chordal Hold, Flow Tap, mouse key and RGB timeout settings.

## Build and flash

```bash
qmk flash -kb keyboardio/model100 -km uhk
```

Hold **Prog** while plugging in if still on stock firmware; hold **Boot** if already on QMK.
