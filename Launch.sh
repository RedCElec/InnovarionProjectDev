#!/bin/bash

# Launch C++ program
cd ~/Desktop/innov/InnovarionProjectDev/src/
make
./tester_notBuild &

cpp_program_pid=$!

# Launch web server
cd ~/Desktop/innov/InnovarionProjectDev/webserver/
npm run dev > ~/Desktop/innov/InnovarionProjectDev/webserver/log.txt 2>&1 &

echo "Web server launched. Press Ctrl+C to stop."
trap "kill $cpp_program_pid" INT
tail -f ~/Desktop/innov/InnovarionProjectDev/webserver/log.txt
