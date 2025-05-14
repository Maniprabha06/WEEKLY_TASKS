echo "Loop starts"

bash -c 'while true; do echo "Process 1"; sleep 1; done' &
bash -c 'while true; do echo "Process 2"; sleep 2; done' &
bash -c 'while true; do echo "Process 3"; sleep 3; done' &

echo "Started 3 background processes"

