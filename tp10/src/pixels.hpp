#pragma once

struct RGBA {
    uint8_t red, green, blue, alpha;
};

struct RGB {
    uint8_t red, green, blue;
};

struct Luma {
    uint8_t gray;
};

template <typename To, typename From>
To convert(const From& stuff);

template <>
RGBA convert(const RGBA& value) {
    return value;
}

template <>
RGB convert(const RGB& value) {
    return value;
}

template <>
Luma convert(const Luma& value) {
    return value;
}

template <>
RGB convert(const RGBA& value) {
    return {value.red, value.green, value.blue};
}

template <>
RGBA convert(const RGB& value) {
    return {value.red, value.green, value.blue, 255};
}

template<>
Luma convert(const RGB& value) {
    return {image_lib::rgb_to_grayscale(value.red, value.green, value.blue)};
}

template<>
RGB convert(const Luma& value) {
    return {image_lib::grayscale_to_rgb(value.gray)};
}

template<>
Luma convert(const RGBA& value) {
    return convert<RGBA, RGB>(convert<RGB, Luma>(value));
}

template<>
RGBA convert(const Luma& value) {
    return convert<RGB, RGBA>(convert<Luma, RGB>(value));
}

RGBA operator+(const RGBA& lhs, const RGBA& rhs) {
    return image_lib::mix_color(lhs.red, lhs.green, lhs.blue, lhs.alpha, rhs.red, rhs.green, rhs.blue, rhs.alpha);
}

RGB operator+(const RGB& lhs, const RGBA& rhs) {
    return convert<RGB>(lhs + rhs);
}

RGB operator+(const Luma& lhs, const RGBA& rhs) {
    return convert<RGB>(lhs + rhs);
}

RGBA operator+(const RGBA& lhs, const RGB& rhs) {
    return convert<RGBA>(lhs + rhs);
}

RGB operator+(const RGB& lhs, const RGB& rhs) {
    return convert<RGB>(lhs + rhs);
}

RGB operator+(const Luma& lhs, const RGB& rhs) {
    return convert<RGB>(lhs + rhs);
}

