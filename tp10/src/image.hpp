#pragma once

#include <iostream>
#include <array>
#include <functional>

template <typename P, size_t W, size_t H>
class Image {
    public:
        Image() = default;

        Image(const P& pixel) {
            for (const auto& row : _pixels) {
                row.fill(pixel);
            }
        }

        Image(const std::function<P(size_t i, size_t j)>& fct) {
            for (int i = 0; i < W; i++) {
                for (int j = 0; j < H; j++) {
                    _pixels[j][i] = fct(i, j);
                }
            }
        }

        P img(size_t i, size_t j) {
            return _pixels.at(i, j);
        }

        const P& operator()(size_t i, size_t j) const {
            return _pixels[j][i]; // _pixels.at(j).at(i)
        }

        P& operator()(size_t i, size_t j) {
            return _pixels[j][i];
        }

        template <size_t W2, size_t H2>
        Image operator+(const Image& otherImage) {
            Image resultImage;
            for (int i = 0; i < W2; i++) {
                for (int j = 0; j < H2; j++) {
                    resultImage(j, i) = (*this)(j, i) + otherImage(j, i);
                }
            }
            return resultImage;
        }

    private:
        std::array<std::array<P, W>, H> _pixels;
};