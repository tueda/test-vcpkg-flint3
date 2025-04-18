# test-vcpkg-flint3

```bash
sudo apt-get update
sudo DEBIAN_FRONTEND=noninteractive apt-get install --no-install-recommends -y automake ca-certificates cmake curl git g++ libtool make pkg-config unzip zip

git clone https://github.com/tueda/test-vcpkg-flint3.git
cd test-vcpkg-flint3

git clone https://github.com/microsoft/vcpkg.git
./vcpkg/bootstrap-vcpkg.sh

cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=$(pwd)/vcpkg/scripts/buildsystems/vcpkg.cmake -DCMAKE_BUILD_TYPE=Debug
cmake --build build
cmake --install build --prefix /path/to/install
```
