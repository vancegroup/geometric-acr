#!/bin/sh

(
for testapp in $1/perform_condition_*_timing; do
    $testapp
done
) #| tee rawlog.txt | sort | uniq |tee processedlog.txt
