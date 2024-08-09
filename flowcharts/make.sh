#!/bin/bash
if ! [ $# -eq 1 ]; then
	echo -e "usage: $0 <presentation.md>\n\nmake sure media is in ./media!" | cowsay -n
	exit 1
fi

mdslides $1 --include media --output_dir out_$1 
firefox ./out_$1/index.html
