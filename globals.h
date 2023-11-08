#pragma once
namespace global{
    const int height = 900;
    const int width = 700;
    const float scale = 2.f;
};

#define SAFE_DELETE(ptr) if (ptr != NULL){delete ptr; ptr = 0;}
