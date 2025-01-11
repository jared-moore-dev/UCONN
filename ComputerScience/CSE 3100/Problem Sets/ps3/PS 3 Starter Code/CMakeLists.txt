cmake_minimum_required(VERSION 3.20)
project(untitled1 C)

set(CMAKE_C_STANDARD 99)

add_executable(list list.c list.h listTest.c)
add_executable(LStack LStack.c LStack.h LStackTest.c list.c)
add_executable(vector vector.c vector.h vectorTest.c)
add_executable(VStack VStackTest.c vector.c VStack.c VStack.h)
add_executable(QTest list.c list.h LStack.c LStack.h queue.h queue.c QTest.c)
add_executable(mimir mimirlist.c list.c list.h)
