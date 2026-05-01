#!/bin/bash

# Compile the exact file you are going to submit
gcc 34474676.c -o submission_test

# Check if compilation failed
if [ $? -ne 0 ]; then
    echo "Compilation failed! Check your C code for syntax errors."
    exit 1
fi

echo "Compilation successful. Running automated tests..."

# Define a function to run tests and compare output
run_test() {
    local test_name="$1"
    local input="$2"
    local expected="$3"

    echo "--------------------------------------------------"
    echo "Test: $test_name"
    
    # Run the executable, feed input, and grab only the very last line of output
    local actual=$(echo "$input" | ./submission_test | tail -n 1)

    # Compare the actual output to the expected string
    if [ "$actual" == "$expected" ]; then
        echo "Result: PASS"
    else
        echo "Result: FAIL"
        echo "Expected : $expected"
        echo "Actual   : $actual"
    fi
}

# Execute the test cases
run_test "Assignment Example" "10 2 3 1 17 25 7 8 35 -99" "10->17->25->35->NULL"
run_test "Already Ascending" "1 5 10 20 -99" "1->5->10->20->NULL"
run_test "Descending / All Smaller" "50 40 30 20 10 -99" "50->NULL"

echo "--------------------------------------------------"
# Clean up
rm submission_test