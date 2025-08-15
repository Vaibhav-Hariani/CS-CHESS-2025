#!/bin/bash
HELP=$(
cat << EOF
	usage: $0 <presentation dir>\n\n
	include optional media in\n
	./<presentation dir>/media!
EOF
)

if ! [ -d $1 ]; then
	echo -e "Please enter a directory that exists!"
	exit 1
fi

if ! [ $# -eq 1 ]; then
	cowsay_avail=
	if type -a cowsay&>/dev/null; then
		echo -e $HELP | cowsay -n
	else
		echo -e $HELP
	fi
	exit 1
fi

if [ ${1: -1} = '/'  ]; then
	echo $1 | head -c-2 | set -- - # clears rest of args
fi

ARGS=--output_dir\ ./$1_out/
if [[ -d ./$1/media ]]; then
	ARGS=$ARGS\ --include\ ./$1/media
fi

mdslides ./$1/$1.md $ARGS
