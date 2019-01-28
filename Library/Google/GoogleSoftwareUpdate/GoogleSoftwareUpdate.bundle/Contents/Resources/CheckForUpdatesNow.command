#!/bin/bash
#
# CheckForUpdatesNow.command
# Google Software Update
#

# Determine directory where this script is running from
script_dir=$(dirname $(echo $0 | sed -e "s,^\([^/]\),$(pwd)/\1,"))

agent="$script_dir"/GoogleSoftwareUpdateAgent.app/Contents/MacOS/GoogleSoftwareUpdateAgent

if [ ! -x "$agent" ]; then
    echo "Can't figure out how to update now."
    exit 1
fi

"$agent" -runMode oneshot -userInitiated YES "$@"
