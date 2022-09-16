set -e

read -p "Do compile? [y] :" YN
if [ $YN = "y" ]; then
    echo "now compiling..."
    /usr/bin/g++ -fdiagnostics-color=always ./src/cpp/RobotPainter.cpp -o ./src/cpp/RobotPainter -std=c++17 -Dhari64 -Wall -Wextra -O3
fi

export DISPLAY=:0.0
YELLOW="\033[33m"
RESET="\033[0m"
read -p "$(echo -e $YELLOW"seed: "$RESET)" seed
seed=$(( seed ? seed : 1 ))
java -jar tester.jar -exec ./src/cpp/RobotPainter -seed ${seed} -debug -delay 100
