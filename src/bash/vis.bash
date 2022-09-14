export DISPLAY=:0.0
YELLOW="\033[33m"
RESET="\033[0m"
read -p "$(echo -e $YELLOW"seed: "$RESET)" seed
seed=$(( seed ? seed : 1 ))
java -jar tester.jar -exec ./src/cpp/RobotPainter -seed ${seed}
