#include "rasterizer.hpp"
#include <opencv2/opencv.hpp>

Matrix4f get_view_matrix(const Vector3f& eye_pos)
{
    Matrix4f view = Matrix4f::Identity();

    Matrix4f translate;

    translate << 1, 0, 0, -eye_pos[0], 0, 1, 0, -eye_pos[1], 0, 0, 1,
            -eye_pos[2], 0, 0, 0, 1;

    view = translate * view;

    return view;

}

Eigen::Matrix4f get_model_matrix(float rotation_angle)
{
    Eigen::Matrix4f model = Eigen::Matrix4f::Identity();

    // TODO: Implement this function
    // Create the model matrix for rotating the triangle around the Z axis.
    // Then return it.

    rotation_angle = rotation_angle/180.0*acos(-1);

    float cosine = cos(rotation_angle);
    float sine = sin(rotation_angle);

    model<<cosine, sine, 0.0f, 0.0f,
            -sine, cosine, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f;


    return model;
}

Eigen::Matrix4f get_projection_matrix(float eye_fov, float aspect_ratio,
                                      float zNear, float zFar)
{
    // Students will implement this function
    Eigen::Matrix4f projection = Eigen::Matrix4f::Identity();
    float rotation_angle = eye_fov/180.0*acos(-1);
    // TODO: Implement this function
    // Create the projection matrix for the given parameters.
    // Then return it.

    float n_abs = fabs(zNear);
    float top = n_abs * tan(rotation_angle / 2.0f);
    float buttom = -top;
    float right = top *  aspect_ratio;
    float left = -right;

    projection<<2*zNear/(right - left),0.0f,(left + right) / (left - right), 0.0f,
                0.0f, 2*zNear/(top - buttom), (buttom + top) / (buttom - top), 0.0f,
                0.0f, 0.0f, (zFar + zNear) / (zNear - zFar), 2*zFar*zNear / (zFar - zNear),
                0.0f, 0.0f, 1.0f, 0.0f;


    return projection;
}

int main(int argc, const char** argv)
{
    float angle = 0;
    bool command_line = false;
    std::string filename = "output.png";

    if (argc >= 3) {
        command_line = true;
        angle = std::stof(argv[2]); // -r by default
        if (argc == 4) {
            filename = std::string(argv[3]);
        }
        else
            return 0;
    }

    rst::rasterizer r(700, 700);

    Eigen::Vector3f eye_pos = {0, 0, 5};

    std::vector<Eigen::Vector3f> pos{{2, 0, -2}, {0, 2, -2}, {-2, 0, -2}};

    std::vector<Eigen::Vector3i> ind{{0, 1, 2}};

    auto pos_id = r.load_positions(pos);
    auto ind_id = r.load_indices(ind);

    int key = 0;
    int frame_count = 0;

    if (command_line) {
        r.clear(rst::Buffers::Color | rst::Buffers::Depth);

        r.set_model(get_model_matrix(angle));
        r.set_view(get_view_matrix(eye_pos));
        r.set_projection(get_projection_matrix(45, 1, 0.1, 50));

        r.draw(pos_id, ind_id, rst::Primitive::Triangle);
        cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
        image.convertTo(image, CV_8UC3, 1.0f);

        cv::imwrite(filename, image);

        return 0;
    }

    while (key != 27) {
        r.clear(rst::Buffers::Color | rst::Buffers::Depth);

        r.set_model(get_model_matrix(angle));
        r.set_view(get_view_matrix(eye_pos));
        r.set_projection(get_projection_matrix(45, 1, 0.1, 50));

        r.draw(pos_id, ind_id, rst::Primitive::Triangle);

        cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
        image.convertTo(image, CV_8UC3, 1.0f);
        cv::imshow("image", image);
        key = cv::waitKey(10);

        std::cout << "frame count: " << frame_count++ << '\n';

        if (key == 'a') {
            angle += 10;
        }
        else if (key == 'd') {
            angle -= 10;
        }
    }

    return 0;
}
