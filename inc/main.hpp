#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <memory>

//#include <spdlog/spdlog.h>

// opencv libraries
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/videoio/videoio.hpp>
#include <opencv2/dnn/dnn.hpp>
#include <opencv2/core/utils/logger.hpp>

// project utils
#include "utils.hpp"

// onnxruntime inference library
//#include <onnxruntime_cxx_api.h>
#include <core/session/onnxruntime_cxx_api.h>
