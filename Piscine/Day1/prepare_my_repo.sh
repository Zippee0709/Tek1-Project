#!/bin/sh
blih -u zhiwen.wang@epitech.eu repository create $1
blih -u zhiwen.wang@epitech.eu repository setacl $1 ramassage-tek r
blih -u zhiwen.wang@epitech.eu repository getacl $1
