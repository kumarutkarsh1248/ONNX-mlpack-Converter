#include "BatchNormalization.hpp"

void AddBatchNormalization(mlpack::FFN<> &ffn, onnx::GraphProto graph,
                           onnx::NodeProto node, map<string, double> onnxOperatorAttribute, vector<arma::Mat<double>> &layerParameters)
{
    // experiment below 
    double eps = onnxOperatorAttribute["epsilon"];
    double momentum = onnxOperatorAttribute["momentum"];
    // mlpack follow width, height, channel and we want normalization only along channel 
    mlpack::BatchNorm* batchNorm = new mlpack::BatchNorm(2, 2, eps, false, momentum);

    // setting the trained parameters
    string scale_input = node.input(1); //gamma
    string B_input = node.input(2); // beta
    string mean_input = node.input(3);
    string var_input = node.input(4);


    batchNorm->TrainingMean() = get::ConvertToColumnMajor(get::Initializer(graph, mean_input));
    batchNorm->TrainingVariance() = get::ConvertToColumnMajor(get::Initializer(graph, var_input));
    // batchNorm->Parameters() = arma::join_cols(get::ConvertToColumnMajor(get::Initializer(graph, mean_input)), get::ConvertToColumnMajor(get::Initializer(graph, var_input)));
    layerParameters.push_back(arma::join_cols(get::ConvertToColumnMajor(get::Initializer(graph, scale_input)), get::ConvertToColumnMajor(get::Initializer(graph, B_input))));
    // experiment above
    ffn.Add(batchNorm);
    cout << "Added the BatchNormalization layer" << endl;
}
