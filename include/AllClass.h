#ifndef GENERALTEST_ALLCLASS_H
#define GENERALTEST_ALLCLASS_H

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include "Core"
#include "Dense"

using std::cout;
using std::endl;

class smart_ptr_test
{
public:
    void getData(const std::vector<int>&);

    void addSum();

private:

    std::vector<std::unique_ptr<int>> arr;

};

class smoeTool
{
public:
    static void Rotate(Eigen::Vector3d& point, double angle);
    static Eigen::Vector3d Rotate(const Eigen::Vector3d& point, const Eigen::Vector3d& base_point, double angle);
};

#endif //GENERALTEST_ALLCLASS_H
