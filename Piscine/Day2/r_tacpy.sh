#!/bin/sh

cut -d':' -f 6 | cut -d'/' -f 4 | sort -r | rev
