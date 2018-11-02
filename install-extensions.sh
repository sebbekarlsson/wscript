mkdir tmp_extensions
cd tmp_extensions

wget https://github.com/sebbekarlsson/libwscriptrequests/archive/master.zip; wait;

unzip master.zip
cd libwscriptrequests-master
make; wait;
make install;

cd ..;
rm -rf tmp_extensions
echo "*** Done installing extensions ***"
