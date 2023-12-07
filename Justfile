scaffold day:
  mkdir day{{ day }}
  touch day{{ day }}/input.txt
  cp template/main.cpp day{{ day }}/main.cpp
  cp template/test.cpp day{{ day }}/test.cpp
  echo "add_day({{ day }})" >> CMakeLists.txt