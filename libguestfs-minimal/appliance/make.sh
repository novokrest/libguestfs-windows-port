#!/bin/bash -
# appliance/make.sh-t.  Generated from make.sh.in by configure.
# Copyright (C) 2009-2014 Red Hat Inc.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

unset CDPATH

set -e

# Run supermin.

if [ "xno" != "xno" ]; then
    extra="--packager-config no"
fi
if [ "xno" != "xno" ]; then
    extra="$extra no"
fi

echo /usr/local/bin/supermin --prepare -v -o supermin.d $(< packagelist ) $extra
/usr/local/bin/supermin --prepare -v -o supermin.d $(< packagelist ) $extra
