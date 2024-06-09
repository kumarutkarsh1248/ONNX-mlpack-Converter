#ifndef MAXPOOL_HPP
#define MAXPOOL_HPP

#include "mlpack.hpp"
#include "onnx_pb.h"

using namespace std;

void AddMaxPool(mlpack::FFN<> &ffn);


#include "MaxPool_impl.hpp"
#endif