set shell := ["fish", "-c"]
set positional-arguments

# kb := "splitkb/kyria/rev3"
kb := "splitkb/halcyon/kyria"
rev := "rev4"
km := "indianboy42"
# km := "indianboy42_vial"
args := "-e HLC_CIRQUE_TRACKPAD=1"

qmk := "qmk"

export LDFLAGS := ""
# qmk := "./bin/qmk"
# qmk := "just nix"

# First/Default command:
# Compile a keyboard
flash:
    {{qmk}} flash -kb {{kb}}/{{rev}} -km {{km}} {{args}}


# Run arbitrary make command
make *arguments:
    make {{arguments}}

# Check qmk installation
doctor:
    {{qmk}} doctor

# Compile a keyboard
compile:
    {{qmk}} compile -kb {{kb}}/{{rev}} -km {{km}}  {{args}}

edit:
    $EDITOR {{justfile_directory()}}/keyboards/{{kb}}/keymaps/{{km}}/keymap.c

upstream:
    #!/usr/bin/env bash
    HASH=$(git rev-parse master)
    git branch master-$HASH $HASH
    git checkout master
    git rebase upstream/master

db: compile_commands
compile_commands:
    qmk generate-compilation-database -kb {{kb}}/{{rev}} -km {{km}}
    cp ~/qmk_firmware/compile_commands.json .

save-config:
    qmk config user.keyboard={{kb}}/{{rev}}
    qmk config user.keymap={{km}}
