#set(SPD_INCLUDE_DIR D:/local_lib/spdlog/include)
#set(SPD_LIBRARY_DIR D:/local_lib/spdlog/lib/Debug)
#set(SPD_LIBRARY spdlogd)

#set(FMT_INCLUDE_DIR /opt/homebrew/opt/fmt/include)
#set(FMT_LIBRARY_DIR /opt/homebrew/opt/fmt/lib)
#set(FMT_LIBRARY fmt)

set(ONNXRUNTIME_INCLUDE_DIR
		D:/local_lib/onnxruntime/include
		D:/local_lib/onnxruntime/include/onnxruntime/core/session
		)
set(ONNXRUNTIME_LIBRARY_DIR D:/local_lib/onnxruntime/lib)
set(ONNXRUNTIME_LIBRARY onnxruntime)

#find_package(OpenCV REQUIRED)
set(OPENCV_INCLUDE_DIR D:/local_lib/opencv-454-win/include/opencv4)
set(OPENCV_LIBRARY_DIR D:/local_lib/opencv-454-win/lib)
#set(OPENCV_LIBRARY opencv_core opencv_highgui opencv_imgproc opencv_video opencv_videoio opencv_dnn)
set(OPENCV_LIBRARY opencv_world454d)

#set(LOCAL_INCLUDE_DIR /usr/local/include)
#set(LOCAL_LIBRARY_DIR /usr/local/lib)

# Dependency 관련 변수 설정
set(DEP_INCLUDE_DIRS
#		${LOCAL_INCLUDE_DIR}
#		${SPD_INCLUDE_DIR} ${FMT_INCLUDE_DIR}
		${ONNXRUNTIME_INCLUDE_DIR}
		${OPENCV_INCLUDE_DIR}
		)
set(DEP_LIBRARY_DIRS
#		${LOCAL_LIBRARY_DIR}
#		${SPD_LIBRARY_DIR} ${FMT_LIBRARY_DIR}
		${ONNXRUNTIME_LIBRARY_DIR}
		${OPENCV_LIBRARY_DIR}
		)
set(DEP_LIBRARIES
#		${SPD_LIBRARY} ${FMT_LIBRARY}
		${ONNXRUNTIME_LIBRARY}
		${OPENCV_LIBRARY}
		)
