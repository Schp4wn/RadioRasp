all:
	g++ radiorasp.cpp -o radiorasp -lwiringPi

install:
	sudo ln -s $(PWD)/radiorasp /usr/local/bin/radiorasp

uninstall:
	sudo rm radiorasp && sudo rm /usr/local/bin/radiorasp
