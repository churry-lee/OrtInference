#include "main.hpp"
#include "detector.hpp"

int main(int argc, char* argv[])
{
	cv::utils::logging::setLogLevel(cv::utils::logging::LogLevel::LOG_LEVEL_SILENT);

	const float confThreshold = 0.3f;
	const float iouThreshold = 0.4f;

	const std::string labelPath = PROJECT_SRC_DIR + std::string("/labels/coco.names");
	const std::vector<std::string> targetLabels = utils::loadLabels(labelPath);
	const std::string modelPath = PROJECT_SRC_DIR + std::string("/models/yolov5m.onnx");
	bool isGPU = false;
	cv::Size inputSize{640, 640};

	if (targetLabels.empty())
	{
		std::cerr << "Empty labels file" << std::endl;
		return -1;
	}

	std::unique_ptr<YOLODetector> Detector = std::make_unique<YOLODetector>(modelPath, isGPU, inputSize);

	const std::string imagePath = PROJECT_SRC_DIR + std::string("/images/bus.jpg");
	cv::Mat image;
	std::vector<Detection> result;

	try
	{
#if 1
		image = cv::imread(imagePath);
		result = Detector->detect(image, confThreshold, iouThreshold);

		utils::visualizeDetection(image, result, targetLabels);
		cv::imshow("result", image);
		cv::waitKey(0);
#else
		cv::VideoCapture cap{0};
		if (!cap.isOpened())
		{
			printf("Can't open the camera");
			return -1;
		}

		while (1)
		{
			cap >> image;
			result = Detector->detect(image, confThreshold, iouThreshold);
			utils::visualizeDetection(image, result, targetLabels);
			cv::imshow("result", image);

			if (cv::waitKey(1) == 27)
				break;
		}
#endif
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return -1;
	}


	return 0;
}