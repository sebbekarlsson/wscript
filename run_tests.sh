virtualenv -p /usr/bin/python2.7 ./venv; wait
source ./venv/bin/activate
pip install pytest

make test
./test.out

py.test unit/output_tests
