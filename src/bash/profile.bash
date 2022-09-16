# gprof ./a.out gmon.out

echo "now compiling..."
/usr/bin/g++ -pg -g -fdiagnostics-color=always ./src/cpp/RobotPainter.cpp -o ./src/cpp/RobotPainter -std=c++17 -Wall -Wextra -O3
echo "now running..."
./src/cpp/RobotPainter < input/2.in
gprof ./src/cpp/RobotPainter gmon.out # -A
rm gmon.out