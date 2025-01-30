#pragma once

bool BGRToRGB(unsigned char *&data, const unsigned int dataLength);
bool BGRToBGRA(unsigned char *&data, const unsigned int dataLength);
bool LoadTGA(const char *filename, unsigned char *&data, unsigned short &width, unsigned short &height);
