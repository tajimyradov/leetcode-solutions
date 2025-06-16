CXX = g++
CXXFLAGS = -std=c++17 -Wall
BUILD_DIR = build

.PHONY: clean run

run-cpp/%:
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/$* $*/main.cpp
	./$(BUILD_DIR)/$*

run-go/%:
	@mkdir -p $(BUILD_DIR)
	go build -o $(BUILD_DIR)/$* $*/main.go
	./$(BUILD_DIR)/$*

clean:
	rm -rf $(BUILD_DIR)
	find . -type f \( -name '*.out' -o -name 'main.exe' \) -delete
