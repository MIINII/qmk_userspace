#!/bin/zsh
# This script merges unicorne userspace keyboard files into
# corresponding qmk folder so can include customizatons in
# qmk_userspae forked repo. This is neccessary because qmk_userspace
# is primarily intended for just keyboard layout mods. and does not
# support building custom keyboard firmware. Thus script assumes
# author's layout and script is build/used in macOS -- for anybody
# else who might use, modify as needed.
echo Building unicorne firmware...
# QMK user space does not support building custom keyboard modules
# from userspace, so copy modules to overlay or add from userspace
# repo to qmk folder. This script assumes qmk_userspace fork is a
# sibling of qmk repo.
KM=rolanday
QMK_UNICORNE_ROOT=../qmk/keyboards/boardsource/unicorne/
test ! -d $QMK_UNICORNE_ROOT && echo "Error: qmk unicorne folder not found" && exit 1
QMK_USERSPACE_UNICORNE_ROOT=./keyboards/boardsource/unicorne/
test ! -d $QMK_USERSPACE_UNICORNE_ROOT && echo "Error: qmk_userspace unicorne folder not found" && exit 1

# list of files to overlay and/or copy
FILES=(info.json unicorne.h unicorne.c)

# FILES=(unicorne.c)
# first pass: ensure all userspace files to copy exist before copying any.
for i in "${FILES[@]}"
do
  src=$QMK_USERSPACE_UNICORNE_ROOT$i
  test ! -e $src && echo "No such userspace file: $src" && exit 1
done

# second pass: copy any changed files.
for i in "${FILES[@]}"
do
  src=$QMK_USERSPACE_UNICORNE_ROOT$i
  tgt=$QMK_UNICORNE_ROOT$i
  # copy changed files so qmk performs full rebuild only as needed,
  md5src=$(md5 -q "$src")
  md5tgt=$(md5 -q "$tgt")
  if [ "$md5tgt" != "$md5src" ]
  then
    echo $src changed
    cp $src $tgt
  fi
done

# build the firmware
qmk compile -kb boardsource/unicorne -km "$KM"
