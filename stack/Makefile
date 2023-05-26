
.PHONY: all
all: test-go test-c test-cpp test-python


.PHONY: test-python
test-python:
	@echo "Running Python tests... #######################\n"
	cd python && make test
	@echo "Python tests finished!"
	@echo "###############################################\n\n"

.PHONY: test-go
test-go:
	@echo "Running Go tests... #######################\n"
	cd go && make test
	@echo "Go tests finished!"
	@echo "###############################################\n\n"

.PHONY: test-c
test-c:
	@echo "Running C tests... #######################\n"
	cd c && make test
	@echo "C tests finished!"
	@echo "###############################################\n\n"

.PHONY: test-cpp
test-cpp:
	@echo "Running C++ tests... #######################\n"
	cd c++ && make test
	@echo "C++ tests finished!"
	@echo "###############################################\n\n"



