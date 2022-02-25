#include "AllClass.h"

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
    m_m << 1.0, 0.0, base_point[0], 0.0, 1.0,base_point[1], 0.0,0.0,1.0;

    Eigen::Vector3d calculate;
    calculate = r_m * m_m * point;
    calculate = m_m_1 * calculate;
    return calculate;
}


int main() {
    Eigen::Vector3d test_vector(1.0, 0.0, 1.0);
    smoeTool tool;
    cout << tool.Rotate(test_vector, Eigen::Vector3d(0.0, 0.0, 1.0), 90) << endl;
    return 0;
}
