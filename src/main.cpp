#include "main.hpp"
#include "detector.hpp"

int main(int argc, char* argv[])
{
	const float confThreshold = 0.3f;
	const float iouThreshold = 0.4f;

	const std::string labelPath = PROJECT_SRC_DIR + std::string("/labels/coco.names");
	const std::vector<std::string> targetLabels = utils::loadLabels(labelPath);
	const std::string modelPath = PROJECT_SRC_DIR + std::string("/models/yolov5m.onnx");
	bool isGPU = false;
	cv::Size inputSize{640, 640};

	if (targetLabels.empty())
	{
		SPDLOG_ERROR("Empty labels file");
		return -1;
	}

	std::unique_ptr<YOLODetector> Detector = std::make_unique<YOLODetector>(modelPath, isGPU, inputSize);

	const std::string imagePath = PROJECT_SRC_DIR + std::string("/images/bus.jpg");
	cv::Mat image = cv::imread(imagePath);

	std::vector<Detection> result;

	try
	{
		result = Detector->detect(image, confThreshold, iouThreshold);
		utils::visualizeDetection(image, result, targetLabels);
		cv::imshow("result", image);
		cv::waitKey(0);
	}
	catch(const std::exception& e)
	{
		SPDLOG_ERROR(e.what());
		return -1;
	}


	return 0;
}