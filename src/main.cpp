#include "polyscope/polyscope.h"
#include <fstream>
#include "polyscope/point_cloud.h"
#include "nanoflann.hpp"


std::vector<glm::vec3> readPointCloud(const std::string & path) {

    std::ifstream file(path);

    std::vector<glm::vec3> points;

    double x, y, z;
    while (file >> x >> y >> z) {
        points.emplace_back(x, y, z);
    }
    return points;
}


void callback() {

    ImGui::PushItemWidth(100);
    ImGuiIO &io = ImGui::GetIO();
    if (ImGui::Button("cool geometry process")) {


    }

}
int main(int argc, char **argv) {

    // Options
    polyscope::options::autocenterStructures = true;
    polyscope::view::windowWidth = 1024;
    polyscope::view::windowHeight = 1024;

    // Initialize polyscope
    polyscope::init();

    auto vec = readPointCloud("../data/points/bunny.xyz");
    // Register the mesh with Polyscope
    auto ps = polyscope::registerPointCloud("input ps",vec);
    ps->resetTransform();


    // Add the callback
    polyscope::state::userCallback = callback;

    // Show the gui
    polyscope::show();

    return 0;
}
