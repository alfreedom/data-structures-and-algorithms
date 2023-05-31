
.PHONY: test
test:
	@go test -v -covermode=count -coverprofile .coverage .
	@go tool cover -func=.coverage