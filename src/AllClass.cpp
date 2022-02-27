#include "AllClass.h"

void smart_ptr_test::addSum()
{
    int return_value = 0;
    for(auto it = this->arr.begin(); it != this->arr.end(); ++it)
    {
        return_value += *(*it).get();
        return_value += *(it->get());
    }
    cout << std::to_string(return_value)<<endl;
}

void smart_ptr_test::getData(const std::vector<int> & rhs)
{
    for(const auto & item : rhs)
    {
        std::unique_ptr<int> temp_ptr = std::make_unique<int>(item);
        this->arr.push_back(std::move(temp_ptr));
    }
}

void smoeTool::Rotate(Eigen::Vector3d& point, double angle)
{
    angle = angle/180.0*acos(-1);

    double cosine = cos(angle);
    double sine = sin(angle);

    Eigen::Matrix3d r_m;
    r_m << cosine, -sine, 0.0, sine, cosine,0.0, 0.0,0.0,1.0;

    Eigen::Matrix3d m_m;
    m_m << 1.0, 0.0, -point[0], 0.0, 1.0,-point[1], 0.0,0.0,1.0;

    Eigen::Vector3d calculate;
    calculate = r_m * point;
    point = calculate;
}

Eigen::Vector3d smoeTool::Rotate(const Eigen::Vector3d& point, const Eigen::Vector3d& base_point, double angle)
{
    angle = angle/180.0*acos(-1);

    double cosine = cos(angle);
    double sine = sin(angle);

    Eigen::Matrix3d r_m;
    r_m << cosine, -sine, 0.0, sine, cosine,0.0, 0.0,0.0,1.0;

    Eigen::Matrix3d m_m;
    m_m << 1.0, 0.0, -base_point[0], 0.0, 1.0,-base_point[1], 0.0,0.0,1.0;
    Eigen::Matrix3d m_m_1;
    m_m_1 << 1.0, 0.0, base_point[0], 0.0, 1.0,base_point[1], 0.0,0.0,1.0;

    Eigen::Vector3d calculate;
    calculate = r_m * m_m * point;
    calculate = m_m_1 * calculate;
    return calculate;
}
