#!/bin/bash

# Define the values of n to test
N_VALUES=(3 5 100 500)

# Define the t values for each n
declare -A T_VALUES
T_VALUES[3]=2
T_VALUES[5]=12
T_VALUES[100]=700
T_VALUES[500]=5500

# Loop over each n value
for N in ${N_VALUES[@]}; do
    if [[ $N -eq 100 ]]; then
        X=2500
    elif [[ $N -eq 500 ]]; then
        X=4000
    else
        X=$((2**$N))
    fi

    # Calculate the total number of lines and the number of times push_swap output more than t lines
    TOTAL_LINES=0
    MORE_THAN_T=0
    for ((i=1; i<=$X; i++)); do
        # Generate random integers and pass them as arguments to push_swap
        NUMBERS=$(gshuf -i 0-1000 -n $N | tr '\n' ' ')
        LINES=$("./push_swap" $NUMBERS | wc -l)
        TOTAL_LINES=$((TOTAL_LINES + LINES))
        
        # Check if the number of lines is more than t
        if [[ $LINES -gt ${T_VALUES[$N]} ]]; then
            MORE_THAN_T=$((MORE_THAN_T + 1))
        fi
    done

    # Calculate the average number of lines
    AVERAGE_LINES=$((TOTAL_LINES / X))

    # Print the results
    echo "Number of int = $N | Number of time tested = $X | Average move needed = $AVERAGE_LINES | Threshold = ${T_VALUES[$N]} | Number of time higher than treashold = $MORE_THAN_T"
done

