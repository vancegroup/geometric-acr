#!/bin/sh

# Pass the build directory (cmake binary dir) as the command line argument.

(
for testapp in $1/timing/perform_condition_*_timing; do
    $testapp
done
) #| tee rawlog.txt | sort | uniq |tee processedlog.txt
