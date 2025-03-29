MODULE_NAME := $(shell go list -m)

# Consider the location of Makefile as the root project directory
PROJECT_ROOT := $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))
PROJECT_NAME := $(shell basename $(PROJECT_ROOT))

# Build directories
TARGET_DIR := build

# Go
GO := go
GOVERSION := $(shell go env GOVERSION)
GOOS := $(shell go env GOOS)
GOARCH := $(shell go env GOARCH)

.PHONY: env
env:
	@echo "PROJECT_ROOT: $(PROJECT_ROOT)"
	@echo "PROJECT_NAME: $(PROJECT_NAME)"
	@echo "GO: $(GO)"
	@echo "GOVERSION: $(GOVERSION)"
	@echo "GOOS: $(GOOS)"
	@echo "GOARCH: $(GOARCH)"

.PHONY: init
init:
	${GO} mod download

.PHONY: all
all: $(TARGET_DIR)/darwin-arm64/libhello.a $(TARGET_DIR)/darwin-arm64/hello.h

.PHONY: clean
clean:
	rm -rf $(TARGET_DIR)

$(TARGET_DIR)/darwin-arm64/libhello.a:
	CGO_ENABLED=1 \
	GOOS=darwin \
	GOARCH=arm64 \
	$(GO) build \
	-buildmode=c-archive \
	-ldflags="-s -w" \
	-o $@ \
	$(PROJECT_ROOT)/cmd/hello

$(TARGET_DIR)/darwin-arm64/hello.h: $(TARGET_DIR)/darwin-arm64/libhello.a
	mv $(TARGET_DIR)/darwin-arm64/libhello.h $@
