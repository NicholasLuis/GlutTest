current_directory="$(cd "$(dirname "$0")" && pwd)"
project_root_dir=$current_directory

cd ${project_root_dir}
rm -rf build
mkdir -p build && cd build
cmake ..
cmake --build .