bash count_limited.sh & pid1=$!
bash count_limited.sh & pid2=$!
bash count_limited.sh & pid3=$!

echo "Started 3 processes with PIDs: "
echo "Process 1: $pid1"
echo "Process 2: $pid2"
echo "Process 3: $pid3"
