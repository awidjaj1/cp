CXX = g++
CXXFLAGS = -std=c++20 -O2

%:
	@$(CXX) $(CXXFLAGS) $(firstword $(wildcard problemSet/*/$@*.cpp)) -o temp
	@./temp < input.txt
	@rm -f temp