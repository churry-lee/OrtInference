#include <iostream>
#include <opencv2/opencv.hpp>

#include "utils.hpp"
#include "detector.hpp"


int main(int argc, char* argv[])
{
    const float confThreshold = 0.3f;
    const float iouThreshold = 0.4f;

	const std::string classNamesPath = PROJECT_SRC_DIR + std::string("/models/coco.names");
	const std::vector<std::string> classNames = utils::loadNames(classNamesPath);
	const std::string imagePath = PROJECT_SRC_DIR + std::string("/images/bus.jpg");
	const std::string modelPath = PROJECT_SRC_DIR + std::string("/models/yolov5s.onnx");
	bool isGPU = true;

	if (classNames.empty())
    {
        std::cerr << "Error: Empty class names file." << std::endl;
        return -1;
    }

    YOLODetector detector {nullptr};
    cv::Mat image;
    std::vector<Detection> result;

    try
    {
        detector = YOLODetector(modelPath, isGPU, cv::Size(640, 640));
        std::cout << "Model was initialized." << std::endl;

		cv::VideoCapture cap{0};
		if (!cap.isOpened())
		{
			printf("Can't open the camera");
			return -1;
		}

		cv::Mat image;

		while (1)
		{
			cap >> image;
			result = detector.detect(image, confThreshold, iouThreshold);
			utils::visualizeDetection(image, result, classNames);
			imshow("camera img", image);

			if (cv::waitKey(1) == 27)
				break;
		}

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    return 0;
}
