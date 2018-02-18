#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {

  // Code copiedd from Udacity SDCND Lesson 5 lectures
  int sz = estimations.size();
  
  VectorXd rmse(4);
  rmse << 0, 0, 0, 0;

  if (estimations.size() != ground_truth.size() || estimations.size() == 0) {
    cout << "Invalid estimation or ground_truth data" << endl;
    return rmse;
  }

  if (499 == estimations.size()) {
    cout << "pxe, pye, re, rde, px, py, r, rd" << endl;
  }

  for(unsigned int i=0; i < estimations.size(); ++i){
    VectorXd residual = estimations[i] - ground_truth[i];
    residual = residual.array()*residual.array();
    rmse += residual;

    if (499 == estimations.size()) {
      cout << estimations[i][0] << "," << estimations[i][1] << "," << estimations[i][2] << "," << estimations[i][3] << ",";
      cout << ground_truth[i][0] << "," << ground_truth[i][1] << "," << ground_truth[i][2] << "," << ground_truth[i][3] << endl;
    }

  }

  rmse = rmse/estimations.size();

  rmse = rmse.array().sqrt();

  return rmse;

}
