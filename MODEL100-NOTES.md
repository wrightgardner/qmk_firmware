# Keyboardio Model 100 on QMK: how this fork works

QMK upstream doesn't support the Model 100 yet. Support comes from
[qmk/qmk_firmware#26397](https://github.com/qmk/qmk_firmware/pull/26397).
I copied that PR's code into this fork as a single snapshot commit and added my
own keymap, `uhk`, on top. All my branches live on **my fork (`origin`)**. The PR
author's fork (`shieldsd`, branch `keyboardio-model100-pr`) is read-only and is
only used to fetch updates to the PR.

## Layout

| Thing                      | Where it lives                                                      |
|----------------------------|---------------------------------------------------------------------|
| My fork                    | `origin` = wrightgardner/qmk_firmware (push here)                   |
| Real QMK                   | `upstream` = qmk/qmk_firmware (fetch only)                          |
| PR author's fork           | `shieldsd` (fetch only; refreshing the PR snapshot)                 |
| `master`                   | Local, mirrors `upstream/master`. Never commit here.                |
| `keyboardio-model100`      | Local: `master` + the PR #26397 snapshot commit                     |
| `keyboardio-model100-uhk`  | Pushed to `origin`: snapshot + my keymap. **The one I build.**      |

The PR only touches `keyboards/keyboardio/model100/`, so rebases are nearly
conflict-free. My keymap lives in `keyboards/keyboardio/model100/keymaps/uhk/`
(see its `readme.md`).

## Initial setup (new machine)

```bash
git clone https://github.com/wrightgardner/qmk_firmware ~/qmk_firmware_mine
cd ~/qmk_firmware_mine
git remote add upstream https://github.com/qmk/qmk_firmware
git remote add shieldsd https://github.com/shieldsd/qmk_firmware
git config remote.pushDefault origin
git switch keyboardio-model100-uhk
qmk setup -H ~/qmk_firmware_mine      # or: git submodule update --init --recursive
```

## Build and flash

```bash
qmk compile -kb keyboardio/model100 -km uhk
qmk flash   -kb keyboardio/model100 -km uhk
```

Bootloader mode:

- **Still on stock Keyboardio firmware:** hold the **Prog** key while plugging in USB.
- **Already on QMK:** hold the **Boot** key (`QK_BOOT` is on layers 0 and 2 of `uhk`).

## Updating QMK (routine)

```bash
git fetch upstream
git switch master && git merge --ff-only upstream/master
git rebase master keyboardio-model100-uhk
git branch -f keyboardio-model100 keyboardio-model100-uhk~N   # N = # of my keymap commits; skip if unsure
git submodule update --init --recursive
qmk compile -kb keyboardio/model100 -km uhk                   # verify before flashing
git push origin master                                        # when ready
git push --force-with-lease origin keyboardio-model100-uhk
```

If a rebase conflicts under `keyboards/keyboardio/model100/`, it's almost always
because the PR changed upstream. See the next section.

## Refreshing the PR snapshot (PR author pushed changes)

The PR commit here is a squash of the PR head, so `git merge` of the PR branch
won't work. Instead replace the snapshot commit:

```bash
git fetch shieldsd keyboardio-model100-pr
git switch -c tmp keyboardio-model100              # PR commit is the tip of this branch
git checkout FETCH_HEAD -- keyboards/keyboardio/model100
git commit --amend --no-edit
git rebase --onto tmp keyboardio-model100 keyboardio-model100-uhk   # move my keymap commits on top
git branch -f keyboardio-model100 tmp && git branch -D tmp
```

The snapshot matched PR head `2c745388` as of 2026-11-18.

## When the PR merges upstream

Check with `git ls-tree upstream/master keyboards/keyboardio/model100`. Once it's there:

```bash
git fetch upstream
git switch master && git merge --ff-only upstream/master
# drop the PR snapshot commit, keep only my keymap on top of real QMK
git rebase --onto master keyboardio-model100 keyboardio-model100-uhk
git branch -D keyboardio-model100
git remote remove shieldsd
```

Optional: move the keymap into a [QMK userspace](https://docs.qmk.fm/newbs_external_userspace)
repo and retire this fork entirely.

## Back to stock Kaleidoscope firmware

1. Go to <https://chrysalis.keyboard.io/>.
2. Reset the factory settings/firmware from there.
3. Clear the EEPROM.
