
# number of recognizers
set(BF_NUM_BITS 6)

# so 2^6 possibilities
math(EXPR MAX_ITER "2^${BF_NUM_BITS}")

add_definitions(-DBF_NUM_BITS=${BF_NUM_BITS})
