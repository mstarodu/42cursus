#!/bin/bash

PUSH_SWAP="./push_swap"

# 5
# Use Python to generate all permutations of numbers 1 through 5
PERMUTATIONS=$(python3 -c "from itertools import permutations; print('\n'.join([' '.join(map(str, p)) for p in permutations(range(1, 6))]))")

echo "Testing all permutations of 5 args"
max_operations_of_five=0 # Initialize the maximum number of operations

# Read each permutation line by line
while IFS= read -r ARGS; do
    # Pass the permutation to your program and count the output lines
    RESULT=$($PUSH_SWAP $ARGS | wc -l)
    echo "Args: $ARGS Number of operations: $RESULT"
    # Update max_operations if the current result is greater
    if (( RESULT > max_operations_of_five )); then
        max_operations_of_five=$RESULT
    fi
done <<< "$PERMUTATIONS"


# 6
# Use Python to generate all permutations of numbers 1 through 6
PERMUTATIONS=$(python3 -c "from itertools import permutations; print('\n'.join([' '.join(map(str, p)) for p in permutations(range(1, 7))]))")

echo "Testing all permutations of 6 args"
max_operations_of_six=0 # Initialize the maximum number of operations

# Read each permutation line by line
while IFS= read -r ARGS; do
    # Pass the permutation to your program and count the output lines
    RESULT=$($PUSH_SWAP $ARGS | wc -l)
    echo "Args: $ARGS Number of operations: $RESULT"
    # Update max_operations if the current result is greater
    if (( RESULT > max_operations_of_six )); then
        max_operations_of_six=$RESULT
    fi
done <<< "$PERMUTATIONS"

echo "Maximum number of operations for 5 args: $max_operations_of_five"
echo "Maximum number of operations for 6 args: $max_operations_of_six"
