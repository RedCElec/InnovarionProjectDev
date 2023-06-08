#!/bin/bash

# Launch C++ program
cd ~/Desktop/innov/src/
make
./tester_notBuild &

# Launch web server
cd ~/Desktop/innov/webserver/
npm run dev > ~/Desktop/innov/webserver/logfile.txt 2>&1 &

echo "Web server launched. Press Ctrl+C to stop."

tail -f ~/Desktop/innov/webserver/logfile.txt
