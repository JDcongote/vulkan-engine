#pragma once
#include "vulkan_headers.h"
#include <fstream>

static std::vector<char> readFile(const std::string& filename) {
	std::ifstream file(filename, std::ios::ate | std::ios::binary);
	if (!file.is_open()) {
		throw std::runtime_error("failed to open file!");
	}
	size_t fileSize = (size_t)file.tellg();
	std::vector<char> buffer(fileSize);

	//seek back to the begining and read all bytes at once;
	file.seekg(0);
	file.read(buffer.data(), fileSize);

	file.close();
	return buffer;
}
