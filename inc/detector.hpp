#ifndef _DETECTOR_HPP_
#define _DETECTOR_HPP_

#include "main.hpp"

class YOLODetector
{
public:
    YOLODetector(const std::string& modelPath, const bool& isGPU, const cv::Size& inputSize);
    std::vector<Detection> detect(cv::Mat &image, const float& confThreshold, const float& iouThreshold);

private:
    Ort::Env m_env{ nullptr};
    Ort::SessionOptions m_sessionOptions{ nullptr};
    Ort::Session m_session{ nullptr};

    void preprocessing(cv::Mat &image, float*& blob, std::vector<int64_t>& inputTensorShape);
    std::vector<Detection> postprocessing(const cv::Size& resizedImageShape,
                                          const cv::Size& originalImageShape,
                                          std::vector<Ort::Value>& outputTensors,
                                          const float& confThreshold, const float& iouThreshold);

    static void getBestClassInfo(std::vector<float>::iterator it, const int& numClasses,
                                 float& bestConf, int& bestClassId);


	/* 이전 버전 type */
#if defined(_WINDOWS) || defined(IMX8QM)
    std::vector<const char *> m_inputNames;
    std::vector<const char *> m_outputNames;
#else
	std::vector<std::unique_ptr<char, Ort::detail::AllocatedFree>> m_inputNames;
	std::vector<std::unique_ptr<char, Ort::detail::AllocatedFree>> m_outputNames;
#endif
	bool m_isDynamicInputShape{};
    cv::Size2f m_inputImageShape;

};

#endif // _DETECTOR_HPP_