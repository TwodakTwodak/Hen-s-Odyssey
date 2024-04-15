/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Matrix.h
Project:    CS230 Engine
Author:     Jonathan Holmes, Jiyun Seok
Created:    March 8, 2023
*/
#include "Matrix.h"
#include "cmath"

Math::TransformationMatrix::TransformationMatrix() {
    Reset();
}


void Math::TransformationMatrix::Reset() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }
}



Math::TransformationMatrix Math::TransformationMatrix::operator * (TransformationMatrix m) const {
    TransformationMatrix result;

    result.matrix[0][0] = matrix[0][0] * m[0][0] + matrix[0][1] * m[1][0] + matrix[0][2] * m[2][0];
    result.matrix[0][1] = matrix[0][0] * m[0][1] + matrix[0][1] * m[1][1] + matrix[0][2] * m[2][1];
    result.matrix[0][2] = matrix[0][0] * m[0][2] + matrix[0][1] * m[1][2] + matrix[0][2] * m[2][2];
    result.matrix[1][0] = matrix[1][0] * m[0][0] + matrix[1][1] * m[1][0] + matrix[1][2] * m[2][0];
    result.matrix[1][1] = matrix[1][0] * m[0][1] + matrix[1][1] * m[1][1] + matrix[1][2] * m[2][1];
    result.matrix[1][2] = matrix[1][0] * m[0][2] + matrix[1][1] * m[1][2] + matrix[1][2] * m[2][2];
    result.matrix[2][0] = matrix[2][0] * m[0][0] + matrix[2][1] * m[1][0] + matrix[2][2] * m[2][0];
    result.matrix[2][1] = matrix[2][0] * m[0][1] + matrix[2][1] * m[1][1] + matrix[2][2] * m[2][1];
    result.matrix[2][2] = matrix[2][0] * m[0][2] + matrix[2][1] * m[1][2] + matrix[2][2] * m[2][2];

    return result;
}

Math::TransformationMatrix& Math::TransformationMatrix::operator *= (Math::TransformationMatrix m) {
    (*this) = (*this) * m;
    return (*this);
}

Math::vec2 Math::TransformationMatrix::operator * (vec2 v) const {
    Math::vec2 result;
    result.x = matrix[0][0] * v.x + matrix[0][1] * v.y + matrix[0][2];
    result.y = matrix[1][0] * v.x + matrix[1][1] * v.y + matrix[1][2];
    return result;
}

Math::TranslationMatrix::TranslationMatrix(const Math::vec2& translation) {

    matrix[0][2] = translation.x;
    matrix[1][2] = translation.y;
}

Math::TranslationMatrix::TranslationMatrix(const Math::ivec2& translation) {
    matrix[0][2] = static_cast<double>(translation.x);
    matrix[1][2] = static_cast<double>(translation.y);
}
Math::ScaleMatrix::ScaleMatrix(double scale) {
    matrix[0][0] = scale;
    matrix[1][1] = scale;
}

Math::ScaleMatrix::ScaleMatrix(vec2 scale) {
    matrix[0][0] = scale.x;
    matrix[1][1] = scale.y;
}

Math::RotationMatrix::RotationMatrix(double theta) {
    double cosTheta = cos(theta);
    double sinTheta = sin(theta);

    matrix[0][0] = cosTheta;
    matrix[0][1] = -sinTheta;
    matrix[1][0] = sinTheta;
    matrix[1][1] = cosTheta;
}