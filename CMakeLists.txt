cmake_minimum_required(VERSION 3.20)
project(MyFinance)

set(CMAKE_CXX_STANDARD 17)

add_executable(MyFinance main.cpp lib/TypeOperation.h lib/Category.h lib/Date.h lib/Operation.h lib/CategoryDirectory.h lib/Wallet.h lib/User.h)
