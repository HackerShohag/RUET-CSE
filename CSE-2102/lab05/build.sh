# configure
mkdir -p build
cmake -S . -B build/

# compile
cd build
make

# run
./my_target

cd -