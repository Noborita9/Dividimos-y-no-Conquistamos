co(){
    g++ $1.cpp -o $1 --std=c++20 -Wall -Wshadow -Wextra
}
run(){
    ./$1 < in.txt
}