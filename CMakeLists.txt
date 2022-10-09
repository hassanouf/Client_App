cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)


# set the project name
project(Client_App)

# add the executable
add_executable(Client_App ../src/main.cpp ../src/Client.cpp ../src/COMM_MEDIA.cpp ../src/Average.cpp ../src/Accumulation.cpp ../src/Socket.cpp ../src/ClientSocket.cpp)