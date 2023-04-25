path=`pwd`
gcc -shared -fPIC -o libsm4.so ./src/cypto/sm4.h ./src/cypto/sm4.c -I$path/include -L/$path/lib64 -lcrypto -Wl,-rpath=$path/lib64