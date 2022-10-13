cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)


# set the project name
project(Client_App)

# add the executable
add_executable(Client_App ../src/main.cpp ../src/Client.cpp ../src/COMM_MEDIA.cpp ../src/Average.cpp ../src/Accumulation.cpp ../src/Socket.cpp ../src/ClientSocket.cpp ../src/DataBase.cpp ../src/sqlite3.c)

# link SQLite3 lib
find_package (SQLite3)
if (SQLITE3_FOUND)
  include_directories(${SQLITE3_INCLUDE_DIRS})
  target_link_libraries (Client_App ${SQLITE3_LIBRARIES})
endif (SQLITE3_FOUND)

# link pthread for sqlite
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(Client_App PRIVATE Threads::Threads  ${CMAKE_DL_LIBS})