#!/bin/sed -E

/.*class="titlelink".*/!d
s/^.*class="title"//
s/><a href="//g
s/" class="titlelink">/¤/g
s/<\/a.*//g
s/" class="titlelink" rel="nofollow">/¤/g
s/\(.*\)¤\(.*\)/**\2**\n\1\n/p
