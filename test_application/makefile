all:
	sudo cp ./*.css /var/www/html/
	sudo cp -r ./media /var/www/html/
	sudo g++ ./main.cpp ../src/*.cpp -o /var/www/cgi-bin/main.cgi
	sudo g++ ./user_input_test.cpp ../src/*.cpp -o /var/www/cgi-bin/user_input_test.cgi
	sudo chown -R apache:apache /var/www/cgi-bin