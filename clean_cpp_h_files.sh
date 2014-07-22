#!/bin/sh
mydir=$(cd $(dirname $0) && pwd)
astyle -n --options=$(dirname $0)/astylerc --recursive \
   "$mydir/boundary_features/*.cpp" \
   "$mydir/boundary_features/*.h" \
   "$mydir/timing/*.cpp" \
   "$mydir/timing/*.h" \
   "$mydir/tests/*.cpp" \
   "$mydir/tests/*.h"
