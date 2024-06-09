#ifndef RELU_HPP
#define RELU_HPP

#include "mlpack.hpp"
#include "onnx_pb.h"

using namespace std;

void AddRelu(mlpack::FFN<> &ffn);


#include "Relu_impl.hpp"
#endif