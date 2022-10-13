# Client_App
Client App using c++ to recieve data from sensor

object: to gather data about the temperature from the sensory node. 

before compile you will need:
1- install tcpClient program to act as node.
2- install cmake , Build-essentials 
3- install pthreads dev lib 
4- install sqlite3 lib

to compile:
mkdir build/
cd build/
cmake ..
make

to run:
1- run tcpclient program as server for ip , port
2- run ./Client_App ip port
