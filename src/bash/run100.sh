set -e

echo "now compiling..."
/usr/bin/g++ -fdiagnostics-color=always ./src/cpp/RobotPainter.cpp -o ./src/cpp/RobotPainter -std=c++17 -Wall -Wextra -O3

export DISPLAY=:0.0
java -jar tester.jar -exec ./src/cpp/RobotPainter -seed 1,100 -bs ./src/bash/best -so ./output -novis
