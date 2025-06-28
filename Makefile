install:
	mkdir --parents build && \
	cd build && \
	cmake -DCMAKE_INSTALL_PREFIX=/usr/local .. && \
	make && \
	sudo make install

test: build-tests run-tests

build-tests:
	mkdir --parents tests/build && \
	cd tests/build && \
	cmake .. && \
	make

run-tests:
	cd tests/build && \
	./logger_tests
