co(){g++ $1/$1.cpp -o $1/$1 --std=c++20 -Wall -Wshadow -Wextra}
run(){for f in `ls ./$1/*.txt`;do echo $f ;./$1/$1 < $f; done}
#Build, template.cpp must exist!
for x in {A..Z}; do mkdir $x; cp template.cpp $x/$x.cpp; touch $x/in.txt;done