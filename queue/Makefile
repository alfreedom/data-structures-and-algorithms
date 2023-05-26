
.PHONY: all
all: test-go test-c test-cpp test-python


.PHONY: test-python
test-python:
	@echo "###############################################"
	@echo "Running Python tests...\n"
	@cd python && make test
	@echo "\nPython tests finished!"
	@echo "###############################################\n\n"

.PHONY: test-go
test-go:
	@echo "###############################################"
	@echo "Running Go tests...\n"
	@cd go && make test
	@echo "\nGo tests finished!"
	@echo "###############################################\n\n"

.PHONY: test-c
test-c:
	@echo "###############################################"
	@echo "Running C tests...\n"
	@cd c && make test
	@echo "\nC tests finished!"
	@echo "###############################################\n\n"

.PHONY: test-cpp
test-cpp:
	@echo "###############################################"
	@echo "Running C++ tests...\n"
	@cd c++ && make test
	@echo "\nC++ tests finished!"
	@echo "###############################################\n\n"



