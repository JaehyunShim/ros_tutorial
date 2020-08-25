#!/bin/bash

BASEDIR=$(dirname $(realpath "$0"))
echo "$BASEDIR"
cd $BASEDIR
xdg-open talker.html