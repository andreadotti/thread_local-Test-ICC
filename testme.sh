

echo "Compiling: testme.cc for host, no problem"
icpc -std=c++11 -c testme.cc -o testme.o.host
echo "Compiling: main.cc for host, no problem"
icpc -std=c++11 -c main.cc -o main.o.host
echo "Creating application, no problem"
icpc -std=c++11 main.o.host testme.o.host -o testme.host

echo "Compiling: testme.cc for mic, warning emitted"
icpc -std=c++11 -mmic -c testme.cc -o testme.o.mic
echo "Compiling: main.cc for mic, no problem"
icpc -std=c++11 -mmic -c main.cc -o main.o.mic
echo "Creating application for mic, cannot link"
icpc -std=c++11 -mmic main.o.mic testme.o.mic -o testme.mic


